//
//  Solutie8.cpp
//  Algorithms
//
//  Created by Dorin Curnic on 12.11.2024.
//

#include "Solutie8.hpp"
#include "iostream"

using namespace std;

void Solutie8(){
	string sir, s1, palindrom;
	int stanga, dreapta;
	cout << "Scrie sirul de litere: ";
	getline(cin, s1);

	if (s1.length() <= 1) {
		cout << "Cel mai lung palindrom este: " << s1 << endl;
	}
	sir = "";

	for (int i = 0; i < s1.length(); ++i) {
		stanga = i;
		dreapta = i;

		while (stanga >= 0 && dreapta <= s1.length() && s1[stanga] == s1[dreapta]) {
			--stanga;
			++dreapta;
		}

		palindrom = s1.substr(stanga + 1, dreapta - stanga - 1);
		if (palindrom.length() > sir.length()) {
			sir = palindrom;
		}

		stanga = i;
		dreapta = i + 1;

		while (stanga >= 0 && dreapta <= s1.length() && s1[stanga] == s1[dreapta]) {
			--stanga;
			++dreapta;
		}

		palindrom = s1.substr(stanga + 1, dreapta - stanga - 1);
		if (palindrom.length() > sir.length()) {
			sir = palindrom;
		}
	}

	cout << "Cel mai lung palindrom este: " << sir << endl;
}
