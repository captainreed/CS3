#pragma once
#include "Board.h"
#include "Queue.h"
#include "AvlTree.h"

class aStarSolve
{
public:
	AvlTree<Board> theTree;
	aStarSolve(Board &input);
	float getPriority(Board &input, Board solvedBoard);
	void solve(Board input);
	~aStarSolve();
private:
	bool correctRow(int row, int col, Board input, Board solvedBoard);
	bool correctCol(int row, int col, Board input, Board solvedBoard);
	void insertChildren(Board bIn, AvlTree<Board> &thetree);
	
};

