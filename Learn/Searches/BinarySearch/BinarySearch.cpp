//
//  BinarySearch.cpp
//  Algorithms
//
//  Created by Dorin Curnic on 01.10.2024.
//

//
//	Binary search = Search algorithm that finds the position of a target value within
//					a sorted array. Half of the array is eliminated during each "step"
//
//	Complexity = O(log n)

#include "BinarySearch.hpp"
#include <iostream>

using namespace std;

int binarySearch(int array[], int size, int target){
	int low = 0;
	int high = size - 1;

	while (low <= high) {
		int middle = (high + low) /2;
		int value = array[middle];

		cout << "Middle: " << value << endl;

		if (value < target) {
			low = middle + 1;
		} else if (value > target){
			high = middle -1;
		} else return middle;
	}

	return -1;
}

void displayBinarySearch(){
	int array[1000];
	int size = sizeof(array) / sizeof(array[0]);
	int target = 674;

	for (int i = 0; i < size; i++) {
		array[i] = i;
	}

	int index = binarySearch(array, size, target);

	if (index != -1) {
		cout << "The index: " << index << endl;
	} else {
		cout << "The value isn't in array" << endl;
	}
}
