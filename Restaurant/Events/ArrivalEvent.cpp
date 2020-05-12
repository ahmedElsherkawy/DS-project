#include "ArrivalEvent.h"
#include "..\Rest\Restaurant.h"


ArrivalEvent::ArrivalEvent(int eTime, int oID, ORD_TYPE oType,int s,double m):Event(eTime, oID)
{
	OrdType = oType;
	size = s;
	OrdMoney = m;
}
ArrivalEvent::ArrivalEvent(int eTime, int oID, ORD_TYPE oType) :Event(eTime, oID)
{
	OrdType = oType;
}
 ///done by moataz
char ArrivalEvent::getType()
{
	return 'A';
}
//done by caroline
void ArrivalEvent::Execute(Restaurant* pRest)
{
	//This function should create an order and fills its data 
	// Then adds it to normal, vegan, or VIP order lists that you will create in phase1

	Order* pOrd = new Order(OrderID,OrdType);
	if (pOrd->GetType()==TYPE_NRM)
	{
		pRest->Addtowaitingnormal(pOrd);
	}
	if (pOrd->GetType()==TYPE_VGAN)
	{
		pRest->Addtowaitingvegan(pOrd);
	}
	if (pOrd->GetType()==TYPE_VIP)
	{
		pRest->Addtowaitingvip(pOrd);
	}
	
	///For the sake of demo, this function will just create an order and add it to DemoQueue
	///Remove the next code lines in phases 1&2
	//Order* pOrd = new Order(OrderID,OrdType);
	//pRest->AddtoDemoQueue(pOrd);
}
