#include "Board.h"
#include "Queue.h"

boardqueue::boardqueue()
{
	back = front = NULL;
}

void boardqueue::add(Board b)
{
	Board *temp = new Board(b);
	temp->writeHistory(b.getHistory());
	temp->generation = b.generation;
	temp->prevMove = b.prevMove;
	temp->next = NULL;

	if (front == NULL)
	{
		front = back = temp;
		back->next = NULL;
	}
	else
	{
		back->next = temp;
		//back = back->next;
		back = temp;
		back->next = NULL;
	}
}
Board* boardqueue::remove()
{
	Board *tmpFront;
	
	if (front == NULL)
		return NULL;
	else
	{
		tmpFront = front;
		tmpFront->writeHistory(front->getHistory());
		tmpFront->generation = front->generation;
		tmpFront->prevMove = front->prevMove;

		//this is where the problem is
		front = front->next;
		//delete(tmpFront);
		return tmpFront;
	}
	//front = front->next;
	

}


