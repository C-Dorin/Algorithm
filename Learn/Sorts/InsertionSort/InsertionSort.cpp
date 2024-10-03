//
//  InsertionSort.cpp
//  Algorithms
//
//  Created by Dorin Curnic on 03.10.2024.
//

//
//	Insertion sort = after comparing elements to the left,
//					 shift elements to the right to make room to insert a value
//
//	Quadratic complexity time: O(n^2)
//
//	small data set = decent
//	large data set = BAD
//
//	Less steps than Bubble sort
//	Best case is O(n) compared to Selection sort O(n^2)
//

#include "InsertionSort.hpp"
#include <iostream>

using namespace std;

void insertionSort(int array[], int size){
	for (int i = 1; i < size; i++) {
		int temp = array[i];
		int j = i - 1;

		while (j >= 0 && array[j] > temp) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = temp;
	}
}

void displayInsertionSort(){
	int array[] = {9, 1, 8, 2, 7, 3, 6, 4, 5};
	int size = sizeof(array) / sizeof(array[0]);

	cout << "Array before: ";
	for (int i : array) {
		cout << i << " ";
	}
	cout << endl;

	insertionSort(array, size);

	cout << "Array after:  ";
	for (int i : array) {
		cout << i << " ";
	}
	cout << endl;
}

