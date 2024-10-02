//
//  LinearSearch.cpp
//  Algorithms
//
//  Created by Dorin Curnic on 01.10.2024.
//

//
//	Linear search = Iterate through a collection one element at a time
//	Runtime complexity: O(n)
//
//	Advantages:
//	1. Fast for searches of small to medium data sets
//	2. Does not need to sorted
//	3. Useful for data structures that do not have random access (Linked List)
//
//	Disadvantages:
//	1. Slow for large data sets
//

#include "LinearSearch.hpp"
#include <iostream>

using namespace std;

int linearSearch(int array[], int size, int value){
	for (int i = 0; i < size; i++) {
		if (array[i] == value) {
			return i;
		}
	}

	return -1;
}

void displayLinearSearch(){
	int array[] = {1, 6, 2, 4, 3, 8, 5, 9, 7};
	int size = sizeof(array) / sizeof(array[0]);
	int value = 10;

	int index = linearSearch(array, size, value);

	if (index != -1) {
		cout << "The index: " << index << endl;
	} else {
		cout << "The value " << value <<" isn't in array" << endl;
	}
}
