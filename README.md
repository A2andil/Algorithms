# Algorithms

A reference collection of classic algorithms implemented in C++. Each file is self-contained: include the headers, compile with `g++ -std=c++17 file.cpp -o out`, and run.

Companion YouTube playlist: https://www.youtube.com/playlist?list=PLVJxzz1cOIRH-bsmJzXQxGb3HXgRTd2Jb

## Contents

- [General](#general) — number-theory and arithmetic building blocks
- [Searching](#searching) — array search and string pattern matching
- [Sorting](#sorting) — comparison and non-comparison sorts
- [Graph](#graph) — traversal, shortest paths, MST, ordering, connectivity
- [Dynamic Programming](#dynamic-programming) — classic DP problems

In the tables below, `n` is the input size, `V` and `E` are graph vertex/edge counts, `m` and `n` are string lengths for string algorithms, `W` is a knapsack capacity, and `k` is the alphabet/bucket size.

---

## General

| # | Algorithm | Time | Space | File |
|---|-----------|------|-------|------|
| 1 | GCD (Euclidean) | O(log min(a,b)) | O(1) | [GCD.cpp](General/GCD.cpp) |
| 2 | LCM | O(log min(a,b)) | O(1) | [LCM.cpp](General/LCM.cpp) |
| 3 | Iterative Factorial | O(n) | O(1) | [Iterative Factorial.cpp](General/Iterative%20Factorial.cpp) |
| 4 | Recursive Factorial | O(n) | O(n) stack | [Recursive Factorial.cpp](General/Recursive%20Factorial.cpp) |
| 5 | Fibonacci (Iterative) | O(n) | O(1) | [Fibonacci Iterative.cpp](General/Fibonacci%20Iterative.cpp) |
| 6 | Fibonacci (Recursive) | O(2^n) | O(n) stack | [Fibonacci Recursive.cpp](General/Fibonacci%20Recursive.cpp) |
| 7 | Power (naive) | O(n) | O(1) | [Power.cpp](General/Power.cpp) |
| 8 | Power (iterative fast) | O(log n) | O(1) | [Power Iterative.cpp](General/Power%20Iterative.cpp) |
| 9 | Power (recursive fast) | O(log n) | O(log n) | [Power Recursive.cpp](General/Power%20Recursive.cpp) |
| 10 | Sum of Powers | O(n log k) | O(1) | [Sum Powers.cpp](General/Sum%20Powers.cpp) |
| 11 | Factors of n | O(√n) | O(d(n)) | [Factors.cpp](General/Factors.cpp) |
| 12 | Prime Check | O(√n) | O(1) | [Prime Numbers.cpp](General/Prime%20Numbers.cpp) |
| 13 | Sieve of Eratosthenes | O(n log log n) | O(n) | [Sieve.cpp](General/Sieve.cpp) |
| 14 | Modular Exponentiation | O(log e) | O(1) | [Modular Exponentiation.cpp](General/Modular%20Exponentiation.cpp) |
| 15 | Extended Euclidean | O(log min(a,b)) | O(log min(a,b)) | [Extended Euclidean.cpp](General/Extended%20Euclidean.cpp) |
| 16 | Modular Inverse | O(log m) | O(1) | [Modular Inverse.cpp](General/Modular%20Inverse.cpp) |
| 17 | Miller-Rabin Primality | O(k log³ n) | O(1) | [Miller Rabin.cpp](General/Miller%20Rabin.cpp) |
| 18 | Segmented Sieve | O((R-L+√R) log log R) | O(R-L+√R) | [Segmented Sieve.cpp](General/Segmented%20Sieve.cpp) |

---

## Searching

| # | Algorithm | Time | Space | File |
|---|-----------|------|-------|------|
| 1 | Linear Search | O(n) | O(1) | [01- Linear Search.cpp](Searching/01-%20Linear%20Search.cpp) |
| 2 | Binary Search | O(log n) | O(1) | [02- Binary Search.cpp](Searching/02-%20Binary%20Search.cpp) |
| 3 | Modified Binary Search (first/last occurrence) | O(log n) | O(1) | [03- Modified Binary Search.cpp](Searching/03-%20Modified%20Binary%20Search.cpp) |
| 4 | KMP Pattern Matching | O(n + m) | O(m) | [04- KMP Searching Pattern.cpp](Searching/04-%20KMP%20Searching%20Pattern.cpp) |
| 5 | Rabin-Karp | O(n + m) avg, O(nm) worst | O(1) | [05- Rabin Karp Algorithm.cpp](Searching/05-%20Rabin%20Karp%20Algorithm.cpp) |
| 6 | Ternary Search | O(log₃ n) | O(1) | [06- Ternary Search.cpp](Searching/06-%20Ternary%20Search.cpp) |
| 7 | Jump Search | O(√n) | O(1) | [07- Jump Search.cpp](Searching/07-%20Jump%20Search.cpp) |
| 8 | Exponential Search | O(log n) | O(1) | [08- Exponential Search.cpp](Searching/08-%20Exponential%20Search.cpp) |
| 9 | Z-Algorithm | O(n + m) | O(n + m) | [09- Z Algorithm.cpp](Searching/09-%20Z%20Algorithm.cpp) |

**Notes.** Binary, ternary, jump, and exponential search require a sorted input. KMP and Z-algorithm both achieve linear pattern matching; Z computes a length-array useful for many string problems beyond plain matching. Rabin-Karp is the right tool when you want to match many patterns at once via rolling hash.

---

## Sorting

| # | Algorithm | Time (avg) | Time (worst) | Space | Stable | File |
|---|-----------|-----------|--------------|-------|--------|------|
| 1 | Selection Sort | O(n²) | O(n²) | O(1) | No | [01- Selection Sort.cpp](Sorting/01-%20Selection%20Sort.cpp) |
| 2 | Insertion Sort | O(n²) | O(n²) | O(1) | Yes | [02- Insertion Sort.cpp](Sorting/02-%20Insertion%20Sort.cpp) |
| 3 | Bubble Sort | O(n²) | O(n²) | O(1) | Yes | [03- Bubble Sort.cpp](Sorting/03-%20Bubble%20Sort.cpp) |
| 4 | Heap Sort | O(n log n) | O(n log n) | O(1) | No | [04- Heap Sort.cpp](Sorting/04-%20Heap%20Sort.cpp) |
| 5 | Merge Sort | O(n log n) | O(n log n) | O(n) | Yes | [05- Merge Sort.cpp](Sorting/05-%20Merge%20Sort.cpp) |
| 6 | Quick Sort | O(n log n) | O(n²) | O(log n) | No | [06- Quick Sort.cpp](Sorting/06-%20Quick%20Sort.cpp) |
| 7 | Counting Sort | O(n + k) | O(n + k) | O(n + k) | Yes | [07- Count Sort.cpp](Sorting/07-%20Count%20Sort.cpp) |
| 8 | Shell Sort | O(n log² n) | O(n²) | O(1) | No | [08- Shell Sort.cpp](Sorting/08-%20Shell%20Sort.cpp) |
| 9 | Radix Sort | O(d·(n + k)) | O(d·(n + k)) | O(n + k) | Yes | [09- Radix Sort.cpp](Sorting/09-%20Radix%20Sort.cpp) |
| 10 | Bucket Sort | O(n + k) | O(n²) | O(n + k) | Yes | [10- Bucket Sort.cpp](Sorting/10-%20Bucket%20Sort.cpp) |

**Picking a sort.** For general-purpose work use merge or quick sort. For integer keys with bounded range use counting/radix. Insertion sort is preferred for small or nearly-sorted inputs (and is the base case inside many hybrid sorts).

---

## Graph

| # | Algorithm | Time | Space | File |
|---|-----------|------|-------|------|
| 1 | Depth-First Search | O(V + E) | O(V) | [01- Depth First Search.cpp](Graph/01-%20Depth%20First%20Search.cpp) |
| 2 | Breadth-First Search | O(V + E) | O(V) | [02- Breadth First Search.cpp](Graph/02-%20Breadth%20First%20Search.cpp) |
| 3 | Dijkstra (matrix) | O(V²) | O(V²) | [03- Dijkstra Using Matrix Representation.cpp](Graph/03-%20Dijkstra%20Using%20Matrix%20Representation.cpp) |
| 4 | Dijkstra (adj list + heap) | O((V+E) log V) | O(V + E) | [04- Dijkstra Using List Representation.cpp](Graph/04-%20Dijkstra%20Using%20List%20Representation.cpp) |
| 5 | Dijkstra with path reconstruction | O((V+E) log V) | O(V + E) | [05- Printing Path in Dijkstra's Algorithm.cpp](Graph/05-%20Printing%20Path%20in%20Dijkstra%E2%80%99s%20%20Algorithm.cpp) |
| 6 | Bellman-Ford | O(V·E) | O(V) | [06- Bellman Ford Algorithm.cpp](Graph/06-%20Bellman%20Ford%20Algorithm.cpp) |
| 7 | SPFA (Bellman-Ford queue variant) | O(V·E) worst, faster avg | O(V) | [07- Shortest Path Faster Algorithm.cpp](Graph/07-%20Shortest%20Path%20Faster%20Algorithm.cpp) |
| 8 | Floyd-Warshall (all-pairs) | O(V³) | O(V²) | [08- Floyd-Warshall Algorithm.cpp](Graph/08-%20Floyd-Warshall%20Algorithm.cpp) |
| 9 | Kruskal MST | O(E log E) | O(V) | [09- Kruskal's Algorithm(MSP).cpp](Graph/09-%20Kruskal's%20Algorithm\(MSP\).cpp) |
| 10 | Prim MST | O((V+E) log V) | O(V + E) | [10- Prim's Algorithm (MSp).cpp](Graph/10-%20Prim's%20Algorithm%20\(MSp\).cpp) |
| 11 | Topological Sort | O(V + E) | O(V) | [11- Topological Sorting.cpp](Graph/11-%20Topological%20Sorting.cpp) |
| 12 | Union-Find (DSU) | O(α(n)) per op | O(n) | [12- Union Find.cpp](Graph/12-%20Union%20Find.cpp) |
| 13 | Tarjan SCC | O(V + E) | O(V) | [13- Tarjan SCC.cpp](Graph/13-%20Tarjan%20SCC.cpp) |
| 14 | Kosaraju SCC | O(V + E) | O(V) | [14- Kosaraju SCC.cpp](Graph/14-%20Kosaraju%20SCC.cpp) |
| 15 | Articulation Points & Bridges | O(V + E) | O(V) | [15- Articulation Points and Bridges.cpp](Graph/15-%20Articulation%20Points%20and%20Bridges.cpp) |
| 16 | 0-1 BFS | O(V + E) | O(V) | [16- 0-1 BFS.cpp](Graph/16-%200-1%20BFS.cpp) |

**Picking a shortest-path algorithm.**
- Non-negative weights, single source → **Dijkstra**
- Edges weighted only 0 or 1 → **0-1 BFS** (a deque-based Dijkstra)
- Negative weights, single source → **Bellman-Ford** (also detects negative cycles); SPFA is the same idea but faster in practice on sparse graphs
- All pairs, dense graph → **Floyd-Warshall**

---

## Dynamic Programming

| # | Algorithm | Time | Space | File |
|---|-----------|------|-------|------|
| 1 | Fibonacci (memoized) | O(n) | O(n) | [01- Fibonacci.cpp](Dynamic%20Programming/01-%20Fibonacci.cpp) |
| 2 | Rod Cutting | O(n²) | O(n) | [02- Rod Cutting.cpp](Dynamic%20Programming/02-%20Rod%20Cutting.cpp) |
| 3 | Maximum Subarray (Kadane) | O(n) | O(1) | [03- Maximum Subarray.cpp](Dynamic%20Programming/03-%20Maximum%20Subarray.cpp) |
| 4 | LCS — length only | O(mn) | O(mn) | [04- Longest Common Subsequence.cpp](Dynamic%20Programming/04-%20Longest%20Common%20Subsequence.cpp) |
| 5 | LCS — reconstruct sequence | O(mn) | O(mn) | [05- Longest Common Subsequence.cpp](Dynamic%20Programming/05-%20Longest%20Common%20Subsequence.cpp) |
| 6 | Minimum Edit Distance (Levenshtein) | O(mn) | O(mn) | [06- Minimum Edit Distance.cpp](Dynamic%20Programming/06-%20Minimum%20Edit%20Distance.cpp) |
| 7 | Subset Sum | O(n·S) | O(n·S) | [07- Subset Sum.cpp](Dynamic%20Programming/07-%20Subset%20Sum.cpp) |
| 8 | 0/1 Knapsack | O(nW) | O(nW) | [08- Knapsack Problem.cpp](Dynamic%20Programming/08-%20Knapsack%20Problem.cpp) |
| 9 | Longest Increasing Subsequence | O(n log n) | O(n) | [09- Longest Increasing Subsequence.cpp](Dynamic%20Programming/09-%20Longest%20Increasing%20Subsequence.cpp) |
| 10 | Matrix Chain Multiplication | O(n³) | O(n²) | [10- Matrix Chain Multiplication.cpp](Dynamic%20Programming/10-%20Matrix%20Chain%20Multiplication.cpp) |
| 11 | Maximum Path in Grid | O(rc) | O(rc) | [11- Maximum Path In Grid.cpp](Dynamic%20Programming/11-%20Maximum%20Path%20In%20Grid.cpp) |
| 12 | Coin Change — min coins | O(n·A) | O(A) | [12- Coin Change Min.cpp](Dynamic%20Programming/12-%20Coin%20Change%20Min.cpp) |
| 13 | Coin Change — count ways | O(n·A) | O(A) | [13- Coin Change Ways.cpp](Dynamic%20Programming/13-%20Coin%20Change%20Ways.cpp) |
| 14 | Egg Drop | O(n·k²) | O(n·k) | [14- Egg Drop.cpp](Dynamic%20Programming/14-%20Egg%20Drop.cpp) |
| 15 | Palindrome Partitioning (min cuts) | O(n²) | O(n²) | [15- Palindrome Partitioning.cpp](Dynamic%20Programming/15-%20Palindrome%20Partitioning.cpp) |
| 16 | Catalan Numbers | O(n²) | O(n) | [16- Catalan Numbers.cpp](Dynamic%20Programming/16-%20Catalan%20Numbers.cpp) |
| 17 | Longest Palindromic Subsequence | O(n²) | O(n²) | [17- Longest Palindromic Subsequence.cpp](Dynamic%20Programming/17-%20Longest%20Palindromic%20Subsequence.cpp) |

---

## Building & running

```bash
g++ -std=c++17 -O2 -Wall path/to/file.cpp -o out
./out
```

Each file has a `main()` with a small example demonstrating the algorithm. Modify the inputs at the top of `main()` to experiment.

## Conventions

- C++17, no external dependencies
- One algorithm per file
- File header comment states: problem, approach, complexity
- `main()` runs a small demo and prints the result

## License

This repository is intended for educational/reference use.
