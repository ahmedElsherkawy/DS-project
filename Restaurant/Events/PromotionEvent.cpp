#include "PromotionEvent.h"
#include "..\Rest\Restaurant.h"



PromotionEvent::PromotionEvent(int eTime, int oID, double m) :Event(eTime, oID)
{
	ExMoney = m;
}

void PromotionEvent::Execute(Restaurant* pRest) {
	
	///done by caroline
	Order* ord;
	Order* pOrd=pRest->Removefromwaitingnormal(this->OrderID);
	if (pOrd) {
		pRest->Addtowaitingvip(pOrd);
	}
}

///done by moataz
char PromotionEvent::getType()
{
	return 'P';
}

PromotionEvent::~PromotionEvent()
{
}
