//Samantha Miller
//CPSC-340-01
//Project 4: Harry Potter Stacks and Queues
//This file contains implementation for a Maze object,
//which contains a 2D array of chars to represent the maze, 
//the entrance location, and two solution functions.

#ifndef MAZECPP
#define MAZECPP
#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <string>
#include "Cell.h"
#include "Maze.h"

using namespace std;

Maze::Maze()
{	
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			maze[i][j] = '*';
		}
	}
	rows = -1;
	cols = -1;
	entranceRow = -1;
	entranceCol = -1;
}

bool Maze::importMaze()
{
	string filename = "";
	ifstream inFile;
	bool goodFile = false;
	char point = ' ';
	int row = 0;
	int col = 0;

	//Ask the user for the file name
	while (!goodFile) {
		cout<<"Type the name of the maze file (e.g., Maze.txt): ";
		getline(cin, filename);
		inFile.open(filename.c_str());
		if (!inFile) {
			cout<<"File not found."<<endl;
			inFile.close();
		} else {
			goodFile = true;
		}
	}
	//Apparently .open() requires an array of characters, not a string.
	//Source: stackoverflow.com/questions/15179924/ifstreamopen-function-using-a-string-as-the-parameter

	cout<<"Reading secret map of "<<filename<<"... Please be patient..."<<endl;

	//Get the first line which contains the rows and columns of the maze.
	inFile>>rows;
	inFile>>cols;

	if (rows > 0 && cols > 0 && rows <= ROWS && cols <= COLS) {
		cout<<"The parameters "<<rows<<" and "<<cols<<" are correctly formatted."<<endl;	
	} else {
		cout<<"The parameters for your maze are listed incorrectly.  Please try again."<<endl;
		return false;
	}
	//inFile.ignore(80, '\n');
	//Import the file data
	while (!inFile.eof()) {
		//Parse 
		inFile.get(point);
		if (point == 'e' || point == '*' || point == 'h' || point == ' ') {	
		//	cout<<"["<<row<<"]"<<"["<<col<<"] "<<point<<endl;
			maze[row][col] = point;
			//Check if the point is the entrance and update reference variables.
			if (point == 'e') {
				entranceRow = row;
				entranceCol = col;
			}

			//Update counts
			if (col >= cols - 1) {
				col = 0;
				row++;
			} else {
				col++;
			}
		}
	}

	//Close the file once complete
	inFile.close();
	cout<<"Maze has been imported."<<endl;
}		

void Maze::runHermione()
{

}


void Maze::runRon()
{

}


void Maze::printMoves(char sq)
{

}


void Maze::printMazeSolution(char sq)
{
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			cout<<maze[i][j];
		}
		cout<<endl;
	}
}	


void Maze::getMaze(char m[][COLS], int ROWS, int COLS)
{
	/*for (int i = 0; i < ROWS; i++) {
	  for (int j = 0; j < COLS; j++) {
	  maze[i][j] = '-';
	  }
	  }*/
}	


void Maze::setMaze(char m[][COLS], int ROWS, int COLS)
{
	/*for (int i = 0; i < ROWS; i++) {
	  for (int j = 0; j < COLS; j++) {
	  maze[i][j] = '-';
	  }
	  }*/
}	

int Maze::getRows()
{
	return rows;
}

void Maze::setRows(int r)
{
	rows = r;
}

int Maze::getCols()
{
	return cols;
}

void Maze::setCols(int c)
{
	cols = c;
}

int Maze::getEntranceRow()
{
	return entranceRow;
}	

void Maze::setEntranceRow(int r)
{
	entranceRow = r;
}	

int Maze::getEntranceCol()
{
	return entranceCol;
}	


void Maze::setEntranceCol(int c)
{
	entranceCol = c;
}	

stack<Cell> Maze::getHermioneSolution()
{
	return HermioneSolution;
}	


void Maze::setHermioneSolution(stack<Cell> her)
{
	HermioneSolution = her;
}	


queue<Cell> Maze::getRonSolution()
{
	return RonSolution;
}	


void Maze::setRonSolution(queue<Cell> ron)
{
	RonSolution = ron;
}	


/* private variables:
   char maze[10][10];
   int entranceRow;
   int entranceCol;
   stack<Cell> HermioneSolution;
   queue<Cell> RonSolution;*/
#endif
