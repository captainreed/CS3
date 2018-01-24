// RotatePuzzle.cpp : Defines the entry point for the console application.
//
#include "Board.h"
#include "Queue.h"

void iterate(Board bIn, boardqueue& theset);

int main()
{
	Board initialBoard;
	initialBoard.makeBoard(1);
	initialBoard.generation = 0;
	initialBoard.prevMove = 12;
	initialBoard.history = "";


	int index = 0;
	bool finished = false;

	Board solvedBoard;
	solvedBoard.makeBoard(0);

	boardqueue set;

	set.add(initialBoard);

	iterate(initialBoard, set);

	Board latest;


	while (!finished)
	{
		latest = set.remove();
		if (solvedBoard.operator==(latest))
		{
			finished = true;
			std::cout << "YOU WIN!!! OriginalBoard" << latest.history << std::endl;
			std::cout << latest.toString() << std::endl;
			//what to do if we finish 

		}
		else
		{
			std::cout << "State " << index << " From State " << latest.generation << " History " << latest.getHistory() << std::endl;
			std::cout << latest.toString() << std::endl;
			//create the 12 possible boards from this board and add them to the queue
			iterate(latest, set);
			//append the next 12 children from this node on to the back of the queue
		}
		index++;

	}
	std::string answer;
	std::cin >> answer;
	return 0;
}


//returns a pointer to an array of memory locations of boards that are shifted by only 1 move in every direction except the one from which it came
void iterate(Board bIn, boardqueue& theset)
{
	int prevMove = bIn.prevMove;

	for (int i = 0; i < 12; i++)
	{
		Board b = bIn;
		switch (i) {
		case 0: if (i != prevMove) { b.rotateNorth(0);  b.move(0); } break;
		case 1: if (i != prevMove) { b.rotateNorth(1);  b.move(1); } break;
		case 2: if (i != prevMove) { b.rotateNorth(2);  b.move(2); } break;
		case 3: if (i != prevMove) { b.rotateSouth(0);  b.move(3); } break;
		case 4: if (i != prevMove) { b.rotateSouth(1);  b.move(4); } break;
		case 5: if (i != prevMove) { b.rotateSouth(2);  b.move(5); } break;
		case 6: if (i != prevMove) { b.rotateEast(0);   b.move(6); } break;
		case 7: if (i != prevMove) { b.rotateEast(1);   b.move(7); } break;
		case 8: if (i != prevMove) { b.rotateEast(2);   b.move(8); } break;
		case 9: if (i != prevMove) { b.rotateWest(0);   b.move(9); } break;
		case 10:if (i != prevMove) { b.rotateWest(1);   b.move(10); } break;
		case 11:if (i != prevMove) { b.rotateWest(2);   b.move(11); } break;
		}
		b.prevMove = i;
		b.generation = bIn.generation + 1;
		theset.add(b);
	}

}


