//
//  Manacher.cpp
//  Algorithms
//
//  Created by Dorin Curnic on 12.11.2024.
//

#include "Manacher.hpp"
#include "iostream"
#include "vector"

using namespace std;

void Manacher(){
	string sir;
	cout << "Scrie sirul de litere: ";
	cin >> sir;

	string temp = "#";
	unsigned long nr1 = sir.length();

	for (int i = 0; i < nr1; ++i) {
		temp += sir[i];
		temp += '#';
	}

	unsigned long n = temp.length();
	vector<int> palindrom(n, 0);
	int stanga = 0;
	int dreapta = -1;
	int lungimeaMax = 0;
	int centru = 0;

	for (int i = 0; i < n; ++i) {
		int k;

		if (i > dreapta) {
			k = 1;
		} else {
			k = min(palindrom[stanga + dreapta - i], dreapta - i);
		}

		while (i - k >= 0 && i + k < n && temp[i - k] == temp[i + k]) {
			++k;
		}

		palindrom[i] = --k;

		if (i + k > dreapta) {
			stanga = i - k;
			dreapta = i + k;
		}

		if (palindrom[i] > lungimeaMax) {
			lungimeaMax = palindrom[i];
			centru = i;
		}
	}

	int start = (centru - lungimeaMax) / 2;
	cout << sir.substr(start, lungimeaMax) << endl;

}
