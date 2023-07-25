# sorting_algorithms
Sorting algorithms written in C language using data structures

## Time complexity of algorithms
| Sorting algorithm | Time complexity | Space complexity |
|---|---|---|
| Bubble sort |||
| Insertion sort |||
| Selection sort |||
| Quick sort | The worst-case time complexity of the Quick Sort algorithm is O(n^2), which occurs when the pivot element is either the smallest or largest element in the array, and the partition function divides the array into two sub-arrays of size 1 and n-1 respectively. In this case, the algorithm will make n recursive calls, each of which processes only one element less than the previous call, resulting in a total of n*(n-1)/2 comparisons. However, the average-case time complexity of Quick Sort is O(nlogn), which is much faster than the worst-case time complexity. The best-case time complexity of Quick Sort is also O(nlogn), which occurs when the pivot element is the median of the array, and the partition function divides the array into two sub-arrays of roughly equal size. In this case, the algorithm will make logn recursive calls, each of which processes half of the elements of the previous call, resulting in a total of nlogn comparisons. ||
| Shell sort |||
