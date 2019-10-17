# Graphs

## Implementation of graph without label on edges
 - Adgecency list --> hastable of sets --> amortized O(1) to access neighboors --> use set to for neighboors to automatically collide neighbours

## Deque
- vector good for random access and iteration and add at end
- deque also good to add in front
- basically list of blocks
- random access done by shifting by block size
- a bit slower than vector for random access and iteration

## Breath First Seatch 
 - Go through level by level in the graph
 - maintain a set of already seen nodes for cycles. Set O(1) access and lookup
 - from entry add level by level of next nodes --> Necessity to maintain order to iterate level by level --> Use dequeue 0(1) for front deletion and back insertion --> adapted for our case

## Depth First Search
- 