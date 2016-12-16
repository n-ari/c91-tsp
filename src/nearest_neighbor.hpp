#ifndef _NEAREST_NEIGHBOR_H
#define _NEAREST_NEIGHBOR_H

#include "tsp.hpp"

namespace TSP{
  namespace NearestNeighbor{
    Tour calc(){
      Tour ans(n);
      bool *used = new bool[n];
      for(Int i=0;i<n;i++){
        used[i] = false;
      }
      Int cur = 0;
      used[cur] = true;
      ans.path[0] = cur;
      for(Int i=1;i<n;i++){
        Int nxt = -1;
        for(Int j=0;j<n;j++){
          if(used[j])continue;
          if(nxt == -1){
            nxt = j;
          }else{
            if(getlength(cur,nxt) > getlength(cur,j)){
              nxt = j;
            }
          }
        }
        used[nxt] = true;
        ans.path[i] = nxt;
        cur = nxt;
      }
      delete[] used;
      return ans;
    }
  }
}

#endif
