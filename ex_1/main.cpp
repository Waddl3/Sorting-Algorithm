#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <algorithm>

struct SortMetrics {
    int inversions = 0;
    int comparisons = 0;
    int data_moves = 0;
};

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

SortMetrics insertionSort(int array[], int size) {
    int unsortedValue;
    int scan;
    SortMetrics metrics;

    for (int index = 1; index < size; index++) {
        unsortedValue = array[index];
        scan = index;

        while (scan > 0 && array[scan - 1] > unsortedValue) {
            metrics.comparisons++;
            array[scan] = array[scan - 1];
            metrics.data_moves++;
            scan--;
        }

        metrics.data_moves++;
        array[scan] = unsortedValue;
        metrics.inversions += (index - scan);
    }

    return metrics;
}

int main(int argc, char const *argv[]) {
    std::cout << "Author: Jesus Rodriguez-Luna" << std::endl;
    
    int arr[] = {4, 3, 1, 0, 9, 8, 6, 7, 5, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original Small List: ";
    print(arr, size);

    std::cout << "\nInsertion Sort for Original Small List: \n";
    SortMetrics originalMetrics = insertionSort(arr, size);
    std::cout << "Sorted List: ";
    print(arr, size);
    std::cout << "Inversions: " << originalMetrics.inversions << std::endl;
    std::cout << "Comparisons: " << originalMetrics.comparisons << std::endl;
    std::cout << "Data Moves: " << originalMetrics.data_moves << std::endl;

    // Sort the sorted list again
    std::cout << "\nSorting the Sorted List: \n";
    SortMetrics sortedAgainMetrics = insertionSort(arr, size);
    std::cout << "Sorted List: ";
    print(arr, size);
    std::cout << "Inversions: " << sortedAgainMetrics.inversions << std::endl;
    std::cout << "Comparisons: " << sortedAgainMetrics.comparisons << std::endl;
    std::cout << "Data Moves: " << sortedAgainMetrics.data_moves << std::endl;

    // Reverse the sorted list and sort it again
    std::cout << "\nSorting the Reversed List: \n";
    std::reverse(std::begin(arr), std::end(arr));
    SortMetrics reversedMetrics = insertionSort(arr, size);
    std::cout << "Sorted List (Descending): ";
    print(arr, size);
    std::cout << "Inversions: " << reversedMetrics.inversions << std::endl;
    std::cout << "Comparisons: " << reversedMetrics.comparisons << std::endl;
    std::cout << "Data Moves: " << reversedMetrics.data_moves << std::endl;

    /*
        FILE 1K
    */
    std::fstream small1k("C:/Users/jesus/GitHub/Sorting/small1k.txt", std::ios_base::in);
    const int SIZE = 1000;
    int int_arr[SIZE];

    if (!small1k.is_open()) {
        std::cout << "File not open!" << std::endl;
        return -1;
    }

    int i = 0;
    std::string txt;
    while (small1k >> txt && i < SIZE) {
        int_arr[i++] = std::stoi(txt);
    }
    small1k.close();

    std::cout << "\nSorting small1k.txt: ";
    clock_t start = clock();
    SortMetrics fileMetrics = insertionSort(int_arr, SIZE);
    clock_t end = clock();

    std::cout << "Running Time: " << end - start << "ms" << std::endl;
    std::cout << "Inversions: " << fileMetrics.inversions << std::endl;
    std::cout << "Comparisons: " << fileMetrics.comparisons << std::endl;
    std::cout << "Data Moves: " << fileMetrics.data_moves << std::endl;

    return 0;
}
