#pragma once

#include "../Defs.h"

#pragma once
class Cook
{
	int ID;
	ORD_TYPE type;	//for each order type there is a corresponding type (VIP, Normal, Vegan)
	int speed;		//dishes it can prepare in one clock tick (in one timestep)
	//int servicetime;
	/// more data members by ola
	int capacity;   //how many orders then taking a break
	int breaktime;  //how many time steps 

public:
	Cook();
	Cook(int, ORD_TYPE, int ,int ,int);
	virtual ~Cook();
	int GetID() const;
	ORD_TYPE GetType() const;
	void setID(int);
	void setType(ORD_TYPE);
	//by caroline
	void setSpeed(int s);
	int GetSpeed()const ;
};
