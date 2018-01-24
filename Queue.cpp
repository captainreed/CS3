#include "Board.h"
#include "Queue.h"

boardqueue::boardqueue()
{
	back = front = NULL;
}

void boardqueue::add(Board b)
{
	Board *temp = new Board(b);
	temp->next = NULL;

	if (front == NULL)
	{
		front = back = temp;
		back->next = NULL;
	}
	else
	{
		back->next = temp;
		back = temp;
		back->next = NULL;
	}
}
Board boardqueue::remove()
{
	Board *tmpFront;
	tmpFront = front;
	front = front->next;

	return *tmpFront;
}


