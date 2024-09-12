//
//  MergeSort.cpp
//  Algorithms
//
//  Created by Dorin Curnic on 12.09.2024.
//

//
//	Expected Time Complexity: O(n*logn)
//	Expected Auxiliary Space: O(n)
//

#include "MergeSort.hpp"
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, unsigned long left, unsigned long mid, unsigned long right) {
	// Create sizes of halfs
	unsigned long leftHalf = mid - left + 1;
	unsigned long rightHalf = right - mid;

	// Create temporary arrays
	vector<int> leftArr(leftHalf);
	vector<int> rightArr(rightHalf);

	// Copy data to temporary arrays
	for (int i = 0; i < leftHalf; i++) {
		leftArr[i] = arr[left + i];
	}
	for (int i = 0; i < rightHalf; i++) {
		rightArr[i] = arr[mid + 1 + i];
	}

	// Merge the temporary arrays back into arr[left..right]
	unsigned long i = 0, j = 0, k = left;
	while (i < leftHalf && j < rightHalf) {
		if (leftArr[i] <= rightArr[j]) {
			arr[k] = leftArr[i];
			i++;
		} else {
			arr[k] = rightArr[j];
			j++;
		}
		k++;
	}

	// Add the remained elements of leftArr at the tail
	while (i < leftHalf) {
		arr[k] = leftArr[i];
		i++;
		k++;
	}

	// Add the remained elements of rightArr at the tail
	while (j < rightHalf) {
		arr[k] = rightArr[j];
		j++;
		k++;
	}
}

void mergeSort(vector<int>& arr, unsigned long left, unsigned long right) {
	if (left < right) {
		unsigned long mid = left + (right - left) / 2;

		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		merge(arr, left, mid, right);
	}
}
