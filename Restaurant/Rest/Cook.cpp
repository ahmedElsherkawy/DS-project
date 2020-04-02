#include "Cook.h"


Cook::Cook()
{
}


Cook::~Cook()
{
}

Cook::Cook(int id, ORD_TYPE t, int s,int c, int b) {
	ID = id;
	type = t;
	speed = s;
	capacity = c;
	breaktime = b;
}


int Cook::GetID() const
{
	return ID;
}


ORD_TYPE Cook::GetType() const
{
	return type;
}


void Cook::setID(int id)
{
	ID = id;
}

void Cook::setType(ORD_TYPE t)
{
	type = t;
}


