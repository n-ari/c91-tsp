#include <iostream>
#include "util.hpp"
#include "tsp.hpp"
#include "nearest_neighbor.hpp"
#include "nearest_insertion.hpp"
#include "farthest_insertion.hpp"
#include "double_mst.hpp"
#include "greedy.hpp"
#include "quick_boruvka.hpp"

#include "two_opt.hpp"

// main routine
int main(int argc, char **argv){
  if(argc<2){
    std::cerr << "Error: need input filename." << std::endl;
    return 1;
  }

  // input
  {
    std::string s(argv[1]);
    s = "in/" + s + ".in";
    TSP::input(s);
  }

  // nearest neighbor
  {
    Util::resettime();
    Util::timestamp("Nearest Neighbor");
    TSP::Tour tour_nn = TSP::NearestNeighbor::calc();
    Util::timestamp("End");
    std::string s(argv[1]);
    s = "out/" + s + "_nn.out";
    TSP::output(tour_nn,s);
    tour_nn.clear();
  }

  // nearest insertion
  {
    Util::resettime();
    Util::timestamp("Nearest Insertion");
    TSP::Tour tour_ni = TSP::NearestInsertion::calc();
    Util::timestamp("End");
    std::string s(argv[1]);
    s = "out/" + s + "_ni.out";
    TSP::output(tour_ni,s);
    tour_ni.clear();
  }

  // farthest insertion
  {
    Util::resettime();
    Util::timestamp("Farthest Insertion");
    TSP::Tour tour_fi = TSP::FarthestInsertion::calc();
    Util::timestamp("End");
    std::string s(argv[1]);
    s = "out/" + s + "_fi.out";
    TSP::output(tour_fi,s);
    tour_fi.clear();
  }

  // double mst
  {
    Util::resettime();
    Util::timestamp("Double Minimum Spanning Tree");
    TSP::Tour tour_dmst = TSP::DoubleMST::calc();
    Util::timestamp("End");
    std::string s(argv[1]);
    s = "out/" + s + "_dmst.out";
    TSP::output(tour_dmst,s);
    tour_dmst.clear();
  }

  // greedy
  {
    Util::resettime();
    Util::timestamp("Greedy");
    TSP::Tour tour_gr = TSP::Greedy::calc();
    Util::timestamp("End");
    std::string s(argv[1]);
    s = "out/" + s + "_gr.out";
    TSP::output(tour_gr,s);
    tour_gr.clear();
  }

  // quick boruvka
  {
    Util::resettime();
    Util::timestamp("Quick Boruvka");
    TSP::Tour tour_qb = TSP::QuickBoruvka::calc();
    Util::timestamp("End");
    std::string s(argv[1]);
    s = "out/" + s + "_qb.out";
    TSP::output(tour_qb,s);
    tour_qb.clear();
  }

  // nearest neighbor & 2-opt
  {
    Util::resettime();
    Util::timestamp("Nearest Neighbor & 2-opt");
    TSP::Tour tour_nn_2opt = TSP::NearestNeighbor::calc();
    Util::timestamp("End(NN)");
    TSP::TwoOpt::improve(tour_nn_2opt);
    Util::timestamp("End(2-opt)");
    std::string s(argv[1]);
    s = "out/" + s + "_nn_2opt.out";
    TSP::output(tour_nn_2opt,s);
    tour_nn_2opt.clear();
  }

  // nearest insertion & 2-opt
  {
    Util::resettime();
    Util::timestamp("Nearest Insertion & 2-opt");
    TSP::Tour tour_ni_2opt = TSP::NearestInsertion::calc();
    Util::timestamp("End(NI)");
    TSP::TwoOpt::improve(tour_ni_2opt);
    Util::timestamp("End(2-opt)");
    std::string s(argv[1]);
    s = "out/" + s + "_ni_2opt.out";
    TSP::output(tour_ni_2opt,s);
    tour_ni_2opt.clear();
  }

  // farthest insertion & 2-opt
  {
    Util::resettime();
    Util::timestamp("Farthest Insertion & 2-opt");
    TSP::Tour tour_fi_2opt = TSP::FarthestInsertion::calc();
    Util::timestamp("End(FI)");
    TSP::TwoOpt::improve(tour_fi_2opt);
    Util::timestamp("End(2-opt)");
    std::string s(argv[1]);
    s = "out/" + s + "_fi_2opt.out";
    TSP::output(tour_fi_2opt,s);
    tour_fi_2opt.clear();
  }

  // double mst & 2-opt
  {
    Util::resettime();
    Util::timestamp("Double Minimum Spanning Tree & 2-opt");
    TSP::Tour tour_dmst_2opt = TSP::DoubleMST::calc();
    Util::timestamp("End(DMST)");
    TSP::TwoOpt::improve(tour_dmst_2opt);
    Util::timestamp("End(2-opt)");
    std::string s(argv[1]);
    s = "out/" + s + "_dmst_2opt.out";
    TSP::output(tour_dmst_2opt,s);
    tour_dmst_2opt.clear();
  }

  // greedy & 2-opt
  {
    Util::resettime();
    Util::timestamp("Greedy & 2-opt");
    TSP::Tour tour_gr_2opt = TSP::Greedy::calc();
    Util::timestamp("End(GR)");
    TSP::TwoOpt::improve(tour_gr_2opt);
    Util::timestamp("End(2-opt)");
    std::string s(argv[1]);
    s = "out/" + s + "_gr_2opt.out";
    TSP::output(tour_gr_2opt,s);
    tour_gr_2opt.clear();
  }

  // quick boruvka & 2-opt
  {
    Util::resettime();
    Util::timestamp("Quick Boruvka & 2-opt");
    TSP::Tour tour_qb_2opt = TSP::QuickBoruvka::calc();
    Util::timestamp("End(QB)");
    TSP::TwoOpt::improve(tour_qb_2opt);
    Util::timestamp("End(2-opt)");
    std::string s(argv[1]);
    s = "out/" + s + "_qb_2opt.out";
    TSP::output(tour_qb_2opt,s);
    tour_qb_2opt.clear();
  }

  TSP::halt();

  return 0;
}
