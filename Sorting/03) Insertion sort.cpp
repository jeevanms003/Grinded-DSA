void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];   // Element to be placed
        int j = i - 1;

        // Shift elements greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key; // Place key at correct position
    }
}


🔹 Time Complexity
Best Case: 
𝑂
(
𝑛
)
O(n)
(When array is already sorted, only one comparison per element)
Average Case: 
𝑂
(
𝑛
2
)
O(n
2
)
Worst Case: 
𝑂
(
𝑛
2
)
O(n
2
)
(When array is in reverse order, maximum shifting happens)
🔹 Space Complexity
𝑂
(
1
)
O(1) (Constant space)
It is an in-place sorting algorithm (no extra memory required)
🔹 Advantages
Simple and easy to implement
Efficient for small datasets
Adaptive → Works faster if array is nearly sorted
Stable sorting algorithm (maintains order of equal elements)
Requires no extra memory
🔹 Disadvantages
Inefficient for large datasets
Takes O(n²) time in worst case
Too many shifts if elements are far from correct position
Not suitable for big real-world applications