//
//  Solutie3.cpp
//  Algorithms
//
//  Created by Dorin Curnic on 08.10.2024.
//

#include "Solutie3.hpp"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
#include <algorithm>

using namespace std;

void Solutie3(){
	unordered_map<int, int> jurnal;
	int clienti = 0;
	cin >> clienti;

	int ora_sosire, ora_plecare;
	for (int i = 0; i < clienti; i++) {
		cin >> ora_sosire >> ora_plecare;

		jurnal[ora_sosire] = ora_plecare;
	}

	int min_key = numeric_limits<int>::max();
	int max_value = numeric_limits<int>::min();

	for (const auto& pair : jurnal) {
		if (pair.first < min_key) {
			min_key = pair.first;
		}

		if (pair.second > max_value) {
			max_value = pair.second;
		}
	}

	vector<int> clientiPerHour;
	int count = 0;
	for (int i = min_key; i <= max_value; i++) {
		for (const auto& pair : jurnal) {
			if (pair.first == i) {
				count++;
			}

			if (pair.second == i) {
				count--;
			}
		}
		clientiPerHour.push_back(count);
	}

	auto max_clientiPerHour = max_element(clientiPerHour.begin(), clientiPerHour.end());

	cout << "Maximum clients per hour: " << *max_clientiPerHour << endl;
}
