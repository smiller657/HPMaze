//Samantha Miller
//CPSC-340-01
//Project 4: Harry Potter Stacks and Queues
//This file contains header information for a cell object.
#ifndef CELLH
#define CELLH
using namespace std;
class Cell
{
	public:
		//Constructs a Cell object for the maze.
		//In: None.
		//Out: None, but a Cell object.
		Cell();

		char getMazeChar();
		void setMazeChar(char m);

		//Getter for the Character representing the parent cell's relation to the current cell.
		//In: None.
		//Out: Returns Character representing the parent cell's relation to the current cell.
		char getDirection();
		
		//Setter for Character representing the parent cell's relation to the current cell.
		//In: 'N', 'S', 'E', 'W' char representing the location from the parent.
		//Out: None.
		void setDirection(char dir);
		
		//Getter for the the location of the parent cell's row.
		//In: None.
		//Out: Coordinate of the row of the parent cell.
		int getParentRow();
		
		//Setter for the the location of the parent cell's row.
		//In: Coordinate of the row of the parent cell.
		//Out: None.
		void setParentRow(int pr);
		
		//Getter for the the location of the parent cell's column.
		//In: None.
		//Out: Coordinate of the column of the parent cell.
		int getParentCol();
		
		//Setter for the the location of the parent cell's column.
		//In: Coordinate of the column of the parent cell.
		//Out: None.
		void setParentCol(int pc);
		
		//Getter for whether the cell has been visited.
		//In: None.
		//Out: True if the cell has been visited, false if it has not.
		bool getVisited();
		
		//Setter for whether the cell has been visited.
		//In: Set true if the cell has been visited, false if it has not.
		//Out: None.
		void setVisited(bool visit);
		
		//Getter for if the tracking element has passed over the cell already.
		//In: None.
		//Out: True if the cell has been visited twice, false if it has been visited once or not at all.
		bool getBacktracked();
		
		//Setter for if the tracking element has passed over the cell already.
		//In: True if the cell has been visited twice, false if it has been visited once or not at all.
		//Out: None.
		void setBacktracked(bool bt);
		
		//Getter for the row location of the cell on the map.
		//In: None.
		//Out: The row location of the cell on the map.
		int getRow();
		
		//Setter for the row location of the cell on the map.
		//In: The row location of the cell on the map.
		//Out: None.
		void setRow(int r);
		
		//Getter for the column location of the cell on the map.
		//In: None.
		//Out: The column location of the cell on the map.
		int getCol();
		
		//Setter for the column location of the cell on the map.
		//In: The column location of the cell on the map.
		//Out: None.
		void setCol(int c);

		bool getIntersection();

		void setIntersection(bool intersects);
	private:
		char mazeChar;
		char direction; //N/S/E/W direction from the parent cell.
		int parentRow; //the row of the parent cell.
		int parentCol; //the column of the parent cell.
		bool visited; //True if visited, false if not.
		bool backtracked; //True if we have backtracked over this cell.
		int row; //Cell's row location on the map.
		int col; //Cell's column location on the map.
		bool intersection;
};
#endif
