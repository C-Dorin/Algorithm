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

// Function to merge two halves of the array
void merge(vector<int>& arr, unsigned long left, unsigned long mid, unsigned long right) {
	// Calculate the sizes of halves
	unsigned long leftHalf = mid - left + 1;
	unsigned long rightHalf = right - mid;

	// Create temporary arrays to hold the left and right halves
	vector<int> leftArr(leftHalf);
	vector<int> rightArr(rightHalf);

	// Copy data to temporary arrays
	for (unsigned long i = 0; i < leftHalf; i++) {
		leftArr[i] = arr[left + i];
	}
	for (unsigned long i = 0; i < rightHalf; i++) {
		rightArr[i] = arr[mid + 1 + i];
	}

	// Merge the temporary arrays back into the original array
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

	// Copy any remaining elements of leftArr
	while (i < leftHalf) {
		arr[k] = leftArr[i];
		i++;
		k++;
	}

	// Copy any remaining elements of rightArr
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

void displayMergeSort(){
	vector<int> arr = {1, 5, 8, 2, 9, 4, 3, 8, 6};

	// Display unsorted array
	cout << "Unsorted array: ";
	for (int x : arr) {
		cout << x << " ";
	}
	cout << endl;

	mergeSort(arr, 0, arr.size() - 1);

	// Display sorted array
	cout << "Sorted array: ";
	for (int x : arr) {
		cout << x << " ";
	}
	cout << endl;
}
