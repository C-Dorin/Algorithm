//
//  InterpolationSearch.cpp
//  Algorithms
//
//  Created by Dorin Curnic on 03.10.2024.
//

//
//	Interpolation search = improvement over binary search best used for "uniformly" distributed data
//						   "guesses" where a value might be based on calculated probe results
//						   if probe is incorrect, search area is narrowed, and a new probe is calculated
//
//	Average case: O(log(log(n)))
//	Worst case: O(n) [values increase exponentially]
//

#include "InterpolationSearch.hpp"
#include <iostream>

using namespace std;

int interpolationSearch(int array[], int size, int value){
	int low = 0;
	int high = size - 1;

	while (value >= array[low] && value <= array[high] && low <= high) {
		int probe = low + (high - low) * (value - array[low]) / (array[high] - array[low]);

		cout << "Probe: " << probe << endl;

		if (array[probe] == value) {
			return probe;
		} else if (array[probe] < value) {
			low = probe + 1;
		} else {
			high = probe - 1;
		}
	}

	return -1;
}

void displayInterpolationSearch(){
	int array[1000];
	int size = sizeof(array) / sizeof(array[0]);
	int value = 674;

	for (int i = 0; i < size; i++) {
		array[i] = i;
	}

	int index = interpolationSearch(array, size, value);

	if (index != -1) {
		cout << "The index: " << index << endl;
	} else {
		cout << "The value isn't in array" << endl;
	}
}
