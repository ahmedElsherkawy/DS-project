#ifndef __ORDER_H_
#define __ORDER_H_

#include "..\Defs.h"
#include "../Rest/Cook.h"

class Cook;

class Order
{

protected:
	int ID;         //Each order has a unique ID (from 1 --> 999 )
	ORD_TYPE type;		//order type: Normal, vegan, VIP
	ORD_STATUS status;	//waiting, in-service, done
	int Distance;	//The distance (in meters) between the order location and the resturant 
	                
	double totalMoney;	//Total order money

	int ArrTime, ServTime, FinishTime;	//arrival, service start, and finish times
	int WaitingTime;
	//
	// TODO: Add More Data Members As Needed
	// done by caroline
	int size;
	int Priority;

public:
	Order(int ID, ORD_TYPE r_Type);
	virtual ~Order();

	int GetID();

	ORD_TYPE GetType() const;

	void SetDistance(int d);
	int GetDistance() const;

	void setStatus(ORD_STATUS s);
	ORD_STATUS getStatus() const;
	
	//
	// TODO: Add More Member Functions As Needed
	// done by caroline
	

	void SetPriority();
	int GetPriority() const;
	void SetArrivalTime(int AT);
	int GetArrivalTime() const;
	void SetServiceTime(Cook* co);

	int GetServiceTime() const;
	void SetFinishTime();
	int GetFinishTime() const;
	void Settotalmoney(int mo);
	double Gettotalmoney() const;
	void Setsize(double s);
	int Getsize() const;
	void SetWaitingTime(int ts);
	int GetWaitingTime() const;

};

#endif