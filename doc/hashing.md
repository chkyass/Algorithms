# Hashing with chaining

## Hash function
  - h(k) = k mod M
  - avoid the fact that M and the population k share a common factor --> will be hashed to a value that is a multiple of the common factor --> use prime number

## Extend
  - each time n = m we double m. So we extend the internal table O(n+m+m'), log2(n) time for n insertion and cost of insertion is 1+a(=chain length) the rest of the time --> amortized complexity is O(1)

## shrink
  - when number of elements is n/4 divide m by 2.
  - Don't use n/2 to avoid case wher n=m/2(shrink) <--> n=m/2+1(extend). In these case each insert has n+m+m' cost
  
  
