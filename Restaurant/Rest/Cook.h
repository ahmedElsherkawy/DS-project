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

	int numderOfOrders; //how many orders did he cook after last break
	bool isbreak; // is this the time to take a break?

	int finishService;  // at what time step the cook will finish the order assigned to him
	int finishBreak;   // at what time step the cook will finish his break;

	bool injured;
	int Rst_Prd; //the rest period if a cook got injured

public:
	Cook();
	Cook(int, COOK_TYPE, int ,int ,int,int);
	virtual ~Cook();
	int GetID() const;
	ORD_TYPE GetType() const;
	void setID(int);
	void setType(ORD_TYPE);
	void setCookType(COOK_TYPE);
	COOK_TYPE getCookType();
	void setFinishService( Order * ord);// still not ready ///now it is ready
	int getFinishService();
	void setFinishBreak(int Ts);
	int getFinishBreak();

	void setNumberOfOrders();
	bool isBreak();

	//by caroline
	void setSpeed(int s);
	int GetSpeed()const;
};
