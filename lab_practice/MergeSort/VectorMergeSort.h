#ifndef VECTOR_MERGE_SORT_H
#define VECTOR_MERGE_SORT_H

#include <iostream>
#include <vector>

template<typename E, typename C>
void merge(std::vector<E>& S1, std::vector<E>& S2, std::vector<E>& S, const C& isLess);

template<typename E, typename C>
void mergeSort(std::vector<E>& S, const C& less) {
    typedef typename std::vector<E>::iterator Itor;

    //  base case:  If size of arr/vect is less then 2 elements
    int n = S.size();
    if (n <= 1) return;

    std::vector<E> S1, S2;
    Itor p = S.begin();

    //  Insert the first half to S1
    for (int i = 0; i < n / 2; i++) S1.push_back(*p++);

    //  Insert the second half to S2
    for (int i = n / 2; i < n; i++) S2.push_back(*p++);

    // Clear S
    S.clear();

    // Recursively solve the problem
    //  S1, C
    mergeSort(S1, less);

    //  S2, C
    mergeSort(S2, less);

    // Merge the solutions together
    merge(S1, S2, S, less);
}

template<typename E, typename C>
void merge(std::vector<E>& S1, std::vector<E>& S2, std::vector<E>& S, const C& isLess) {
    // typedef typename std::vector<E>::iterator Itor;

    auto p1 = S1.begin();
    auto p2 = S2.begin();

    while (p1 != S1.end() && p2 != S2.end())
    {
        if (isLess(*p1, *p2))
        {
            S.push_back(*p1++);
        }
        else {
            S.push_back(*p2++);
        }
    }

    //  Comlpete remaining elements
    while (p1 != S1.end())
    {
        S.push_back(*p1++);
    }

    while (p2 != S2.end())
    {
        S.push_back(*p2++);
    }
}

#endif