//
//  romanToInteger.cpp
//  Algorithms
//
//  Created by Dorin Curnic on 17.09.2024.
//

#include "romanToInteger.hpp"
#include <iostream>
#include <vector>

using namespace std;

void romanToInteger(vector<char>& nrRoman){
	vector<int> nrInteger(10);
	int result = 0;

	unsigned long i;
	for (i = 0; i < nrRoman.size(); i++) {
		if (nrRoman[i] == 'I') {
			nrInteger[i] = 1;
		} else if (nrRoman[i] == 'V') {
			nrInteger[i] = 5;
		} else if (nrRoman[i] == 'X') {
			nrInteger[i] = 10;
		} else if (nrRoman[i] == 'L') {
			nrInteger[i] = 50;
		} else if (nrRoman[i] == 'C') {
			nrInteger[i] = 100;
		} else if (nrRoman[i] == 'D') {
			nrInteger[i] = 500;
		} else if (nrRoman[i] == 'M') {
			nrInteger[i] = 1000;
		}
	}

	for (i = 0; i < nrInteger.size() - 1; i++) {
		if (nrInteger[i] < nrInteger[i+1]) {
			nrInteger[i] = nrInteger[i+1] - nrInteger[i];
			nrInteger[i+1] = 0;
		}
	}

	for (i = 0; i < nrInteger.size(); i++) {
		result += nrInteger[i];
	}

	

	cout << "Numarul: " << result <<endl;
}

void displayRomanToInteger(){
	vector<char> nrRoman;

	cout << "Introduceti numarul roman: ";

	string input;
	getline(cin, input);

	for (char &c : input) {
		if (isalpha(c)) {
			nrRoman.push_back(toupper(c));
		}
		
	}

	romanToInteger(nrRoman);
}
