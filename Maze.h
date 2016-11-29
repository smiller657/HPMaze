//Samantha Miller
//CPSC-340-01
//Project 4: Harry Potter Stacks and Queues
//This file contains header information for a Maze object,
//which contains a 2D array of chars to represent the maze, 
//the entrance location, and two solution functions.

#ifndef MAZEH
#define MAZEH
#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include "Cell.h"

using namespace std;

const int ROWS = 10;
const int COLS = 10;

class Maze
{
	public:
		//Constructor for a Maze object.
		//In: None.
		//Out: A default Maze object.
		Maze();
		
		//Asks user to supply a maze file and saves the contents in the Maze object.
		//In: None, but the function asks the user to supply a maze file.
		//Out: True if succesfully imported. False if it is not.
		bool importMaze();
		
		//Solves the maze using a stack.
		//In: None, but a maze must be imported first.
		//Out: None, but saves the solution for the maze in a stack.
		void runHermione();
		
		//Solves the maze using a queue.
		//In: None, but a maze must be improted first.
		//Out: None, but saves the solution for the maze in a queue.
		void runRon();
		
		//Prints the sequence of moves for a requested solution.
		//In: A char 'H' for Hermione's stack solution or 'R' for Ron's queue solution.
		//Out: None, but prints the path to the console.
		void printMoves(char sq);
		
		//Prints the maze for a requested solution.
		//In: A char 'H' for Hermione's stack solution or 'R' for Ron's queue solution.
		//Out: None, but prints the maze with solution to console.
		void printMazeSolution(char sq);
		
		//Getter for the maze.
		//In: The maze, passed by reference.
		//Out: None, except the pass by reference 2d array maze.
		void getMaze(char m[][COLS], int ROWS, int COLS);
		
		//Setter for the maze.
		//In: The maze, passed by reference, which updates the maze object.
		//Out: None, but updates the array associated with the object.
		void setMaze(char m[][COLS], int ROWS, int COLS);
		
		//Getter for the row count of the maze.
		//In: None.
		//Out: The integer row count of the maze.
		int getRows();

		//Setter for the row count of the loaded maze.
		//In: An integer for the number of rows in the maze.
		//Out: None.
		void setRows(int r);

		//Getter for the column count of the loaded maze.
		//In: None.
		//Out: The integer for the number of rows in the maze.
		int getCols();

		//Setter for the column count of the loaded maze.
		//In: An integer for the number of columns in the maze.
		//Out: None.
		void setCols(int c);


		//Getter for the row that holds the entrance to the maze.
		//In: None.
		//Out: The row location for the entrance to the maze.
		int getEntranceRow();
		
		//Setter for the row that holds the entrance to the maze.
		//In: Updates the location for the entrance to the maze.
		//Out: None.
		void setEntranceRow(int r);
		
		//Getter for the column that holds the entrance to the maze.
		//In: None.
		//Out: The column location for the entrance to the maze.
		int getEntranceCol();
		
		//Setter for the column that holds the entrance to the maze.
		//In: Update the column location for the entrance to the maze.
		//Out: None.
		void setEntranceCol(int c);
		
		//Getter for Hermione's stack solution to the maze.
		//In: None.
		//Out: The stack of Cells that trace the solution to the maze.
		stack<Cell> getHermioneSolution();
		
		//Setter for Hermione's stack solution to the maze.
		//In: A stack of Cells that trace the solution to the maze.
		//Out: None.
		void setHermioneSolution(stack<Cell> her);
		
		//Getter for Ron's queue solution to the maze.
		//In: None.
		//Out: A queue of Cells that trace the solution to the maze.
		queue<Cell> getRonSolution();
		
		//Setter for Ron's queue solution to the maze.
		//In: A queue of Cells that trace the solution to the maze.
		//Out: None.
		void setRonSolution(queue<Cell> ron);
	
	private:
		char maze[ROWS][COLS];
		int rows;
		int cols;
		int entranceRow;
		int entranceCol;
		stack<Cell> HermioneSolution;
		queue<Cell> RonSolution;
};
#endif
