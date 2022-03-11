#ifndef ODD_EVEN_SORT_HPP_INCLUDED
#define ODD_EVEN_SORT_HPP_INCLUDED

#include <algorithm>
#include <array>

// algorithm credit goes here;
// https://www.geeksforgeeks.org/odd-even-sort-brick-sort/
template<typename T, int N>
inline void odd_even_sort(std::array<T, N>& arr, int n)
{
#pragma HLS INLINE

  bool is_sorted = false; // Initially array is unsorted

while_not_sorted:while (!is_sorted)
  {
#pragma HLS LOOP_TRIPCOUNT min=N max=N
    is_sorted = true;

    // Perform Bubble sort on odd indexed element
for_odd:for (auto i=1; i<=n-2; i=i+2)
    {
#pragma HLS LOOP_TRIPCOUNT min=N/2 max=N/2
      if (arr[i] > arr[i+1])
      {
        std::swap(arr[i], arr[i+1]);
        is_sorted = false;
      }
    }

    // Perform Bubble sort on even indexed element
for_even:for (auto i=0; i<=n-2; i=i+2)
    {
#pragma HLS LOOP_TRIPCOUNT min=N/2 max=N/2
      if (arr[i] > arr[i+1])
      {
        std::swap(arr[i], arr[i+1]);
        is_sorted = false;
      }
    }
  }
}

#endif
