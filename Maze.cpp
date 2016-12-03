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
	//Initialize maze to store maze import.
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			maze[i][j] = '*';
		}
	}
	rows = -1;
	cols = -1;
	entranceRow = -1;
	entranceCol = -1;

	//Initialize maze for Hermione's solution
	Cell c;
	c.setMazeChar('*');
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			c.setRow(i);
			c.setCol(j);
			hMaze[i][j] = c;
		}
	}

	//Initialize maze for Ron's solution
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			c.setRow(i);
			c.setCol(j);
			rMaze[i][j] = c;
		}
	}	
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
			hMaze[row][col].setMazeChar(point);
			rMaze[row][col].setMazeChar(point);

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

bool Maze::runHermione()
{

	if (entranceRow == -1 || entranceCol == -1) {
		cout<<"There is no entrance to the maze."<<endl;
		return false;
	}
	Cell c; //intital working cell variable
	bool hFound = false; //determines if the horcrux is found
	//stack<Cell> backTrackStack;
	stack<Cell> nStack;//track neighbors
	//Initialize entrance row
	c.setRow(entranceRow);
	c.setCol(entranceCol);
	c.setMazeChar('e');
	nStack.push(c);
	//Explore maze
	while (!hFound && !nStack.empty()) {
		Cell current = nStack.top();
		int currentRow = current.getRow();
		int currentCol = current.getCol();
		hMaze[currentRow][currentCol].setMazeChar('S');
		hMaze[currentRow][currentCol].setVisited(true);
		nStack.pop();
		hermioneSolution.push(current);
		cout<<"Popping "<<currentRow<<" "<<currentCol<<endl;
		int neighbors = 0;
		int direction = 0; //0=North, 1=South, 2=West, 3=East
		current.setVisited(true);
		while (direction <= 3) { //Check your neighbors
			int neighborRow = current.getRow();
			int neighborCol = current.getCol();
			char currentDirection = 'N';
			if (direction == 0) {
				currentDirection = 'N';
				neighborRow--;
			} else if (direction == 1) {
				currentDirection = 'S';
				neighborRow++;
			} else if (direction == 2) {
				currentDirection = 'W';
				neighborCol--;
			} else { //direction == 3
				currentDirection = 'E';
				neighborCol++;
			}

			//Push valid neighbors onto stack to find valid solution
			if (neighborRow >= 0 && neighborRow < ROWS && neighborCol >= 0 && neighborCol < COLS) {
				Cell neighbor;
				neighbor.setDirection(currentDirection);
				neighbor.setParentRow(currentRow);
				neighbor.setParentCol(currentCol);
				neighbor.setRow(neighborRow);
				neighbor.setCol(neighborCol);
				//if solution is found
				if (maze[neighborRow][neighborCol] == 'h') {
					hermioneSolution.push(neighbor);
					hFound = true;
					cout<<"Horcurx found at neighbor "<<neighbor.getRow()<<" "<<neighbor.getCol()<<endl;
				} else if (!hMaze[neighborRow][neighborCol].getVisited() 
						&& maze[neighborRow][neighborCol] == ' ') {
					hMaze[neighborRow][neighborCol].setDirection(currentDirection);
					nStack.push(neighbor);
					neighbors++;
					cout<<"Push neighbor "<<neighbor.getRow()<<" "<<neighbor.getCol()<<" "<<neighbor.getDirection()<<endl;
				}
			} //end if push valid neighbors
			direction++;
		}//end while neighbor check
		if (!hFound) {
			if (neighbors == 0) {
				//backtrack to last intersection
				bool intersectionFound = false;
				while (!intersectionFound) {
					Cell hTemp = hermioneSolution.top();
					int pRow = hTemp.getParentRow();
					int pCol = hTemp.getParentCol();
					int hRow = hTemp.getRow();
					int hCol = hTemp.getCol();
					hMaze[hRow][hCol].setMazeChar('B');
					hMaze[hRow][hCol].setBacktracked(true);
					hermioneSolution.pop();
					cout<<"Backtracking "<<hRow<<" "<<hCol<<endl;
					if (hMaze[pRow][pCol].getIntersection()) {
						intersectionFound = true;
					}
				}
		} else if (neighbors >= 2) {
				current.setIntersection(true);
			}
		} //If !hFound
	}//end while explore maze
	if (!hFound) {
		cout<<"No solution found."<<endl;
		return false;
	}
	return true;
}


bool Maze::runRon()
{
	return true;
}


void Maze::printMoves(char sq)
{
	Cell c;
	string seq = "";
	if (sq == 'h') {
		if (hermioneSolution.size() > 0) {
		cout<<"Here is Hermione's solution: "<<endl;
		stack<Cell> s;
		int i = 0;
		//Move hermione's solution to a temp stack
		while (i < hermioneSolution.size()) {
			c = hermioneSolution.top();
			s.push(c);
			hermioneSolution.pop();
		}
		//Pop the first since it's the start
		c = s.top();
		hermioneSolution.push(c);
		s.pop();
		//Concatinate to string and return to hermioneSolution
		while (i < s.size()) {
			c = s.top();
			seq = seq + c.getDirection() + "-";
			hermioneSolution.push(c);
			s.pop();
		}
		cout<<"The sequence of moves is "<<seq<<endl;
		} else {
			cout<<"No directions available for Hermione's solution."<<endl;
		}
	} else if (sq == 'r') {

	} else {
		cout<<"Invalid command."<<endl;
	}
}

void Maze::printMaze() {
	cout<<"_0123456789"<<endl;
	for (int i = 0; i < ROWS; i++) {
		cout<<i;
		for (int j = 0; j < COLS; j++) {
			cout<<maze[i][j];
		}
		cout<<endl;
	}

}

void Maze::printMazeSolution(char sq)
{
	Cell c;
	if (sq == 'h') {
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++) {
				c = hMaze[i][j];
				cout<<c.getMazeChar();
			}
			cout<<endl;
		}
	} else if (sq == 'r') {
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++) {
				cout<<rMaze[i][j].getMazeChar();
			}
			cout<<endl;
		}
	} else {
		cout<<"Invalid command."<<endl;
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
	return hermioneSolution;
}	


void Maze::setHermioneSolution(stack<Cell> her)
{
	hermioneSolution = her;
}	


queue<Cell> Maze::getRonSolution()
{
	return ronSolution;
}	


void Maze::setRonSolution(queue<Cell> ron)
{
	ronSolution = ron;
}	
#endif
