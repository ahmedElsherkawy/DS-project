#pragma once

#include "..\Defs.h"
#include "Order.h"

#pragma once
class Order;
class Cook
{
	int ID;
	ORD_TYPE type;	//for each order type there is a corresponding type (VIP, Normal, Vegan)
	COOK_TYPE cookType;
	int speed;		//dishes it can prepare in one clock tick (in one timestep)
	//int servicetime;
	/// more data members by ola
	int capacity;   //how many orders then taking a break
	int breaktime;  //how many time steps 

	int finishService;  // at what time step the cook will finish the order assigned to him
	int finishBreak;   // at what time step the cook will finish his break;

public:
	Cook();
	Cook(int, COOK_TYPE, int ,int ,int);
	virtual ~Cook();
	int GetID() const;
	ORD_TYPE GetType() const;
	void setID(int);
	void setType(ORD_TYPE);
	void setCookType(COOK_TYPE);
	COOK_TYPE getCookType();
	void setFinishService(int Ts , Order * ord);// still not ready
	int getFinishService();
	void setFinishBreak(int Ts);
	int getFinishBreak();


	//by caroline
	void setSpeed(int s);
	int GetSpeed()const;
};
