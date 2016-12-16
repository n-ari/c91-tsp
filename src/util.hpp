#ifndef _UTIL_HPP
#define _UTIL_HPP

#include <iostream>
#include <random>
#include <chrono>

// utilities
namespace Util{
  using namespace std::chrono;
  uint64_t begintime = (uint64_t)duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

  uint32_t getrandint(){
    static std::random_device seed_gen;
    static std::mt19937 engine(seed_gen());
    return engine();
  }
  double getrand(){
    return (double)(getrandint())/4294967296.0;
  }
  void resettime(){
    begintime = (uint64_t)duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
  }
  uint64_t gettime(){
    return (uint64_t)duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() - begintime;
  }
  void timestamp(std::string mes){
    std::cerr << "[" << gettime() << "] " << mes << std::endl;
  }
}

#endif
