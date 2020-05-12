#include "Cook.h"


Cook::Cook()
{
	numderOfOrders = 0;
	isbreak = false;
}


Cook::~Cook()
{
}

Cook::Cook(int id, COOK_TYPE type, int spee,int capa, int b,int rest) {
	ID = id;
	cookType = type;
	speed = spee;
	capacity = capa;
	breaktime = b;
	numderOfOrders = 0;
	isbreak = false;
	injured = false;
	Rst_Prd = rest;
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

void Cook::setFinishService( Order * ord) {
	finishService = ord->GetFinishTime();// still not finished i am waiting for class order to be ready  
	// it is ready

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
//phase 2 ola
void Cook::setNumberOfOrders() {
	numderOfOrders++;
	if (numderOfOrders == capacity) {
		numderOfOrders = 0;
		isbreak = true;

	}
}
bool Cook::isBreak() {
	if (isbreak) {
		isbreak = false;
		return true;
	}
	return isbreak;
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