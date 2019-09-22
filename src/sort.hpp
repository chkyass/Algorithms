#ifndef sort_h
#define sort_h

template <class E>
class sort 
{
  private:
    size_t treshold_;
    void mergeSortHelper(E*, E*, size_t, size_t);
    void merge(E*, E*, size_t, size_t, size_t);

  public:
    sort(size_t treshold = 16): treshold_(treshold){}
    E* mergeSort(E*, size_t size);
    void raddixSort(E*);
    void insertionSort(E*, size_t, size_t=0);
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
  if(start >= end)
  {
    copy[start] = array[start];
  }
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
    size--;
    size_t middle = size/2;
    mergeSortHelper(copy, array, 0, middle);
    mergeSortHelper(copy, array, middle + 1, size);
    merge(array, copy, 0, middle, size);
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

#endif