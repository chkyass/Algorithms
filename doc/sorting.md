# Sorting
  
###  Implemented algorithms
  #### Merge sort
  - NlogN worst case. use N extra memory
  - split the array in 2 recursively until to have all element splited --> log(N) levels
  - copy the array to extra memory when at leaf
  - merge the array by sorting left and right part with parallel walk to extra memory --> N
  - to avoid copy back to array after each merge swich the role of array and extra at each recursion level and merge to extra each time --> at each recursion exit of left and right the data is at the same place --> by merging to extra we put the sorted data in array in wich the abave recursion level will check

  #### Quicksort
  - NlogN average. N^2 worst. No extra --> perform well with random data
  - Worst case if each time we choose the maximum as pivot --> end up with a tree of height N
  - To avoid worst case by choosing the middle of three as pivot
  - partionne start from left. i at -1 and j at 0. i point to the rightest smaller that=n pivot and j look for element smaller than pivot
  - when smaller found i incremented to point to the leftest bigger than pivot and swap a[i] and a[j] 

  #### radixsort
  - work on unsigned integers
  - (N + K)*d --> K is the size of th array in counting sort --> d the number of passe to sort everything
  - k = 2^r --> implemented with r=8 --> k=255
  - d = log2(max in array)/r
  - implementation worst casr complexity = (N+256)*4
  - sort each byte from least significant with counting sort
  - log2 return 0 based index of most significant bit
  - shift is 1 based index --> adapt the indexes



### unstable sort
#### stl::sort
  - fastest unstable sort for small arrays (under 4000 integer entris). Use insertion sort for small arrays otherwise quicksort. If the choice of pivots is bad, it's detected and fallback to heapsort.

#### boost::spreadsort::spreadsort
  - fastest mono threaded unstable sort. For small arrays fallback to std::sort. Otherwise use radix sort. Available for float !! TODO check how it work for float

#### boost::sort::Block_indirect_sort
  - parallel sort multithreaded sort. If amount of data above 100000 integer faster sort

### stable sort
  #### boost::sort::spinsort
  - fastest stable sort. Use N/2 memory. If number entries is under 100000 use it
  
  #### boost::sort::sample_sort
  - parallel stable sort. Use N memory overhead. fastest if amount of data > 100000

### Benchmark results (mac os with 4 cores) for integers
  - unstable sort benchmark
  ![unstable sort](./images/unstableSort.png?raw=true)

  - stable sort benchmark
  ![stable sort](./images/stableSort.png?raw=true)

