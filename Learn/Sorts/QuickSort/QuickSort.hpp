//
//  QuickSort.hpp
//  Algorithms
//
//  Created by Dorin Curnic on 03.10.2024.
//

#ifndef QuickSort_hpp
#define QuickSort_hpp

#include <vector>

int partition(std::vector<int>& array, int start, unsigned long end);
void quickSort(std::vector<int>& array, int start, unsigned long end);
void displayQuickSort();

#endif /* QuickSort_hpp */
