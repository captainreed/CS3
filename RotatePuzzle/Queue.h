#ifndef QUEUE_H
#define QUEUE_H
#include <string>
#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>
#include "Board.h"


class boardqueue
{
public:
	Board * front;
	Board *back;
	boardqueue();
	void add(Board b);
	Board remove();
};
#endif

