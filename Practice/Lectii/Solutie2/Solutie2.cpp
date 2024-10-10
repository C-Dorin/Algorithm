//
//  Solutie2.cpp
//  Algorithms
//
//  Created by Dorin Curnic on 08.10.2024.
//

#include "Solutie2.hpp"
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void Solutie2(){
	int n, x, y, stanga, dreapta;
	cin >> n >> x;
	stanga = 0;
	dreapta = n - 1;
	vector<pair<int, int>> a(n);

	for (int i = 0; i < n; i++) {
		cin >> y;
		a[i] = {y, i};
	}
	sort(a.begin(), a.end());

	while (stanga < dreapta) {
		if (a[stanga].first + a[dreapta].first > x) {
			dreapta--;
		} else if (a[stanga].first + a[dreapta].first < x) {
			stanga++;
		} else if (a[stanga].first + a[dreapta].first == x) {
			cout << a[stanga].second + 1 << " " << a[dreapta].second + 1 << endl;
			return;
		}
	}
}
