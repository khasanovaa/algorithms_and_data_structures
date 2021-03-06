NP-COMPLETE TASKS:

1) <i>knapsack.cpp</i> <br>
    The knapsack problem: Given a set of items, each with a weight and a value, determine the number of each item to include in a collection so that the total weight is less than or equal to a given limit and the total value is as large as possible<br>
    input: the amount of things, their weight, their value, a given limit.<br>
    output: the max total value, number of things, that were used to reach max total value.<br>
    
2) <i>Vertex-cover</i><br>
    Find a K-vertex cover.
    input: the amount of vertexes, amount of edges and K, list of edges.
    output: if the K-vertex exists: YES and vertexes in vertex-cover, else: NO

FINITE AUTOMATION:
1) <i>DFA.cpp</i><br>
   input: N - amount of conditions, then N strings with condition description: (1-condition is terminal or 0-condition is not terminal), T - amount of transitions, then T descriptions off transitions (symbol, condition), then M - amount of strings to check this automat. 
   output: M+1 string: 1-the automat accepts the word, 0-the automat doesn't accepts the word.
   
2) <i>NFA.cpp</i><br>
   input: N - amount of conditions, then N strings with condition description: (1-condition is terminal or 0-condition is not terminal), E- emount of epsilon-transitions, E number of epsilon-transitions, T - amount of transitions, then T descriptions off transitions (symbol, condition), then M - amount of strings to check this automat. 
   output: M+1 string: 1-the automat accepts the word, 0-the automat doesn't accepts the word.

ALGORITHMS:

1) <i>Ford_Belman_longest_path.cpp</i> <br> 
   Finding longest path with Ford-Belman algorithm <br>
   input: amount of vertexes,  adjacency matrix <br>
   output: the length of path

2) <i>LargeFactorial.cpp </i> <br>
   Calculationg N! for N < 100000. <br>
   input: N in decimal notation <br>
   output : N!
   
3) <i>LargeSort.cpp</i> <br>
   Sorting text file lexicographical by strings. <br>
   input: text <br> and limit on memory in file memory.txt. <br>
   output: sorted text

4) <i>bridges.cpp</i> <br>
   Finding bridges in graph. <br>
   input: amount of vertexes, list of edges, <br>
   output: numbers of edges-bridges as in input<br>
   
5) <i>closest_points.cpp</i><br>
   Finding two closest points <br>
   input: amount of points, coordinates<br>
   output: distance between two closest points<br>  

6) <i>merge_sort.cpp</i><br>
   Realization of merge sort <br>
   input: size of array, array<br>
   output: sorted array<br>
  
  
7) <i>piramidal_sort.cpp</i><br>
   Realization of piramidal sort <br>
   input: size of array, array<br>
   output: sorted array<br>
  
8) <i>quick_sort.cpp</i><br>
   Realization of quick sort <br>
   input: size of array, array<br>
   output: sorted array<br>
   
 
9) <i>radix_sort.cpp</i><br>
   Realization of radix sort <br>
   input: size of array, array<br>
   output: sorted array<br>

10) <i>red-black tree.cpp</i><br>
   Realization of red-black tree structure without using set, multiset, map, multimap, unordered_set, unordered_multiset, unordered_map, unordered_multimap, etc.<br>
   input: n - amount of requests, n request : (0, v_i) = put v_i in tree or (1, v_i) = find out if v_i is in the tree<br>
   output: YES/NO for requests. Then the tree in format: KEY LEFTKEY RIGHTKEY COLOR<br>
   
11) <i>shortest_path.cpp</i><br>
   Finding the shortest path from vertex A to B <br>
   input: amount of vertexes, list of edges, A, B <br>
   output: the shortest path.
   
12) <i>stl.cpp</i><br>
   Realization of some of stl library templates<br>
 
13) <i>utf-coding.cpp</i><br>
    Coding a word with utf-8. <br>
    input: word <br>
    output: coded word
    
14) <i>utf-decoding.cpp</i><br>
    Deoding a word from utf-8. <br>
    input: coded word <br>
    output: decoded word
