#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <vector>
#include <algorithm>

template <typename E, typename C>
E medianOfThree(std::vector<E>& S, int a, int b, const C& less);

// Quick-sort functions for a vector
template <typename E, typename C>
void quickSortStep(std::vector<E>& S, int a, int b, const C& less, int& comparisons, int& moves) {
    if (a >= b) return; // 0 or 1 left? done
    E pivot = medianOfThree(S, a, b, less); // Choose median of three as pivot
    int l = a; // left edge
    int r = b - 1; // right edge
    while (l <= r) {
        while (l <= r && !less(pivot, S[l])) {
            l++;
            comparisons++; // Increment comparison count
        }
        while (r >= l && !less(S[r], pivot)) {
            r--;
            comparisons++; // Increment comparison count
        }
        if (l < r) { // both elements found
            std::swap(S[l], S[r]);
            moves++; // Increment move count
        }
    } // until indices cross
    std::swap(S[l], S[b]); // store pivot at l
    moves++; // Increment move count
    quickSortStep(S, a, l - 1, less, comparisons, moves); // recur on both sides
    quickSortStep(S, l + 1, b, less, comparisons, moves);
}

template <typename E, typename C>
E medianOfThree(std::vector<E>& S, int a, int b, const C& less) {
    int mid = (a + b) / 2;
    if (less(S[mid], S[a]))
        std::swap(S[mid], S[a]);
    if (less(S[b], S[a]))
        std::swap(S[b], S[a]);
    if (less(S[mid], S[b]))
        std::swap(S[mid], S[b]);
    return S[b];
}

#endif // QUICK_SORT_H
