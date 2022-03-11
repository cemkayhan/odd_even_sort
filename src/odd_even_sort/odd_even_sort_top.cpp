#include "odd_even_sort_top.h"
#include "odd_even_sort.hpp"

void odd_even_sort_top(std::array<myarr_type,MYARR_SIZE>* myarr, int n)
{
#ifdef D_MYARR_M_AXI_INTERFACE
#pragma HLS INTERFACE mode=m_axi port=myarr
#else
#pragma HLS DISAGGREGATE variable=myarr
#endif

  odd_even_sort<myarr_type,MYARR_SIZE>(*myarr,n);
}
