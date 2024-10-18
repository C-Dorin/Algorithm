//
//  Solutie4.cpp
//  Algorithms
//
//  Created by Dorin Curnic on 15.10.2024.
//

#include "Solutie4.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cctype>

using namespace std;

// Operations
int add(int a, int b) {
	return  a + b;
}

int subtract(int a, int b) {
	return a - b;
}

int multiply(int a, int b) {
	return a * b;
}

int divide(int a, int b) {
	return a / b;
}

// Transform a romanNumber => integerNumber
int romanToInteger(const string& nrRoman){
	int result = 0;
	unordered_map<char, int> romanMap = {
		{'I', 1},
		{'V', 5},
		{'X', 10},
		{'L', 50},
		{'C', 100},
		{'D', 500},
		{'M', 1000}
	};

	for (int i = 0; i < nrRoman.size(); i++) {
		int currentVal = romanMap[nrRoman[i]];
		int nextVal = (i + 1 < nrRoman.size()) ? romanMap[nrRoman[i + 1]] : 0;

		if (currentVal < nextVal) {
			result += nextVal - currentVal;
			i++;
		} else {
			result += currentVal;
		}
	}

	return result;
}


void makeOperations(const vector<string>& nrRoman, const vector<char>& semn){
	vector<int> nrInteger;
	for (const auto& roman : nrRoman) {
		nrInteger.push_back(romanToInteger(roman));
	}

	vector<int> values = nrInteger;
	vector<char> operations = semn;

	// Make the multiply and divide operations, then rewrite the result
	for (int i = 0; i < operations.size(); i++) {
		if (operations[i] == '*' || operations[i] == '/') {
			int result;
			if (operations[i] == '*') {
				result = multiply(values[i], values[i+1]);
			} else {
				result = divide(values[i], values[i+1]);
			}

			values[i] = result;
			values.erase(values.begin() + i + 1);
			operations.erase(operations.begin() + i);
			i--;
		}
	}

	for (int i : values) {
		cout << i << " ";
	}
	cout << endl << endl;

	int finalResult = values[0];
	for (int i = 0; i < operations.size(); i++) {
		if (operations[i] == '+') {
			finalResult = add(finalResult, values[i+1]);
		} else if (operations[i] == '-') {
			finalResult = subtract(finalResult, values[i+1]);
		}
		for (int i : values) {
			cout << i << " ";
		}
		cout << finalResult;
		cout << endl << endl;
	}

	cout << "The answer: " << finalResult << endl;
}

void Solutie4(){
	vector<string> nrRoman;
	vector<char> semn;
	char simbol;

	cout << "Introduceti expresia: ";

	string tempNrRoman = "";
	while (true) {
		cin.get(simbol);
		if (simbol == '\n') {
			if (tempNrRoman != "") {
				nrRoman.push_back(tempNrRoman);
			}
			break;
		}

		if (simbol != '*' && simbol != '/' && simbol != '+' && simbol != '-') {
			if (isalpha(simbol)) {
				simbol = (toupper(simbol));
			}
			tempNrRoman += simbol;
		} else {
			semn.push_back(simbol);
			nrRoman.push_back(tempNrRoman);
			tempNrRoman = "";
		}
	}

	makeOperations(nrRoman, semn);
}
