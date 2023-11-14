#include <iostream>
#include <fstream>
#include <list>
#include <chrono>
#include "MergeSort.h"

// print first 5 and last 5 elements of a list
template<typename T>
void printFirstAndLast5(const std::list<T>& dataList) {
    auto it = dataList.begin();
    std::cout << "First 5 values: ";
    for (int i = 0; i < 5 && it != dataList.end(); ++i, ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    it = dataList.end();
    std::advance(it, -5);
    std::cout << "Last 5 values: ";
    for (; it != dataList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Author: Jesus Rodriguez-Luna" << std::endl;

    std::list<int> smallList = {4, 3, 1, 0, 9, 8, 6, 7, 5, 2};
    int comparisons = 0, moves = 0;

    std::cout << "Original small list: ";
    printList(smallList);

    mergeSort(smallList, std::less<int>(), comparisons, moves);

    std::cout << "Sorted small list: ";
    printList(smallList);

    std::cout << "Number of comparisons: " << comparisons << ", Data moves: " << moves << std::endl << std::endl;

    /*
       data from files: small1k.txt and large100k.txt
    */
    std::list<int> data1k, data100k;

    // small1k.txt
    std::ifstream file1k("C:/Users/jesus/GitHub/Sorting/small1k.txt");
    int num;
    while (file1k >> num) {
        data1k.push_back(num);
    }
    file1k.close();

    std::cout << "small1k.txt:" << std::endl;
    printFirstAndLast5(data1k);

    comparisons = 0;
    moves = 0;
    auto start1k = std::chrono::high_resolution_clock::now();
    mergeSort(data1k, std::less<int>(), comparisons, moves);
    auto stop1k = std::chrono::high_resolution_clock::now();
    auto duration1k = std::chrono::duration_cast<std::chrono::milliseconds>(stop1k - start1k);

    std::cout << "Number of comparisons for small1k.txt: " << comparisons << ", Data moves: " << moves << std::endl;
    std::cout << "Running time for small1k.txt: " << duration1k.count() << " milliseconds" << std::endl << std::endl;

    // large100k.txt
    std::ifstream file100k("C:/Users/jesus/GitHub/Sorting/large100k.txt");
    while (file100k >> num) {
        data100k.push_back(num);
    }
    file100k.close();

    std::cout << "large100k.txt:" << std::endl;
    printFirstAndLast5(data100k);

    comparisons = 0;
    moves = 0;
    auto start100k = std::chrono::high_resolution_clock::now();
    mergeSort(data100k, std::less<int>(), comparisons, moves);
    auto stop100k = std::chrono::high_resolution_clock::now();
    auto duration100k = std::chrono::duration_cast<std::chrono::milliseconds>(stop100k - start100k);

    std::cout << "Number of comparisons for large100k.txt: " << comparisons << ", Data moves: " << moves << std::endl;
    std::cout << "Running time for large100k.txt: " << duration100k.count() << " milliseconds" << std::endl;

    return 0;
}
