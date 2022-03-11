#include "odd_even_sort.hpp"

constexpr auto N = 100;
using myarr_t = int;

void synth_tb(std::array<myarr_t,N>* myarr, int n,
    volatile myarr_t* myarr_out)
{
#pragma HLS INTERFACE mode=m_axi port=myarr offset=off

fill_unsorted:for (auto i=0; i<N; ++i)
    (*myarr)[i] = N-i-1;

  odd_even_sort<myarr_t,N>(*myarr,n);

read_sorted:for (auto i=0; i<n; ++i)
#pragma HLS LOOP_TRIPCOUNT min=N max=N
    *myarr_out = (*myarr)[i];
}
