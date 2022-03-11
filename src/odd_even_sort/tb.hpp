#ifndef TB_HPP_INCLUDED
#define TB_HPP_INCLUDED

#include "ap_int.h"

#include <random>

template<typename T>
struct myarr_rand_dist_t;

template<>
struct myarr_rand_dist_t<int> {
  using type = std::uniform_int_distribution<int>;
};

template<>
struct myarr_rand_dist_t<short> {
  using type = std::uniform_int_distribution<short>;
};

template<>
struct myarr_rand_dist_t<double> {
  using type = std::uniform_real_distribution<double>;
};

template<>
struct myarr_rand_dist_t<float> {
  using type = std::uniform_real_distribution<float>;
};

template<int n>
struct myarr_rand_dist_t<ap_int<n>> {
  using type = std::uniform_int_distribution<int>;
};

template<int n>
struct myarr_rand_dist_t<ap_uint<n>> {
  using type = std::uniform_int_distribution<int>;
};

#endif
