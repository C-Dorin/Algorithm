//
//  BubbleSort.cpp
//  Algorithms
//
//  Created by Dorin Curnic on 03.10.2024.
//

//
//	Bubble sort = pairs of adjacent elements are compared, and the elements swapped
//				  if they are not in order.
//
//	Quadratic complexity time: O(n^2)
//
//	small data set = okay-ish
//	large data set = BAD (plz don't)
//

#include "BubbleSort.hpp"
#include <iostream>

using namespace std;

void bubbleSort(int array[], int size){
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++){
			if (array[j] > array[j + 1]) {
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

void displayBubbleSort(){
	int array[] = {9, 1, 8, 2, 7, 3, 6, 4, 5};
	int size = sizeof(array) / sizeof(array[0]);

	cout << "Array before: ";
	for (int i : array) {
		cout << i << " ";
	}
	cout << endl;

	bubbleSort(array, size);

	cout << "Array after:  ";
	for (int i : array) {
		cout << i << " ";
	}
	cout << endl;
}
