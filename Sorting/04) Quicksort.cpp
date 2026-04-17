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