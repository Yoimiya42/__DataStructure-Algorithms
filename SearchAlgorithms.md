
# SearchAlgorithms

## Category 1: Brute-force Search
Brute-force search locates the target element by traversing the overall data structure.  

- ***Linear Search*** is suitable for linear structure such as array, linked list.  
- 
Two traversal strategies for non-linear structure such as tree, graph:  

- ***Breadth First Search（BFS）*** is implemented by **queue**. From the near to the far, it traverses the nodes layer by layer.
- ***Depth First Search (DFS)*** is implemented by **stack**. It follows a path until it reaches the end, then backtracks to the previous node and tries other paths.


## Category 2: Adaptive Search

- ***Binary Search*** uses the orderliness of data to achieve efficient search, only suitable for ordered array.
- ***Hash Search*** uses hash table to establish the mapping between key and value via hash function. 
- ***Tree Search***
