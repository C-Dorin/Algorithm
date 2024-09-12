//
//  ProductArrayPuzzle.cpp
//  Algorithm
//
//  Created by Dorin Curnic on 11.09.2024.
//

#include "ProductArrayPuzzle.hpp"
#include <iostream>
#include <vector>

using namespace std;

vector<long long int> productExceptSelf() {
	vector<long long int> nums = {10, 3, 5, 6, 2};
	long long int product = 1;
	int c = 0;
	
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] != 0) {
			product *= nums[i];
		} else {
			c++;
		}
	}
	
	if (c > 1) {
		for (int i = 0; i < nums.size(); i++) {
			nums[i] = 0;
		}
	} else if (c == 1) {
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 0) {
				nums[i] = product;
			} else {
				nums[i] = 0;
			}
		}
	} else {
		for (int i = 0; i < nums.size(); i++){
			nums[i] = product/nums[i];
		}
	}
	
	return nums;
}
