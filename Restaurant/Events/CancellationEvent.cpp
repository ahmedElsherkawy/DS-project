#include "CancellationEvent.h"



CancellationEvent::CancellationEvent(int eTime, int oID):Event(eTime,oID)
{
}

void CancellationEvent::Execute(Restaurant* pRest) {
	pRest->Cancellation(this->OrderID);
}

CancellationEvent::~CancellationEvent()
{
}
