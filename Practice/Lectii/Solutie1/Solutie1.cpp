//
//  Solutie1.cpp
//  Algorithms
//
//  Created by Dorin Curnic on 08.10.2024.
//

#include "Solutie1.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

void Solutie1(){
	ifstream fin("Solutie1in.txt");
	ofstream fout("Solutie1out.txt");

	int n, Q, op, x;
	fin >> n;
	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		fin >> a[i];
	}
	fin >> Q;

	for (int i = 0; i < Q; i++) {
		fin >> op >> x;

		switch (op) {
			case 1: {
				auto it = upper_bound(a.begin(), a.end(), x);
				fout << (it - a.begin()) << endl;
			}
				break;
			case 2: {
				auto it = upper_bound(a.begin(), a.end(), x);
				fout << (a.end() - it) << endl;
			}
				break;
			case 3: {
				auto lb = lower_bound(a.begin(), a.end(), x);
				auto up = upper_bound(a.begin(), a.end(), x);
				fout << (up - lb) << endl;
			}
				break;
			default:
				cerr << "Errorare" << endl;
				break;
		}
	}

	fin.close();
	fout.close();

}
