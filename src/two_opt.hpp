#ifndef _TWO_OPT_H
#define _TWO_OPT_H

#include "tsp.hpp"

namespace TSP{
  namespace TwoOpt{
    void improve(Tour &tour){
      // prepare
      int size = std::min(n-1,1000);
      Int **nearest = new Int*[n];
      Int *tmp = new Int[n];
      for(Int i=0;i<n;i++){
        tmp[i] = i;
      }
      for(Int i=0;i<n;i++){
        nearest[i] = new Int[size];
        std::sort(tmp,tmp+n,[&](int a,int b){
          return getlength2(i,a) < getlength2(i,b);
        });
        for(Int j=0;j<size;j++){
          nearest[i][j] = tmp[j+1];
        }
      }
      delete[] tmp;
      // improve
      Int count = n;
      Int pos = 0;
      Int *path = tour.path;
      Int *rev = new Int[n];
      for(Int i=0;i<n;i++){
        rev[path[i]] = i;
      }
      while(count-- > 0){
        Int a = path[pos];
        Int b = path[pos<n-1 ? pos+1 : pos+1-n];
        Int bd = path[pos<n-2 ? pos+2 : pos+2-n];
        Real score = getlength(a,b);
        for(Int i=0;i<size;i++){
          Int c = nearest[b][i];
          if(c==a || c==b || c==bd)continue;
          Real score2 = score - getlength(b,c);
          if(score2 <= 0.0)break;
          Int pc = rev[c];
          Int d = path[pc>0 ? pc-1 : pc-1+n];
          Real score3 = score2 + getlength(c,d) - getlength(d,a);
          if(score3 > 0.0){
            // do improvement
            Int left = pos<n-1 ? pos+1 : pos+1-n;
            Int right = pc>0 ? pc-1 : pc-1+n;
            while(left != right){
              std::swap(path[left], path[right]);
              std::swap(rev[path[left]], rev[path[right]]);
              left++;
              if(left==n)left=0;
              if(left==right)break;
              right--;
              if(right==-1)right=n-1;
            }
            count = n+5;
            break;
          }
        }
        pos++;
        if(pos==n)pos=0;
      }
      for(Int i=0;i<n;i++){
        delete[] nearest[i];
      }
      delete[] nearest;
      delete[] rev;
    }
  }
}

#endif