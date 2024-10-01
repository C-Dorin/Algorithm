//
//  DynamicArray.cpp
//  Algorithms
//
//  Created by Dorin Curnic on 24.09.2024.
//

//
//	Dynamic array = a random access, variable-size list data structure that allows
//					elements to be added or removed
//
//	Advantages:
//	1. Random access of elements O(1)
//	2. Good locality of reference and data cache utilization
//	3. Easy to insert/delete at the end
//
//	Disadvantages:
//	1. Wastes more memory
//	2. Shifting elements is time consuming O(n)
//	3. Expanding/Shrinking the array is time consuming O(n)
//

#include "DynamicArray.hpp"
#include "iostream"

using namespace std;

void dynamicArray(){
	// Create a dynamic array of size 'length'
	vector<int> dynamicArray;

	// Adding elements dynamically
	dynamicArray.push_back(10);
	dynamicArray.push_back(20);
	dynamicArray.push_back(30);
	dynamicArray.push_back(40);
	dynamicArray.push_back(50);

	// Output the dynamic array
	for (int i = 0; i < dynamicArray.size(); i++) {
		cout << dynamicArray[i] << " ";
	}
	cout << endl;

	// Removing the last element
	dynamicArray.pop_back();
	
}

void dysplayDynamicArray(){
	dynamicArray();
}
