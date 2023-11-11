#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <ctime>

void print(int arr[], int size);

void insertionSort(int array[], int size) {
    int unsortedValue;
    int scan;

    //add code below to count inversions
    int inversions = 0;
    int comparisons = 0;
    int data_moves = 0;

    //modify code below to count comparisons and data moves
    for (int index = 1; index < size; index++) {
        unsortedValue = array[index];
        scan = index;

        while (scan > 0 && array[scan - 1] > unsortedValue) {
            comparisons++;
            array[scan] = array[scan - 1];
            data_moves++;
            scan--;
        }
        data_moves++;
        array[scan] = unsortedValue;
        inversions += (index - scan);
    }

    print(array, size);
    std::cout << "\nInversions: " << inversions << std::endl;
    std::cout << "Comparisons: " << comparisons << std::endl;
    std::cout << "Data Moves: " << data_moves << std::endl;
}

void print(int arr[], int size){
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    int arr[] = {4, 3, 1, 0, 9, 8, 6, 7, 5, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    clock_t start, end;

    std::cout << "Before: ";
    print(arr, size);

    std::cout << "After: ";
    start = clock();
    insertionSort(arr, size);
    end = clock();

    std::cout << "Running time: " << end - start << "ms" << std::endl;
    std::cout << std::endl;

    /*
        FILE 1K 
    */
    std::fstream small1k("C:/Users/jesus/Documents/GitHub/Sorting-Algorithm/small1k.txt", std::ios_base::in);
    std::string txt = "";
    const int SIZE = 1000;
    int int_arr[SIZE];
    int i = 0;

    if(!small1k.is_open()){
        std::cout << "Not Open" << std::endl;
        return -1;
    }
    
    while (small1k >> txt && i < SIZE) {
        int_arr[i] = std::stoi(txt);
        i++;
    }

    std::cout << "Sorting small1k.txt: ";
    start = clock();
    insertionSort(int_arr, SIZE);
    end = clock();
    std::cout << "Running Time: " << end - start << "ms" << std::endl;

    return 0;
}
