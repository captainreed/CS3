#include "aStarSolve.h"
#include "Board.h"
#include "Queue.h"
#include "AvlTree.h"

//astar solve constructor, creates the AVL tree and declares the pertenant variables
aStarSolve::aStarSolve(Board &input)
{
	input.costSoFar = 0;
	input.priority = 0;
	theTree.insert(input);
}
aStarSolve::~aStarSolve()
{
}

void aStarSolve::solve(Board input)
{
	bool solved = false;
	int index = 0;
	Board latest;
	Board solvedBoard;
	solvedBoard.makeBoard(0);
	input.index = index;
	insertChildren(input, theTree);

	while (!solved)
	{
		latest = theTree.findMin();
		theTree.removeMin();
		latest.index = index;

		if (solvedBoard.operator==(latest))
		{
			solved = true;
			std::cout << "YOU WIN!!! OriginalBoard" << latest.history << std::endl;
			std::cout << latest.toString() << std::endl;
			//what to do if we finish 
		}
		else
		{

			//std::cout << "State " << index << " From State " << latest.generation << " History " << latest.getHistory() << "pevious index" << latest.prevMove << std::endl;
			std::cout << "State " << index << " From State " << latest.generation << " History " << latest.getHistory() << std::endl;

			std::cout << latest.toString() << std::endl;

			//create the 12 possible boards from this board and add them to the queue
			insertChildren(latest, theTree);
		}
		index++;
	}

}

float aStarSolve::getPriority(Board &input, Board solvedBoard)
{
	float prioritySum = 0;

	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (!correctRow(row,col,input,solvedBoard))
				prioritySum += 1;

			if (!correctCol(row, col, input, solvedBoard))
				prioritySum += 1;

		}
		
	}
	return prioritySum/3;
	
}
bool aStarSolve::correctRow(int row, int col, Board input, Board solvedBoard)
{
	bool rightRow = false;
	for (int i = 0; i < 3; i++)
	{
		if (input.board[row][col] == solvedBoard.board[i][col])
			rightRow = true;
	}
	return rightRow;
}
bool aStarSolve::correctCol(int row, int col, Board input, Board solvedBoard)
{
	bool rightCol = false;
	for (int i = 0; i < 3; i++)
	{
		if (input.board[row][col] == solvedBoard.board[row][i])
			rightCol = true;
	}
	return rightCol;
}





void aStarSolve::insertChildren(Board bIn, AvlTree<Board> &thetree)
{
	int prevMove = bIn.prevMove;
	Board solvedBoard;
	solvedBoard.makeBoard(0);

	for (int i = 0; i < 12; i++)
	{
		Board b(bIn);
		b.writeHistory(b.move(i));
		b.prevMove = bIn.index;
		b.index = -1;
		b.generation = bIn.generation + 1;
		b.costSoFar = b.costSoFar + 1;
		b.priority = getPriority(b,solvedBoard) + b.costSoFar;
		thetree.insert(b);
	}

}

