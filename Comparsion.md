# Algorithm & Data structure

### Segment Tree

A generic data structure.
Maximum, Minimum, Sum, GCD, Bitwise

* Preprocessing : O(nlogn)
* Query : O(logn)
* Update : O(logn)
* Online

### RMQ

Offline but the speed of query is freaking fast

* Preprocessing : O(nlogn)
* Query : O(1)
* Offline

### Binary indexed Tree(Fenwick tree)

Great choice for range sum.

* Preprocessing : O(nlogn)
* query : O(logn)
* Update : O(logn)
* Online

### Prefix Sum 

Offline but the speed of query is freaking fast

* Preprocessing : O(n)
* query : O(1)
* Offline

### Difference array

Add value x to [a,b] in O(1), freaking fast but slow on query the value
But if we combine with other data structure that will not be the case.

* Preprocessing : O(n)
* Query : O(n)
* Update n value: O(1)
* Online

### Difference array + Binary indexed tree

Range query with Range update support, Insane.
If segment tree apply lazy propagation might do the trick too, but it require nlogn space complexity.
while this only require n

* Preprocessing : O(nlogn)
* Query : O(logn)
* Update n value: O(logn)
* Online
