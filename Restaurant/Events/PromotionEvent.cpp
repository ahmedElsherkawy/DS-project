#include "PromotionEvent.h"



PromotionEvent::PromotionEvent(int eTime, int oID, double m) :Event(eTime, oID)
{
	ExMoney = m;
}

void PromotionEvent::Execute(Restaurant* pRest) {

}

PromotionEvent::~PromotionEvent()
{
}
