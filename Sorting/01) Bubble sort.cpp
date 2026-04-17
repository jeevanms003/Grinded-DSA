void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Optimization: check if swap happens
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        // If no swaps → array already sorted
        if (!swapped) break;
    }
}

Bubble Sort – Time Complexity, Space, Advantages & Disadvantages
🔹 Time Complexity
Best Case: O(n) → when array is already sorted (due to early stopping using swapped flag)
Average Case: O(n²)
Worst Case: O(n²) → when array is reverse sorted
🔹 Space Complexity
O(1) (in-place sorting, no extra memory required)
🔹 Advantages
Simple and easy to implement
In-place algorithm (no extra space)
Stable sorting technique
Adaptive (efficient for nearly sorted arrays)
🔹 Disadvantages
Inefficient for large datasets (O(n²))
Performs many comparisons and swaps
Slower than efficient algorithms like Merge Sort and Quick Sort
Not suitable for real-world large-scale applications