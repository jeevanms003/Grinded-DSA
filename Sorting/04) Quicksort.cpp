int partition(int arr[], int low, int high) {
    int pivot = arr[high];   // Choose last element as pivot
    int i = low - 1;         // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]); // Place pivot in correct position
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partition index

        quickSort(arr, low, pi - 1);  // Left subarray
        quickSort(arr, pi + 1, high); // Right subarray
    }
}

🔹 Time Complexity
Best Case: 
𝑂
(
𝑛
log
⁡
𝑛
)
O(nlogn)
(Pivot divides array into equal halves)
Average Case: 
𝑂
(
𝑛
log
⁡
𝑛
)
O(nlogn)
Worst Case: 
𝑂
(
𝑛
2
)
O(n
2
)
(When pivot is smallest/largest, e.g., already sorted array)
🔹 Space Complexity
𝑂
(
log
⁡
𝑛
)
O(logn) (due to recursion stack in best/average case)
𝑂
(
𝑛
)
O(n) in worst case (skewed recursion)
🔹 Advantages
Very fast in practice compared to other 
𝑂
(
𝑛
log
⁡
𝑛
)
O(nlogn) algorithms
Uses divide and conquer approach
In-place sorting (no extra array needed)
Good cache performance
Widely used in real-world applications
🔹 Disadvantages
Worst case 
𝑂
(
𝑛
2
)
O(n
2
) performance
Not stable (does not preserve order of equal elements)
Recursive → uses stack memory
Performance depends heavily on pivot selection