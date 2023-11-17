#include "VectorMergeSort.h"

template<typename E>
void printList(std::vector<E> v){
    for (const auto& n : v) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    std::vector<int> v = {9, 2, 7, 4, 6, 1, 3, 5, 8};

    std::cout << "Before: ";
    printList(v);

    mergeSort(v, std::less<int>());

    std::cout << "After: ";
    printList(v);

    return 0;
}
