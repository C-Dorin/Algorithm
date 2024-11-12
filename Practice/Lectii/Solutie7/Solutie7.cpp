//
//  Solutie7.cpp
//  Algorithms
//
//  Created by Dorin Curnic on 10.11.2024.
//

#include "Solutie7.hpp"
#include "iostream"

using namespace std;

void Solutie7(){
	string s1, s2;
	cout << "Introduceti 2 cuvinte: ";
	cin >> s1 >> s2;
	cout << endl;

	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	unsigned long length = max(s1.size(), s2.size());

	unsigned long s1Length = s1.length();
	unsigned long s2Length = s2.length();

	for (int i = 0; i < s1Length; ++i) {
		for (int j = 0; j < s2Length; ++j) {
			if (s1[i] == s2[j]) {
				s1.erase(i, 1);
				s1.erase(j, 1);
				--s1Length;
				--s2Length;
				--i;
				--j;
			}
		}
	}

	unsigned long result = s1.length() + s2.length();

	cout << result;

}
