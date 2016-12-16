#ifndef _FARTHEST_INSERTION_H
#define _FARTHEST_INSERTION_H

#include "tsp.hpp"

namespace TSP{
  namespace FarthestInsertion{
    inline void chmin(Real &v, Real x){
      if(v>x)v=x;
    }
    struct list{
      Int val;
      list *bef,*aft;
      list(){
        val = 0;
        bef = aft = NULL;
      }
    };
    Tour calc(){
      bool *used = new bool[n];
      Real *nearest_distance = new Real[n];
      list *items = new list[n];
      for(Int i=0;i<n;i++){
        used[i] = false;
        nearest_distance[i] = 1.0e18;
        items[i].val = i;
      }
      // begin from 0
      list *head = &items[0];
      head->bef = head;
      head->aft = head;
      used[0] = true;
      for(Int i=0;i<n;i++){
        if(used[i])continue;
        chmin(nearest_distance[i], getlength(0,i));
      }
      for(Int i=1;i<n;i++){
        Int minid = -1;
        for(Int j=0;j<n;j++){
          if(used[j])continue;
          if(minid == -1){
            minid = j;
          }else{
            if(nearest_distance[minid] < nearest_distance[j]){
              minid = j;
            }
          }
        }
        used[minid] = true;
        for(Int j=0;j<n;j++){
          if(used[j])continue;
          chmin(nearest_distance[j], getlength(minid,j));
        }
        list *cur = head;
        list *insert_point = head;
        Real minscore = 1.0e18;
        while(true){
          list *aft = cur->aft;
          Real score = getlength(cur->val, minid) + getlength(aft->val, minid) - getlength(cur->val, aft->val);
          if(score < minscore){
            insert_point = cur;
            minscore = score;
          }
          cur = aft;
          if(cur == head)break;
        }
        list *aft = insert_point->aft;
        insert_point->aft = &items[minid];
        items[minid].bef = insert_point;
        items[minid].aft = aft;
        aft->bef = &items[minid];
      }
      Tour ans(n);
      for(Int i=0;i<n;i++){
        ans.path[i] = head->val;
        head = head->aft;
      }
      delete[] used;
      delete[] nearest_distance;
      delete[] items;
      return ans;
    }
  }
}

#endif
