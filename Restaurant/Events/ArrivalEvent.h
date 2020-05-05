#ifndef __ARRIVAL_EVENT_H_
#define __ARRIVAL_EVENT_H_

#include "Event.h"


//class for the arrival event
class ArrivalEvent: public Event
{
	//info about the order ralted to arrival event
	int OrdDistance;	//order distance
	ORD_TYPE OrdType;		//order type: Normal, vegan, VIP	                
	double OrdMoney;	//Total order money
	/// more data members by ola
	int size;

public:
	ArrivalEvent(int eTime, int oID, ORD_TYPE oType);
	//Add more constructors if needed
	ArrivalEvent(int eTime, int oID, ORD_TYPE oType, int s, double m);
	char getType(); ///done br moataz

	virtual void Execute(Restaurant *pRest);	//override execute function

};

#endif