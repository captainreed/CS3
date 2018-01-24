// RotatePuzzle.cpp : Defines the entry point for the console application.
//
#include "Board.h"
#include "Queue.h"

Board* iterate(Board bIn);

int main()
{
	Board *initialBoard = new Board();
	initialBoard->makeBoard(1);
	initialBoard->generation = 5;
	initialBoard->prevMove = 12;
	initialBoard->writeHistory("kjhjkjhjk");
	

	int index = 0;
	bool finished = false;

	Board solvedBoard;
	solvedBoard.makeBoard(0);

	boardqueue set;

	set.add(*initialBoard);

	Board *firstset = iterate(*initialBoard);
	for (int i = 0; i < 12; i++)
		set.add(*(firstset + i));

	Board *latest = new Board();


	while (!finished)
	{
		latest = set.remove();
		if (solvedBoard.operator==(*latest))
		{
			finished = true;
			std::cout << "YOU WIN!!! OriginalBoard" << std::endl;
			std::cout << latest->toString() << std::endl;
			//what to do if we finish 
			return 0;
		}
		else
		{
			std::cout << "State " << index << " From State " << latest->generation << " History " << latest->getHistory() << std::endl;
			std::cout << latest->toString() << std::endl;
			//create the 12 possible boards from this board and add them to the queue
			Board *newset = iterate(*latest);
			for (int i = 0; i < 12; i++)
			{
				set.add(*(newset + i));
			}
			//append the next 12 children from this node on to the back of the queue
		}
		index++;

	}
	return 0;
}


//returns a pointer to an array of memory locations of boards that are shifted by only 1 move in every direction except the one from which it came
Board* iterate(Board bIn)
{
	int prevMove = bIn.prevMove;
	static Board b[12] = { bIn,bIn,bIn,bIn,bIn,bIn,bIn,bIn,bIn,bIn,bIn,bIn };
	for (int i = 0; i < 12; i++)
	{
		switch (i) {
		case 0: if (i != prevMove) { b[i].rotateNorth(0); b[i].writeHistory(bIn.getHistory()); b[i].move(0); b[i].generation = bIn.generation + 1; } break;
		case 1: if (i != prevMove) { b[i].rotateNorth(1); b[i].writeHistory(bIn.getHistory()); b[i].move(1); b[i].generation = bIn.generation + 1; } break;
		case 2: if (i != prevMove) { b[i].rotateNorth(2); b[i].writeHistory(bIn.getHistory()); b[i].move(2); b[i].generation = bIn.generation + 1; } break;
		case 3: if (i != prevMove) { b[i].rotateSouth(0); b[i].writeHistory(bIn.getHistory()); b[i].move(3); b[i].generation = bIn.generation + 1; } break;
		case 4: if (i != prevMove) { b[i].rotateSouth(1); b[i].writeHistory(bIn.getHistory()); b[i].move(4); b[i].generation = bIn.generation + 1; } break;
		case 5: if (i != prevMove) { b[i].rotateSouth(2); b[i].writeHistory(bIn.getHistory()); b[i].move(5); b[i].generation = bIn.generation + 1; } break;
		case 6: if (i != prevMove) { b[i].rotateEast(0); b[i].writeHistory(bIn.getHistory());  b[i].move(6); b[i].generation = bIn.generation + 1; } break;
		case 7: if (i != prevMove) { b[i].rotateEast(1); b[i].writeHistory(bIn.getHistory());  b[i].move(7); b[i].generation = bIn.generation + 1; } break;
		case 8: if (i != prevMove) { b[i].rotateEast(2); b[i].writeHistory(bIn.getHistory());  b[i].move(8); b[i].generation = bIn.generation + 1; } break;
		case 9: if (i != prevMove) { b[i].rotateWest(0); b[i].writeHistory(bIn.getHistory());  b[i].move(9); b[i].generation = bIn.generation + 1; } break;
		case 10:if (i != prevMove) { b[i].rotateWest(1); b[i].writeHistory(bIn.getHistory());  b[i].move(10); b[i].generation = bIn.generation + 1; } break;
		case 11:if (i != prevMove) { b[i].rotateWest(2); b[i].writeHistory(bIn.getHistory());  b[i].move(11); b[i].generation = bIn.generation + 1; } break;
		}

	}
	return b;

}


