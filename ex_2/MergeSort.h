#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <iostream>
#include <list>
#include <chrono>

template <typename E, typename C>
void merge(std::list<E>& S1, std::list<E>& S2, std::list<E>& S, const C& less, int& comparisons, int& moves);

template <typename E, typename C>
void mergeSort(std::list<E>& S, const C& less, int& comparisons, int& moves) {
    typedef typename std::list<E>::iterator Itor;
    int n = S.size();
    if (n <= 1) return;

    std::list<E> S1, S2;
    Itor p = S.begin();
    for (int i = 0; i < n/2; i++) S1.push_back(*p++);
    for (int i = n/2; i < n; i++) S2.push_back(*p++);
    S.clear();

    mergeSort(S1, less, comparisons, moves);
    mergeSort(S2, less, comparisons, moves);
    merge(S1, S2, S, less, comparisons, moves);
}

template <typename E, typename C>
void merge(std::list<E>& S1, std::list<E>& S2, std::list<E>& S, const C& less, int& comparisons, int& moves) {
    typedef typename std::list<E>::iterator Itor;
    Itor p1 = S1.begin();
    Itor p2 = S2.begin();
    while(p1 != S1.end() && p2 != S2.end()) {
        comparisons++;
        if(less(*p1, *p2))
            S.push_back(*p1++);
        else
            S.push_back(*p2++);
        moves++;
    }
    while(p1 != S1.end())
        S.push_back(*p1++);
    while(p2 != S2.end())
        S.push_back(*p2++);
}

template <typename E>
void printList(const std::list<E>& S) {
    for (const auto& elem : S) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

#endif // MERGE_SORT_H
