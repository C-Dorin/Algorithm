//
//  MergeSort.hpp
//  Algorithms
//
//  Created by Dorin Curnic on 12.09.2024.
//

#ifndef MergeSort_hpp
#define MergeSort_hpp

#include <stdio.h>
#include <vector>

void merge(std::vector<int>& arr, unsigned long left, unsigned long mid, unsigned long right);

void mergeSort(std::vector<int>& arr, unsigned long left, unsigned long right);

#endif /* MergeSort_hpp */
