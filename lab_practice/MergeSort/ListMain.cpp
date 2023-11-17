#include "LinkedMergeSort.h" 

// Function to print elements of a list
template<typename E>
void printList(const std::list<E>& S) {
    for (const auto& elem : S) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Creating an unsorted list of integers
    std::list<int> myList = {9, 5, 7, 1, 3, 8, 2, 4, 6};

    std::cout << "Original List: ";
    printList(myList);

    // Sorting the list using merge sort
    mergeSort(myList, std::less<int>());

    // After sorting
    std::cout << "Sorted List: ";
    printList(myList); // Print the list after sorting

    return 0;
}
