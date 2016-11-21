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
#include "Cell.h"
#include "Maze.h"

using namespace std;

Maze::Maze()
{
	/*for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			maze[i][j] = '-';
		}
	}*/
	entranceRow = -1;
	entranceCol = -1;
}

void Maze::importMaze()
{
	
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
