//
//  Stack.cpp
//  Algorithms
//
//  Created by Dorin Curnic on 12.09.2024.
//

//
//	stack = LIFO data structure. Last-In First-Out
//
//	Uses of stacks:
//	1. Undo/redo features in text editors
//	2. Moving back/forward through browser history
//	3. Backtracking algorithms (maze, file directories)
//	4. Calling functions (call stack)
//

#include "Stack.hpp"
#include <iostream>
#include <stack>

using namespace std;

void stack_learn() {
	// Create a stack
	stack<string> arr;

	// Add elements to stack
	arr.push("Minecraft");
	arr.push("CS-2");
	arr.push("Dota 2");
	arr.push("Clash of Clans");
	arr.push("Shadow Fight");

	// Delete the top element from stack
	arr.pop();

	// Passes the top element of the stack to a variable
	string game = arr.top();

	// Display and clear the stack
	while (!arr.empty()) {
		cout << arr.top() << endl;
		arr.pop();
	}
}

void displayStack(){
	stack_learn();
}
