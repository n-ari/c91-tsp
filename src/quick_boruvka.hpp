#ifndef _QUICK_BORUVKA_H
#define _QUICK_BORUVKA_H

#include "tsp.hpp"

namespace TSP{
  namespace QuickBoruvka{
    Tour calc(){
      UnionFind uf(n);
      int *deg = new int[n];
      std::vector<Int> *graph = new std::vector<Int>[n];
      for(Int i=0;i<n;i++){
        deg[i] = 0;
      }
      for(int t=0;t<2;t++){
        for(Int i=0;i<n;i++){
          if(deg[i]==2)continue;
          Int nxt = -1;
          for(Int j=0;j<n;j++){
            if(deg[j]==2)continue;
            if(i==j)continue;
            if(uf.same(i,j))continue;
            if(nxt==-1){
              nxt = j;
            }else{
              if(getlength2(i,nxt) > getlength2(i,j)){
                nxt = j;
              }
            }
          }
          if(nxt==-1)continue;
          uf.unite(i,nxt);
          deg[i]++;
          deg[nxt]++;
          graph[i].push_back(nxt);
          graph[nxt].push_back(i);
        }
      }
      int a=-1, b=-1;
      for(Int i=0;i<n;i++){
        if(deg[i]==1){
          if(a==-1)a=i;
          else b=i;
        }
      }
      graph[a].push_back(b);
      graph[b].push_back(a);

      Tour ans(n);
      bool *used = new bool[n];
      for(Int i=0;i<n;i++){
        used[i] = false;
      }
      int cur = 0;
      used[cur] = true;
      ans.path[0] = cur;
      for(Int i=1;i<n;i++){
        int nxt = graph[cur][0];
        if(used[nxt]){
          nxt = graph[cur][1];
        }
        used[nxt] = true;
        ans.path[i] = nxt;
        cur = nxt;
      }
      delete[] deg;
      delete[] graph;
      delete[] used;
      return ans;
    }
  }
}

#endif