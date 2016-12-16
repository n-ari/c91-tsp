#ifndef _TSP_HPP
#define _TSP_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "util.hpp"

namespace TSP{
  typedef short Int;
  typedef float Real;

  Int n;
  Real *xs, *ys;

  class Tour{
  public:
    Int n, *path;
    Tour(Int n):n(n){
      path = new Int[n];
    }
    Tour(Int n,Int *p):n(n){
      path = new Int[n];
      for(Int i=0;i<n;i++){
        path[i] = p[i];
      }
    }
    void clear(){
      delete[] path;
    }
  };

  // length between 2 points
  inline Real getlength(Int i,Int j){
    Real dx = xs[i]-xs[j];
    Real dy = ys[i]-ys[j];
    return sqrt(dx*dx + dy*dy);
  }

  // square power of length between 2 points
  inline Real getlength2(Int i,Int j){
    Real dx = xs[i]-xs[j];
    Real dy = ys[i]-ys[j];
    return dx*dx + dy*dy;
  }

  // length of Tour
  inline Real calclen(Tour &t){
    Real ret = 0.0;
    for(Int i=0;i<t.n;i++){
      ret += getlength(t.path[i], i<t.n-1 ? t.path[i+1] : t.path[0]);
    }
    return ret;
  }

  // input and output
  void input(char* in){
    std::ifstream fs(in);
    fs >> n;
    xs = new Real[n];
    ys = new Real[n];
    for(Int i=0;i<n;i++){
      fs >> xs[i] >> ys[i];
    }
    fs.close();
  }
  void input(std::string in){
    std::ifstream fs(in);
    fs >> n;
    xs = new Real[n];
    ys = new Real[n];
    for(Int i=0;i<n;i++){
      fs >> xs[i] >> ys[i];
    }
    fs.close();
  }
  void output(Tour &ans, char* out){
    std::ofstream fs(out);
    fs << calclen(ans) << std::endl;
    for(Int i=0;i<n;i++){
      fs << ans.path[i] << " ";
    }
    fs << std::endl;
    fs.close();
  }
  void output(Tour &ans, std::string out){
    std::ofstream fs(out);
    fs << calclen(ans) << std::endl;
    for(Int i=0;i<n;i++){
      fs << ans.path[i] << " ";
    }
    fs << std::endl;
    fs.close();
  }
  void halt(){
    delete[] xs;
    delete[] ys;
  }

  // structures
  struct UnionFind{
    Int *data;
    UnionFind(Int n){
      data = new Int[n];
      for(Int i=0;i<n;i++){
        data[i] = -1;
      }
    }
    ~UnionFind(){
      delete[] data;
    }
    Int root(Int x){
      return data[x]<0 ? x : data[x]=root(data[x]);
    }
    void unite(Int a,Int b){
      a = root(a);
      b = root(b);
      if(a != b){
        if(data[a] > data[b])std::swap(a,b);
        data[a] += data[b];
        data[b] = a;
      }
    }
    inline bool same(Int a,Int b){
      return root(a)==root(b);
    }
  };
}

#endif
