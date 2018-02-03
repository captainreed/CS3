// RotatePuzzle.cpp : Defines the entry point for the console application.
//
#include "Board.h"
#include "Queue.h"

void iterate(Board bIn, boardqueue& theset);
void solveBoard(int solver);

int main()
{

	solveBoard(1);
	solveBoard(2);
	solveBoard(3);
	solveBoard(4);
	
	std::string answer;
	std::cin >> answer;
	return 0;
}

//solves and prints the boards located in input1,input3 and input3 text files located in the same directory as the project files
//if you give it 4 it will solve and print a randomly generated board
void solveBoard(int solver)
{
	Board initialBoard;
	initialBoard.makeBoard(2);
	std::string filepath;
	//will make the initialboar the board found in the input1.txt file
	if (solver == 1) { filepath = "input1.txt"; initialBoard.inputBoard(filepath); }
	//will make the initialboar the board found in the input2.txt file

	if (solver == 2) { filepath = "input2.txt"; initialBoard.inputBoard(filepath); }
	//will make the initialboar the board found in the input3.txt file

	if (solver == 3) { filepath = "input3.txt"; initialBoard.inputBoard(filepath); }

	//will make initialboard a randomly generated board jumbled by 2 moves
	if (solver == 4) { initialBoard.makeBoard(2); }
	//finish creating initialboard
	initialBoard.generation = -1;
	initialBoard.prevMove = 12;
	initialBoard.history = "";

	//the index keeps track of how many boards have been created in the solution
	int index = 0;
	bool finished = false;
	//this is the perfect board that we will compare all of the boards to
	Board solvedBoard;
	solvedBoard.makeBoard(0);
	//the queue that every board will be added to
	boardqueue set;

	set.add(initialBoard);
	//create all possible boards from the initialboard and add it to the queue
	iterate(initialBoard, set);

	//this will be the latest board every time you remove a board from the top of the queue
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

		}
		index++;

	}
}

//creates a new board with every move posibility from the givem board and adds it to the queue
void iterate(Board bIn, boardqueue& theset)
{
	int prevMove = bIn.prevMove;

	for (int i = 0; i < 12; i++)
	{
		Board b = bIn;
		b.writeHistory(b.move(i));
		b.prevMove = i;
		b.generation = bIn.generation + 1;
		theset.add(b);
	}

}


