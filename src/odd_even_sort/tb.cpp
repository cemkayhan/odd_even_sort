#include "tb.hpp"
#include "config.h"
#include "pcg.hpp"
#include "ap_int.h"
#include "odd_even_sort_top.h"

#include <algorithm>
#include <iterator>
#include <iostream>
#include <random>
#include <array>
#include <fstream>

int main()
{
  // Randomly select the number of elements (between 1 and myarr_size)
  // in the array to be sorted
  pcg::pcg32 n_rand_gen(pcg_extras::seed_seq_from<std::random_device> {});
  std::uniform_int_distribution<int> n_rand_dist {1,myarr_size};
  const auto n = n_rand_dist(n_rand_gen);

  // Initialize the random number generator that fills the array
  pcg::pcg32 myarr_rand_gen(pcg_extras::seed_seq_from<std::random_device> {});
  myarr_rand_dist_t<myarr_type>::type myarr_rand_dist;

  // Fill the array with random values
  std::array<myarr_type,myarr_size> myarr;
  std::generate_n(begin(myarr),n,
      [&myarr_rand_dist,&myarr_rand_gen]{return myarr_rand_dist(myarr_rand_gen);});

  // DUT
  odd_even_sort_top(&myarr,n);
  
  if (!std::is_sorted(begin(myarr),begin(myarr)+n)) {
    std::cerr << "TEST FAILED\n";
    return -1;
  }

#ifdef D_DEBUG
  std::ofstream ofs {"Logfile"};
  copy(begin(myarr),begin(myarr)+n,std::ostream_iterator<myarr_type> {ofs, "\n"});
#endif
}
