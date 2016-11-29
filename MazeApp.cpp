//Samantha Miller
//CPSC-340-01
//Project 4: Harry Potter Stacks and Queues
//This file contains the main function the analyze the maze.

#include <iostream>
#include "Maze.h"
#include "Cell.h"

using namespace std;

//Runs the main function, which finds maze solutions using stacks and queues. 
//In: None, but requires user input.
//Out: None, but pritns to console.
int main() {
	cout<<"Welcome to Hermione and Ron's MapQuest!"<<endl;
	Maze maze;
	bool importSuccess = maze.importMaze();
	maze.printMazeSolution('r');
	return 0;
}
