#pragma once
#include "..\Events\Event.h"
#include"..\Rest\Restaurant.h"
class CancellationEvent:public Event
{
public:
	CancellationEvent(int eTime, int oID);
	void Execute(Restaurant* pRest);
	virtual ~CancellationEvent();
};

