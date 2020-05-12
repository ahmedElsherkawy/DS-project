#include "Order.h"
#include<cmath>

Order::Order(int id, ORD_TYPE r_Type)
{
	ID = (id>0&&id<1000)?id:0;	//1<ID<999
	type = r_Type;
	status = WAIT;
}

Order::~Order()
{
}

int Order::GetID()
{
	return ID;
}


ORD_TYPE Order::GetType() const
{
	return type;
}


void Order::SetDistance(int d)
{
	Distance = d>0?d:0;
}

int Order::GetDistance() const
{
	return Distance;
}


void Order::setStatus(ORD_STATUS s)
{
	status = s;
}

ORD_STATUS Order::getStatus() const
{
	return status;
}

void Order:: SetArrivalTime(int AT)
{
	ArrTime=AT;
}
int Order:: GetArrivalTime() const
{
	return ArrTime;
}
void Order:: SetServiceTime(Cook* co)
{
	ServTime=ceil(size/(co->GetSpeed()));
}
int Order:: GetServiceTime() const
{
	return ServTime;
}
void Order::SetFinishTime( )
{
	//FinishTime = 4;
	FinishTime=ArrTime+ WaitingTime +ServTime;
}
int Order:: GetFinishTime() const
{
	return FinishTime;
}
void Order:: Settotalmoney(int om)
{
	totalMoney=om;
}
double Order :: Gettotalmoney() const
{
	return totalMoney;
}
void Order:: Setsize(double s)
{
	size=s;
}
int Order:: Getsize() const
{
	return size;
}
void Order::SetPriority()
{
	Priority=(size*totalMoney)/ArrTime;
}

int Order::GetPriority() const
{
	return Priority;
}

void Order::SetWaitingTime(int ts)
{
	WaitingTime = ts - ArrTime;
}
int Order::GetWaitingTime() const
{
	return WaitingTime;
}
