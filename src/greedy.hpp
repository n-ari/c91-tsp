#ifndef _GREEDY_H
#define _GREEDY_H

#include "tsp.hpp"

namespace TSP{
  namespace Greedy{
    Tour calc(){
      // sort all edge
      Int **to = new Int*[n];
      Int *head = new Int[n];
      Int *deg = new Int[n];
      for(Int i=0;i<n;i++){
        to[i] = new Int[n];
        for(Int j=0;j<n;j++){
          to[i][j] = j;
        }
        std::sort(to[i],to[i]+n,[&](Int &a,Int &b){
          return getlength2(i,a) < getlength2(i,b);
        });
        head[i] = 0;
        deg[i] = 0;
      }

      UnionFind uf(n);
      std::vector<Int> *graph = new std::vector<Int>[n];
      for(Int time=0;time<n-1;time++){
        Int mins = -1, mint = -1;
        for(Int x=0;x<n;x++){
          if(deg[x]==2)continue;
          Int y = 0;
          head[x]--;
          do{
            head[x]++;
            y = to[x][head[x]];
          }while(uf.same(x,y) || deg[y]==2);
          if(mins == -1){
            mins = x;
            mint = y;
          }else{
            if(getlength2(mins,mint) > getlength2(x,y)){
              mins = x;
              mint = y;
            }
          }
        }
        head[mins]++;
        head[mint]++;
        uf.unite(mins,mint);
        deg[mins]++;
        deg[mint]++;
        graph[mins].push_back(mint);
        graph[mint].push_back(mins);
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
      for(Int i=0;i<n;i++){
        delete[] to[i];
      }
      delete[] to;
      delete[] head;
      delete[] deg;
      delete[] graph;
      delete[] used;
      return ans;
    }
  }
}

#endif