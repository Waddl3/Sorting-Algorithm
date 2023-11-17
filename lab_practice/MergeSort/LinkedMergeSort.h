#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <iostream>
#include <list>

template<typename E, typename C>
void merge(std::list<E>& S1, std::list<E>& S2, std::list<E>& S, const C& isLess);

// For a list S of size n, function mergeSort(S, c) runs in O(n log n)
template<typename E, typename C>
void mergeSort(std::list<E>& S, const C& less) {
    typedef typename std::list<E>::iterator Itor;
    // base case:   if theres only two or less elements, return
    int n = S.size();
    if (n <= 1) return;

    std::list<E> S1, S2;
    Itor p = S.begin();

    // Copy first half to S1
    for (int i = 0; i < n/2; i++) S1.push_back(*p++);

    // Copy second half to S2
    for (int i = n/2; i < n; i++) S2.push_back(*p++);
    S.clear();  //  Clear Contents in original S

    //recur on the first half
    mergeSort(S1, less);

    //recur on the second half
    mergeSort(S2, less);

    //merge S1 and S2 into S
    merge(S1, S2, S, less);
}

template<typename E, typename C>
void merge(std::list<E>& S1, std::list<E>& S2, std::list<E>& S, const C& isLess) {
    typedef typename std::list<E>::iterator Itor;   //  Sequence of elements
    Itor p1 = S1.begin();
    Itor p2 = S2.begin();

    // until either is empty, append smaller to S
    while (p1  != S1.end() && p2 != S2.end()) {
        if(isLess(*p1, *p2)){
            S.push_back(*p1++);
        }
        else {
            S.push_back(*p2++);
        }
    }

    //  Copy the remaining elements S1 to S
    while (p1 != S1.end()){
        S.push_back(*p1++);
    }

    //  Copy the remaining elements S2 to S
    while (p2 != S2.end()) {
        S.push_back(*p2++);
    }
}

#endif