//
//  Queue.cpp
//  Algorithms
//
//  Created by Dorin Curnic on 12.09.2024.
//

//
//	queue = FIFO data structure. First-In First-Out
//
//	Uses of queue:
//	1. Keyboard buffer (letters should appear on the screen in the order they're pressed)
//	2. Printer Queue (Print jobs should be completed in order)
//	3. BFS (Breadth-First Search) in Graphs
//

#include "Queue.hpp"
#include <iostream>
#include <queue>

using namespace std;

void queue_learn() {
	// Create a queue
	queue<string> arr;

	// Add elements to queue
	arr.push("Minecraft");
	arr.push("CS-2");
	arr.push("Dota 2");
	arr.push("Clash of Clans");
	arr.push("Shadow Fight");

	// Delete the first element from queue
	arr.pop();

	// Passes the first element of the queue to a variable
	string firstGame = arr.front();	// "Minecraft"

	// Passes the last element of the queue to a variable
	string lastGame = arr.back();	// "Shadow Fight"

	// Display and clear the stack
	while (!arr.empty()) {
		cout << arr.front() << endl;
		arr.pop();
	}
}

void displayQueue(){
	queue_learn();
}
