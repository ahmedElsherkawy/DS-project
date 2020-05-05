#pragma once
#include "..\Events\Event.h"
class PromotionEvent :
	public Event
{
	double ExMoney;
public:
	PromotionEvent(int eTime, int oID,double m);
	void Execute(Restaurant* pRest);
	char getType(); ///done by moataz
	virtual ~PromotionEvent();
};

