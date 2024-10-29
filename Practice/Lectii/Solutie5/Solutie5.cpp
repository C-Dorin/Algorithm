//
//  Solutie5.cpp
//  Algorithms
//
//  Created by Dorin Curnic on 22.10.2024.
//

#include "Solutie5.hpp"
#include <iostream>
#include <stack>

using namespace std;

void Solutie5(){
	stack<string> words;
	bool lastWord = false;
	string word;

	while (true) {
		getline(cin, word);

		if (word.empty()) {
			break;
		} else {
			words.push(word);
			lastWord = false;
		}
	}

	long a = words.size();
	for (int i = 0; i < a; i++) {
		cout << words.top() << endl;
		words.pop();
	}
}
