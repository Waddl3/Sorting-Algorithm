#include <iostream>

void insertionSort(int array[], int size) {
    int unsortedValue;
    int scan;

    //add code below to count inversions

    //modify code below to count comparisons and data moves
    for (int index = 1; index < size; index++) {
        unsortedValue = array[index];
        scan = index;

        while (scan > 0 && array[scan - 1] > unsortedValue) {
            array[scan] = array[scan - 1];
            scan--;
        }
        array[scan] = unsortedValue;
    }
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
