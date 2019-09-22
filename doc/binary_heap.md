# Binary_heap (priority queue)

### Implementation
  - internally vector. Viewed as binary tree 2i is left child and 2i+1 is right child 
  - build the heap take N. Heap when all nodes are greter(smaller) than their childs --> root is max 

#### Build --> N
 - From the penultimate (N/2 because last level contain half of nodes) level heapify.
 - heapify: if invariant respected stop else move nodes to make the bigger root and recursively call heapify on the moved down one

 #### Pop() --> Log N
 - exchange root and last node. first and last index of the tree. heapify the root

 ### insert() --> Log N
 - add element at end
 - call heapify on node parents until invariant is respected

TODO lock free queue