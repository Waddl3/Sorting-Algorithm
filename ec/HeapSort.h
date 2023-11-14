#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <vector>
#include <algorithm>

template <typename T>
void heapify(std::vector<T>& arr, int n, int i, int& comparisons, int& moves) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n) {
        comparisons++; // Increment comparison count
        if (arr[left] > arr[largest])
            largest = left;
    }

    if (right < n) {
        comparisons++; // Increment comparison count
        if (arr[right] > arr[largest])
            largest = right;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        moves += 3; // Increment move count for swapping
        heapify(arr, n, largest, comparisons, moves);
    }
}

template <typename T>
void heapSort(std::vector<T>& arr, int& comparisons, int& moves) {
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, comparisons, moves);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        moves += 3; // Increment move count for swapping
        heapify(arr, i, 0, comparisons, moves);
    }
}

#endif // HEAPSORT_H
