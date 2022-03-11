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
  // Initialize the random number generator that selects the number of
  // elements (between 1 and MYARR_SIZE) in the array to be sorted
  pcg::pcg32 n_rand_gen(pcg_extras::seed_seq_from<std::random_device> {});

  // In order for Co-Simulation to pass, testbench needs to use a fixed-seed for any
  // random number generator
#ifdef D_FIXED_SEED
  constexpr auto FIXED_SEED = D_FIXED_SEED;
  n_rand_gen.seed(FIXED_SEED);
#endif

  // Randomly select the number of elements in the array to be sorted
  std::uniform_int_distribution<int> n_rand_dist {1,MYARR_SIZE};
  const auto n = n_rand_dist(n_rand_gen);

  // Initialize the random number generator that fills the array
  pcg::pcg32 myarr_rand_gen(pcg_extras::seed_seq_from<std::random_device> {});

  // In order for Co-Simulation to pass, testbench needs to use a fixed-seed for any
  // random number generator
#ifdef D_FIXED_SEED
  myarr_rand_gen.seed(FIXED_SEED);
#endif

  // Initialize and fill the array with random values
  myarr_rand_dist_t<myarr_type>::type myarr_rand_dist {std::numeric_limits<myarr_type>::min()};
  std::array<myarr_type,MYARR_SIZE> myarr;
  std::generate_n(begin(myarr),n,
      [&myarr_rand_dist,&myarr_rand_gen]{return myarr_rand_dist(myarr_rand_gen);});

  // DUT
  odd_even_sort_top(&myarr,n);
  
#ifdef D_DEBUG
  std::ofstream ofs {"Logfile"};
  copy(begin(myarr),begin(myarr)+n,std::ostream_iterator<myarr_type> {ofs, "\n"});
#endif

  if (!std::is_sorted(begin(myarr),begin(myarr)+n)) {
    std::cerr << "TEST FAILED\n";
    return -1;
  }
}
