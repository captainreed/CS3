#pragma once
#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>


class Board {
public:
	static const int SIZE = 3;
	int costSoFar;
	int priority;//the cost to solve from current step
	Board *next;
	std::string history;//this will be the string that holds the history of the board
	int generation;//the generation of the board from the original
	int prevMove;//the move that was made to create this board
	void writeHistory(std::string move);//writes the move string to the history string
	std::string getHistory();//returns the history string
	int board[SIZE][SIZE];  // Values of board
	Board(const Board & b);  //Create board from another board
	std::string move(int m);  //m is which move.  Returns string describing move
							  //void makeBoard(int jumbleCt = 0);  //Starting from a perfect board, do jumbleCt moves to alter it
	void makeBoard(int jumbleCt);  //Starting from a perfect board, do jumbleCt moves to alter it
	std::string toString() const;  //return a string which represents the contents of the board
	bool operator==(Board &b);   //Return true if two boards are equal	
	bool operator>(Board &b);
	bool operator<(Board &b);
	bool operator<=(Board &b);
	bool operator>=(Board &b);
	Board() { makeBoard(0); };
	void rotateEast(int row);
	void rotateWest(int row);
	void rotateNorth(int col);
	void rotateSouth(int col);
	void inputBoard(std::string fn);
	void jumble(int ct);  //Do jumble moves to alter board
};
#endif
