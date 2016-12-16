#ifndef _DOUBLE_MST_H
#define _DOUBLE_MST_H

#include "tsp.hpp"

namespace TSP{
  namespace DoubleMST{
    void dfs(Int p,Tour &ans,Int &it,bool *used,std::vector<Int> *graph){
      used[p] = true;
      ans.path[it++] = p;
      for(auto to:graph[p]){
        if(used[to])continue;
        dfs(to,ans,it,used,graph);
      }
    }
    Tour calc(){
      // sort all edge
      typedef std::pair<Int,Int> pair;
      int cnt = std::min(n-1,100);
      int all = (int)n*cnt;
      pair *es = new pair[all];
      for(Int i=0;i<n;i++){
        pair *es2 = new pair[n-1];
        int it = 0;
        for(Int j=0;j<n;j++)if(i!=j){
          es2[it++] = pair(i,j);
        }
        std::partial_sort(es2,es2+cnt,es2+(int)n-1,[&](pair &s,pair &t){
          return getlength2(s.first, s.second) < getlength2(t.first, t.second);
        });
        for(int j=0;j<cnt;j++){
          es[(int)i*cnt+j] = es2[j];
        }
        delete[] es2;
      }
      std::sort(es,es+all,[&](pair &s,pair &t){
        return getlength2(s.first, s.second) < getlength2(t.first, t.second);
      });

      UnionFind uf(n);
      std::vector<Int> *graph = new std::vector<Int>[n];
      int count = 0;
      for(int id=0;id<all;id++){
        pair p = es[id];
        Int s = p.first;
        Int t = p.second;
        if(uf.same(s,t))continue;
        uf.unite(s,t);
        count++;
        graph[s].push_back(t);
        graph[t].push_back(s);
        if(count==n-1)break;
      }

      Tour ans(n);
      Int it = 0;
      bool *used = new bool[n];
      for(Int i=0;i<n;i++){
        used[i] = false;
      }
      dfs(0,ans,it,used,graph);

      delete[] es;
      delete[] graph;
      delete[] used;
      return ans;
    }
  }
}

#endif