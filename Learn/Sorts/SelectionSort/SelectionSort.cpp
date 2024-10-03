//
//  SelectionSort.cpp
//  Algorithms
//
//  Created by Dorin Curnic on 03.10.2024.
//

//
//	Selection sort = search through an array and keep track of the minimum value during
//					 each iteration. At the end of each iteration, we swap values.

//	Quadratic complexity time: O(n^2)
//
//	Small data set = okay
//	Large data set = BAD
//

#include "SelectionSort.hpp"
#include <iostream>

using namespace std;

void selectionSort(int array[], int size){
	for (int i = 0; i < size - 1; i++) {
		int min = i;
		for (int j = i + 1; j < size; j++) {
			if (array[min] > array[j]) {
				min = j;
			}
		}

		int temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
}

void displaySelectionSort(){
	int array[] = {9, 1, 8, 2, 7, 3, 6, 4, 5};
	int size = sizeof(array) / sizeof(array[0]);

	cout << "Array before: ";
	for (int i : array) {
		cout << i << " ";
	}
	cout << endl;

	selectionSort(array, size);

	cout << "Array after:  ";
	for (int i : array) {
		cout << i << " ";
	}
	cout << endl;
}
