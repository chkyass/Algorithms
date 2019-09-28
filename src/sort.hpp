#ifndef sort_h
#define sort_h
#include <utility>
#include <vector>
#include <cmath>


template <class E>
class sort 
{
  private:
    size_t treshold_;
    void mergeSortHelper(E*, E*, size_t, size_t);
    void quickSortHelper(E*, size_t, size_t);
    void merge(E*, E*, size_t, size_t, size_t);
    size_t partition(E*, size_t, size_t);
    size_t middleOfThree(E*, size_t, size_t, size_t);

  public:
    sort(size_t treshold = 16): treshold_(treshold){}
    E* mergeSort(E*, size_t);
    void radixSort(E*, size_t);
    void insertionSort(E*, size_t, size_t=0);
    void quickSort(E*, size_t);
    void countSort8(E*, size_t, size_t);

}; 

template <class E> void sort<E>::merge(E* array, E* copy, size_t start, size_t middle ,size_t end)
{
  // merge left and right
  size_t new_index = start;
  size_t right_index = middle + 1;
  size_t left_index = start;
  while(left_index <= middle && right_index <= end)
  {
    if(array[left_index] <= array[right_index])
    {
      copy[new_index++] = array[left_index++];
    }
    else
    {
      copy[new_index++] = array[right_index++];
    }
  }

  // select which between left and right has to be copied
  size_t remaining = (right_index > end ? left_index : right_index);

  // copy the remaining elements
  for(;new_index <= end; new_index++)
  {
    copy[new_index] = array[remaining++];
  }
}

template <class E> void sort<E>::mergeSortHelper(E* array, E* copy, size_t start, size_t end)
{
  if(end > start)
  {
    size_t middle = (start+end)/2;
    mergeSortHelper(copy, array, start, middle);
    mergeSortHelper(copy, array, middle + 1, end);
    merge(array, copy, start, middle, end);
  }
}

template <class E> E* sort<E>::mergeSort(E *array, size_t size)
{
  if(size <= treshold_)
  {
    insertionSort(array, size);
    return array;
  }
  else {
    E* copy = new E[size];
    std::copy(array, array+size, copy);
    size--;
    size_t middle = size/2;
    mergeSortHelper(copy, array, 0, middle);
    mergeSortHelper(copy, array, middle + 1, size);
    merge(array, copy, 0, middle, size);
    std::copy(copy, copy + (++size), array);
    return copy;
  }
}

template <class E> void sort<E>::insertionSort(E* array, size_t size, size_t start)
{
  for(size_t i = start + 1; i < size; i++)
  {
    for(size_t j = i; j > start; j--)
    {
      if (array[j-1] < array[j])
        break;
      std::swap(array[j-1], array[j]);
    }
  } 
}

template <class E> size_t sort<E>::middleOfThree(E* array , size_t a, size_t b, size_t c)
{
    if (array[a] > array[b])  
    { 
        if (array[b] > array[c]) 
            return b; 
        else if (array[a] > array[c]) 
            return c; 
        else
            return a; 
    }
    else 
    { 
        if (array[a] > array[c]) 
            return a; 
        else if (array[b] > array[c]) 
            return c; 
        else
            return b; 
    }
}


template <class E> size_t sort<E>::partition(E* array, size_t start, size_t end)
{
  // choose pivot as median of three
  if ((end - start + 1) > 2)
  {
    size_t middle = middleOfThree(array, start, (start+end)/2, end);
    std::swap(array[middle], array[end]);
  }

  // move all smaller than pivot to left and bigger to right
  // start at -1 in case all elements are bigger than pivot
  size_t last_lower = start - 1;
  for(size_t last_bigger = start; last_bigger < end; last_bigger++)
  {
    if(array[last_bigger] <= array[end])
    {
      last_lower++;
      std::swap(array[last_bigger], array[last_lower]);
    }
  }

  std::swap(array[++last_lower], array[end]);
  return last_lower;
}

template <class E> void sort<E>::quickSortHelper(E* array, size_t start, size_t end)
{
  if(start < end)
  {
    size_t pivot =  partition(array, start, end);
    // Avoid integer underflow
    if(pivot - 1 < pivot)
      quickSortHelper(array, start, pivot - 1);
    quickSortHelper(array, pivot + 1, end);
  }
}

template <class E> void sort<E>::quickSort(E* array, size_t size)
{
  if(size <= treshold_)
  {
    insertionSort(array, size);
  }
  else
  {
    size_t pivot = partition(array, 0, size - 1);
    quickSortHelper(array, 0, pivot - 1);
    quickSortHelper(array, pivot + 1, size - 1);
  }
}

template <class E> void sort<E>::radixSort(E* array, size_t size)
{
  // get the index of the most significant bit set in the array
  E max = *std::max_element(array, array+size);
  unsigned char highest_bit_set = log2(max);
  size_t shift;

  //count sort byte by byte until the least significant bit
  for(shift = 0; shift < (highest_bit_set + 1); shift += 8)
  {
    countSort8(array, size, shift);
  }
}

template <class E> void sort<E>::countSort8(E* array, size_t size, size_t hex_ind)
{
  std::vector<E> count_array [256];
  size_t i;
  for(i = 0; i < size; i++)
  {
    count_array[(unsigned char)(array[i] >> hex_ind) & 0xff].push_back(array[i]);
  }

  i = 0;
  for(auto& v : count_array)
  {
    for(auto& e : v)
    {
      array[i++] = e;
    }
  }
}

#endif