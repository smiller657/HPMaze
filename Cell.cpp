//Samantha Miller
//CPSC-340-01
//Project 4: Harry Potter Stacks and Queues
//This file contains the implementation for a cell object.
#ifndef CELLCPP
#define CELLCPP
#include "Cell.h"

using namespace std;

Cell::Cell() 
{
	direction = ' ';
	parentRow = -1;
	parentCol = -1;
	visited = false;
	backtracked = false;
	intersection = false;
	row = -1;
	col = -1;
}

char Cell::getMazeChar()
{
	return mazeChar;
}

void Cell::setMazeChar(char m)
{
	mazeChar = m;
}

char Cell::getDirection()
{
	return direction;
}

void Cell::setDirection(char dir)
{
		direction = dir;
}

int Cell::getParentRow()
{
	return parentRow;
}

void Cell::setParentRow(int pr)
{
	parentRow = pr;
}

int Cell::getParentCol()
{
	return parentCol;
}

void Cell::setParentCol(int pc)
{
	parentCol = pc;
}

bool Cell::getVisited()
{
	return visited;
}

void Cell::setVisited(bool visit)
{
	visited = visit;
}

bool Cell::getBacktracked()
{
	return backtracked;
}

void Cell::setBacktracked(bool bt)
{
	backtracked = bt;
}

int Cell::getRow()
{
	return row;
}

void Cell::setRow(int r)
{
	row = r;
}

int Cell::getCol()
{
	return col;
}

void Cell::setCol(int c)
{
	col = c;
}

bool Cell::getIntersection() {
	return intersection;
}

void Cell::setIntersection(bool intersects) {
	intersection = intersects;
}
#endif
