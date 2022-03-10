#include "odd_even_sort_top.h"
#include "odd_even_sort.hpp"

void odd_even_sort_top(std::array<myarr_type,myarr_size>* myarr, int n)
{
#pragma HLS INTERFACE mode=m_axi port=myarr

  odd_even_sort<myarr_type,myarr_size>(*myarr,n);
}
