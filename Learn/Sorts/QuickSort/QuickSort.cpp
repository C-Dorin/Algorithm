//
//  QuickSort.cpp
//  Algorithms
//
//  Created by Dorin Curnic on 03.10.2024.
//

//
//	Quick sort = moves smaller elements to left of a pivot. Recursively divide array in 2 partitions
//
//	Time complexity = Best case O(n log(n))
//					  Average case O(n log(n))
//					  Worst case O(n^2) if already sorted
//
//	Space complexity = O(log(n)) due to recursion
//

#include "QuickSort.hpp"
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& array, int start, unsigned long end){
	int pivot = array[end];
	int i = start - 1;

	for (int j = start; j <= end; j++) {
		if (array[j] < pivot) {
			i++;
			swap(array[i], array[j]);
		}
	}

	i++;
	swap(array[i], array[end]);

	return i;
}

void quickSort(vector<int>& array, int start, unsigned long end){
	if (start >= end) return;

	int pivot = partition(array, start, end);
	quickSort(array, start, pivot - 1);
	quickSort(array, pivot + 1, end);
}

void displayQuickSort(){
	vector<int> array = {1, 5, 8, 2, 9, 4, 3, 8, 6};

	// Display unsorted array
	cout << "Unsorted array: ";
	for (int x : array) {
		cout << x << " ";
	}
	cout << endl;

	quickSort(array, 0, array.size() - 1);

	// Display sorted array
	cout << "Sorted array: ";
	for (int x : array) {
		cout << x << " ";
	}
	cout << endl;
}
