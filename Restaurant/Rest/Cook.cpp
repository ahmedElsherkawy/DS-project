#include "Cook.h"


Cook::Cook()
{
}


Cook::~Cook()
{
}

Cook::Cook(int id, COOK_TYPE t, int s,int c, int b) {
	ID = id;
	cookType = t;
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

void Cook::setCookType(COOK_TYPE t) {
	cookType = t;
}
COOK_TYPE Cook::getCookType() {
	return cookType;
}

void Cook::setFinishService(int Ts, Order * ord) {
	finishService = Ts;// still not finished i am waiting for class order to be ready  
}
int Cook::getFinishService() {
	return finishService;
}
void Cook::setFinishBreak(int Ts) {
	finishBreak = Ts + breaktime;
}
int Cook::getFinishBreak() {
	return finishBreak;
}



///done by caroline
void Cook::setSpeed(int s)
{
	speed = s;
}
int Cook::GetSpeed()const
{
	return speed;
}