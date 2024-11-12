//
//  Solutie6.cpp
//  Algorithms
//
//  Created by Dorin Curnic on 29.10.2024.
//

#include "Solutie6.hpp"
#include <iostream>
#include <vector>
#include <map>
#include "Learn.hpp"

using namespace std;

void Solutie6(){
	vector<string> originalWords;
	vector<string> copyWords;
	string word;
	int nr;

	cout << "Introduceti numarul de cuvinte: ";
	cin >> nr;

	for (int i = 0; i < nr; ++i) {
		cin >> word;
		originalWords.push_back(word);

		vector<int> ascii;
		for (char letter : word) {
			ascii.push_back((int)(letter));
		}

		quickSort(ascii, 0, ascii.size() - 1);
		sort(ascii.begin(), ascii.end());
		string sorted_word;
		for (int letter : ascii) {
			sorted_word += (char)(letter);
		}

		copyWords.push_back(sorted_word);
	}

	multimap<string, string> wordsMap;
	for (size_t i = 0; i < originalWords.size(); ++i) {
		wordsMap.insert({copyWords[i], originalWords[i]});
	}

	size_t index = 0;
	for (const auto& pair : wordsMap) {
		copyWords[index] = pair.first;
		originalWords[index] = pair.second;
		index++;
	}

	for (int i = 0; i < originalWords.size(); ++i) {
		cout << originalWords[i] << " ";
		if (i + 1 < originalWords.size() && copyWords[i] != copyWords[i+1]) {
			cout << endl;
		}
	}

	cout << endl;
}
