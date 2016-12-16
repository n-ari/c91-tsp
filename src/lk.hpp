#ifndef _LK_H
#define _LK_H

#include "tsp.hpp"

namespace TSP{
  namespace LK{
    class LKTour : public Tour{
    private:
      Int *_rev;
    public:
      Int rev(Int p){
        return _rev[p];
      }
      void flip(Int left, Int right){
        left = rev(left);
        right = rev(right);
        while(left != right){
          std::swap(path[left],path[right]);
          std::swap(rev[path[left]],rev[path[right]]);
          left++;
          if(left==n)left=0;
          if(left==right)break;
          right--;
          if(right==-1)right=n-1;
        }
      }
      LKTour(Int n):Tour(n){
        _rev = new Int[n];
      }
      LKTour(Tour &tour):Tour(tour.n){
        _rev = new Int[n];
        for(Int i=0;i<n;i++){
          path[i] = tour.path[i];
          _rev[path[i]] = i;
        }
      }
      void clear(){
        delete[] _rev;
        Tour::clear();
      }
    };
    void improve(Tour &tour){
      // prepare
      int size = std::min(n-1,10);
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
    }
  }
}

#endif
