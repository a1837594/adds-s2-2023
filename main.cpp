#include <iostream>
#include <vector>
#include "Sort.h"
#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

int main() {
    std::vector<int> input;
    int num;
    
    while (std::cin >> num) {
        input.push_back(num);
    }
    
    BubbleSort bubbleSort;
    QuickSort quickSort;
    RecursiveBinarySearch binarySearch;
    
    std::vector<int> sortedList = quickSort.sort(input);
    int target = 1;
    
    bool found = binarySearch.search(sortedList, target);
    
    std::cout << (found ? "true" : "false");
    
    for (int num : sortedList) {
        std::cout << " " << num;
    }
    
    std::cout << std::endl;
    
    return 0;
}
