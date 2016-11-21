run: Cell.o Maze.o MazeApp.o
	g++ Cell.o Maze.o MazeApp.o -o run
MazeApp.o: MazeApp.cpp
	g++ -c MazeApp.cpp
Maze.o: Maze.h Maze.cpp
	g++ -c Maze.cpp
Cell.o: Cell.h Cell.cpp
	g++ -c Cell.cpp
clean:
	rm -rf *.o
	rm -rf run
