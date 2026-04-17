void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // Find index of minimum element
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap with current position
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

Selection Sort – Time, Space, Advantages & Disadvantages
🔹 Time Complexity
Best Case: O(n²)
Average Case: O(n²)
Worst Case: O(n²)
👉 Always performs same number of comparisons regardless of input
🔹 Space Complexity
O(1) (in-place sorting, no extra memory required)
🔹 Advantages
Simple and easy to understand
In-place algorithm (no extra space required)
Performs minimum number of swaps (at most n−1)
Useful when memory writes are costly
🔹 Disadvantages
Inefficient for large datasets (O(n²))
Not adaptive (does not improve for sorted input)
Not stable (may change order of equal elements)
Slower compared to efficient algorithms like Merge Sort and Quick Sort