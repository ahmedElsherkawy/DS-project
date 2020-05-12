#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;
#include<fstream>
#include"..\Events\CancellationEvent.h"
#include"..\Events\PromotionEvent.h"
#include "Restaurant.h"
#include "..\Events\ArrivalEvent.h"


Restaurant::Restaurant()
{
	pGUI = NULL;
}

void Restaurant::RunSimulation()
{
	pGUI = new GUI;
	PROG_MODE	mode = pGUI->getGUIMode();

	switch (mode)	//Add a function for each mode in next phases
	{
	case MODE_INTR:
		//SimulationFunc_INTR();
		InterActiveMode();
		break; //mode to use
	case MODE_STEP:
		StepByStepMode();
		break;
	case MODE_SLNT:
		SilentMode();
		break;

	};

}



//////////////////////////////////  Event handling functions   /////////////////////////////

//Executes ALL events that should take place at current timestep
void Restaurant::ExecuteEvents(int CurrentTimeStep)
{
	Event* pE;
	while (EventsQueue.peekFront(pE))	//as long as there are more events
	{
		if (pE->getEventTime() > CurrentTimeStep)	//no more events at current timestep
			return;

		pE->Execute(this);
		EventsQueue.dequeue(pE);	//remove event from the queue
		delete pE;		//deallocate event object from memory
	}

}


Restaurant::~Restaurant()
{
	if (pGUI)
		delete pGUI;
}
void Restaurant::SimulationFunc_INTR() {
	/*pGUI->PrintMessage("Write Input File Name:");
	string fileName = pGUI->GetString();
	//get file name
	LoadingFunc(fileName);
	//call loading function
	int timeStep = 1;
	//make time var   int timestep=1;
	while (!EventsQueue.isEmpty() || inServiceOrders.isempty()==false)
	{
		//print current timestep
		//char ts[10];
		//itoa(timeStep, ts, 10); // 3awz as2l de bt3ml eh
		//pGUI->PrintMessage("TS=");
		//pGUI->printInfo(ts);

		
		Event* E;
		EventsQueue.peekFront(E);
		while (E->getEventTime() == timeStep)
		{
			EventsQueue.dequeue(E);
				E->Execute(this);
			//EventsQueue.dequeue(E);	//remove event from the queue
			delete E;		//deallocate event object from memory
			EventsQueue.peekFront(E);
		}


		/*if (WaitingNormal.isempty()==false)
		{
			Order* ON=nullptr;
			WaitingNormal.pop(ON);
			AddtoServiceList(ON);
			//delete ON;
		}
		if(WaitingVIP.isempty()!=true)
		{
			Order* OV=nullptr;
			WaitingVIP.pop(OV);
			AddtoServiceList(OV);
			//delete OV;
		}
		if(WaitingVegan.isEmpty()!=true)
		{
			Order* OG;
			WaitingVegan.dequeue(OG);
			AddtoServiceList(OG);
			//delete OG;
		}



		/*Event * E;
		EventsQueue.peekFront(E);
		while (E->getEventTime() == timeStep)
		{
			EventsQueue.dequeue(E);
			E->Execute(this);
			//EventsQueue.dequeue(E);	//remove event from the queue
			delete E;		//deallocate event object from memory
			EventsQueue.peekFront(E);
		}*/

		/*if(timeStep % 5 == 0)
		{
			for (int i = 0; i < 3; i++)
			{
				if (inServiceOrders.isempty() == false)
				{
					Order* OF=nullptr;
					inServiceOrders.pop(OF);
					AddtofinishedOrders(OF);
				}
			}
		}*/
		/*AssignNormal(timeStep);
		AssignVIP(timeStep);
		AssignVigen(timeStep);

		MoveToService(timeStep);

		MoveToFinished(timeStep);
		PromoteNormal(timeStep);




		FillDrawingList();
		pGUI->UpdateInterface();

		char ts[10];
		itoa(timeStep, ts, 10);
		char CN[10];
		itoa(getCooksNormal(), CN, 10);
		char CG[10];
		itoa(getCooksVigen(), CG, 10);
		char CV[10];
		itoa(getCooksVIP(), CV, 10);
		char WN[10];
		itoa(getNumberWaitingNormal(), WN, 10);
		char WG[10];
		itoa(getNumberWaitingVigen(), WG, 10);
		char WV[10];
		itoa(getNumberWaitingVIP(), WV, 10);
		char OC[10];
		itoa(getNumberofCooks(), OC, 10);
		char OT[10];
		itoa(getNumberWaitingVIP()+getNumberWaitingVigen()+getNumberWaitingNormal(), OT, 10);
		pGUI->printInfo(ts, CN, CG, CV,WN,WG,WV,OC,OT);

		/*for (int i = 0; i < C_count; i++)
			pGUI->AddToDrawingList(&pC[i]);

		//Let's add ALL randomly generated Ordes to GUI::DrawingList
		int size = 0;
		Order** Demo_Orders_Array = DEMO_Queue.toArray(size);

		for (int i = 0; i < size; i++)
		{
			pOrd = Demo_Orders_Array[i];
			pGUI->AddToDrawingList(pOrd);
		}*/

		/*timeStep++;
		//pGUI->waitForClick();
		pGUI->ResetDrawingList();
		pGUI->waitForClick();
		




	}*/

	//logic
	//call filldrawinglist
	//call updateinterface
	
}
void Restaurant::FillDrawingList()
{
	// function to use -->> 


	Order* pOrd;
	//example for queues
	int size = 0;

	Order** Demo_Orders_Array = finishedOrders.toArray(size);

	for (int i = 0; i < size; i++)
	{
		pOrd = Demo_Orders_Array[i];
		pGUI->AddToDrawingList(pOrd);
	}

	int waitingVigenSize = 0;
	Order ** Waiting_Vegan_Orders = WaitingVegan.toArray(waitingVigenSize);
	setNumberWaitingVigen(waitingVigenSize);

	for (int i = 0; i < waitingVigenSize; i++)
	{
		pOrd = Waiting_Vegan_Orders[i];
		pGUI->AddToDrawingList(pOrd);
	}
	////////////////////////////////////////////////
	int size1 = 0, size2 = 0, size3 = 0;
	Cook** Normal_Cock_Array = freeNormalCooks.toArray(size1);
	setCooksNormal(size1);
	Cook** Vegan_Cock_Array = freeVegancooks.toArray(size2);
	setCooksVigen(size2);
	Cook** VIP_Cock_Array = freeVIPCooks.toArray(size3);
	setCooksVIP(size3);
	int C_count = size1 + size2 + size3;
	setNumberofCooks(C_count);
	Cook** pCc = new Cook*[C_count];

	for (int i = 0; i < size1; i++)
	{
		pCc[i] = Normal_Cock_Array[i];
	}
	for (int i = 0; i < size2; i++)
	{
		pCc[size1+i] = Vegan_Cock_Array[i];
	}
	for (int i = 0; i < size3; i++)
	{
		pCc[size1+size2+i] = VIP_Cock_Array[i];
	}


	for (int i = 0; i < C_count; i++)
		pGUI->AddToDrawingList(pCc[i]);



	int waitingNormalSize = 0;
	Order** Waiting_Normal_Orders = WaitingNormal.toArray(waitingNormalSize);
	setNumberWaitingNormal(waitingNormalSize);
	for (int i = 0; i < waitingNormalSize; i++)
	{
		pOrd = Waiting_Normal_Orders[i];
		pGUI->AddToDrawingList(pOrd);
	}
	////////////////////////////////////////////////
	int waitingVIPSize = 0;
	Order** Waiting_VIP_Orders = WaitingVIP.toArray(waitingVIPSize);
	setNumberWaitingVIP(waitingVIPSize);
	for (int i = 0; i < waitingVIPSize; i++)
	{
		pOrd = Waiting_VIP_Orders[i];
		pGUI->AddToDrawingList(pOrd);
	}
	////////////////////////////////////////////////
	int serviceSize = 0;
	Order** service_Orders = inServiceOrders.toArray(serviceSize);

	for (int i = 0; i < serviceSize; i++)
	{
		pOrd = service_Orders[i];
		pGUI->AddToDrawingList(pOrd);
	}
	////////////////////////////////////////////////
	//This function should be implemented in phase1
	//It should add ALL orders and Cooks to the drawing list
	//It should get orders from orders lists/queues/stacks/whatever (same for Cooks)
	//To add orders it should call function void GUI::AddToDrawingList(Order* pOrd);
	//To add Cooks it should call function  void GUI::AddToDrawingList(Cook* pCc);

	// function to use -->>  pGUI->AddToDrawingList()

	//example for queues
	/*
	Order** Demo_Orders_Array = DEMO_Queue.toArray(size);

	for (int i = 0; i < size; i++)
	{
		pOrd = Demo_Orders_Array[i];
		pGUI->AddToDrawingList(pOrd);
	}

	*/


	//This function should be implemented in phase1
	//It should add ALL orders and Cooks to the drawing list
	//It should get orders from orders lists/queues/stacks/whatever (same for Cooks)
	//To add orders it should call function  void GUI::AddToDrawingList(Order* pOrd);
	//To add Cooks it should call function  void GUI::AddToDrawingList(Cook* pCc);

}
///done by caroline
void Restaurant::Addtowaitingvegan(Order *pOrd)
{
	WaitingVegan.enqueue(pOrd);
}
void Restaurant::Addtowaitingnormal(Order *pOrd)
{
	WaitingNormal.InsertSorted(pOrd,2);
}
void Restaurant::Addtowaitingvip(Order *pOrd)
{
    WaitingVIP.InsertSorted(pOrd,1);
	
}

void Restaurant::AddtofinishedOrders(Order* pOrd)
{
	finishedOrders.enqueue(pOrd);
	pOrd->setStatus(DONE);
}

////done by moataz
void Restaurant::AddtoServiceList(Order* pOrd)
{
	inServiceOrders.InsertSorted(pOrd, 3);
	pOrd->setStatus(SRV);
}


Order * Restaurant::Removefromwaitingnormal(int ordId)
{
	Order *pOrd;
	WaitingNormal.DeleteOrder(ordId,pOrd);
	return pOrd;
}

///done by ola
void Restaurant::Cancellation(int ordId) {
	Order* ord;
	WaitingNormal.DeleteOrder(ordId, ord);
}

/// done by ola
void Restaurant::addToEventQueue(Event* E) {
	EventsQueue.enqueue(E);
}

///done by ola
void Restaurant::LoadingFunc(string address) {
	fstream input_file;
	input_file.open(address);
	int cookN, cookG, cookV, sn_min, sn_max, sg_min, sg_max, sv_min, sv_max, BO
		, BN_min, BN_max, BG_min,BG_max ,BV_min ,BV_max,  RstPrd, pro,VIP_wt;
	double InjProp;
	input_file >> cookN >> cookG >> cookV >> sn_min >> sn_max >> sg_min >> sg_max >> sv_min >> sv_max>> BO
		>> BN_min>> BN_max>> BG_min>> BG_max>> BV_min >>BV_max >> InjProp>> RstPrd>> pro>>VIP_wt;
	//cout << cookN << cookG << cookV << sn << sg << sv << BO << BN << BG << BV;
	Cook* NC;
	auto_pro = pro;
	VIP_WT = VIP_wt;
	Inj_Prop = InjProp;
	for (int i = 1; i < 1+cookN; i++) {
		NC = new Cook(i, TYPE_NRM_COOK, rand() % (sn_max - sn_min + 1) + sn_min, BO, rand() % (BN_max - BN_min + 1) + BN_min, RstPrd);
		freeNormalCooks.enqueue(NC);
	}

	for (int i = cookN+1; i < 1+cookN + cookG; i++) {
		NC = new Cook(i, TYPE_VGAN_COOK, rand() % (sg_max - sg_min + 1) + sg_min, BO, rand() % (BG_max - BG_min + 1) + BG_min,  RstPrd);
		freeVegancooks.enqueue(NC);
	}

	for (int i = cookG + cookN+1; i < 1+cookN + cookG + cookV; i++) {
		NC = new Cook(i, TYPE_VIP_COOK, rand() % (sv_max - sv_min + 1) + sv_min, BO, rand() % (BV_max - BV_min + 1) + BV_min,  RstPrd);
		freeVIPCooks.enqueue(NC);
	}

	int nevents;
	char eventtype, ordtype;
	int t, id, s;
	double m;
	input_file >> nevents;
	for (int i = 0; i < nevents; i++) {
		Event* ER;
		input_file >> eventtype;
		//cout << eventtype;
		if (eventtype == 'R') {
			input_file >> ordtype >> t >> id >> s >> m;
			if (ordtype == 'N')
				ER = new ArrivalEvent(t, id, TYPE_NRM, s, m);
			else if (ordtype == 'G')
				ER = new ArrivalEvent(t, id, TYPE_VGAN, s, m);
			else if (ordtype == 'V')
				ER = new ArrivalEvent(t, id, TYPE_VIP, s, m);
			EventsQueue.enqueue(ER);
		}
		else if (eventtype == 'X') {
			input_file >> t >> id;
			ER = new CancellationEvent(t, id);
			EventsQueue.enqueue(ER);
		}
		else if (eventtype == 'P') {
			input_file >> t >> id >> m;
			ER = new PromotionEvent(t, id, m);
			EventsQueue.enqueue(ER);
		}
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////
/// ==> 
///  DEMO-related functions. Should be removed in phases 1&2

//Begin of DEMO-related functions

//This is just a demo function for project introductory phase
//It should be removed starting phase 1
/*void Restaurant::Just_A_Demo()
{

	//
	// THIS IS JUST A DEMO FUNCTION
	// IT SHOULD BE REMOVED IN PHASE 1 AND PHASE 2

	int EventCnt;
	Order* pOrd;
	Event* pEv;
	srand(time(NULL));

	pGUI->PrintMessage("Just a Demo. Enter EVENTS Count(next phases should read I/P filename):");
	EventCnt = atoi(pGUI->GetString().c_str());	//get user input as a string then convert to integer

	pGUI->PrintMessage("Generating Events randomly... In next phases, Events should be loaded from a file...CLICK to continue");
	pGUI->waitForClick();

	//Just for sake of demo, generate some cooks and add them to the drawing list
	//In next phases, Cooks info should be loaded from input file
	int C_count = 12;
	Cook* pC = new Cook[C_count];
	int cID = 1;

	for (int i = 0; i < C_count; i++)
	{
		cID += (rand() % 15 + 1);
		pC[i].setID(cID);
		pC[i].setType((ORD_TYPE)(rand() % TYPE_CNT));
	}



	int EvTime = 0;

	int O_id = 1;

	//Create Random events and fill them into EventsQueue
	//All generated event will be "ArrivalEvents" for the demo
	for (int i = 0; i < EventCnt; i++)
	{
		O_id += (rand() % 4 + 1);
		int OType = rand() % TYPE_CNT;	//Randomize order type		
		EvTime += (rand() % 5 + 1);			//Randomize event time
		pEv = new ArrivalEvent(EvTime, O_id, (ORD_TYPE)OType);
		EventsQueue.enqueue(pEv);

	}

	// --->   In next phases, no random generation is done
	// --->       EventsQueue should be filled from actual events loaded from input file





	//Now We have filled EventsQueue (randomly)
	int CurrentTimeStep = 1;


	//as long as events queue is not empty yet
	while (!EventsQueue.isEmpty())
	{
		//print current timestep
		char timestep[10];
		itoa(CurrentTimeStep, timestep, 10);
		pGUI->PrintMessage(timestep);


		//The next line may add new orders to the DEMO_Queue
		ExecuteEvents(CurrentTimeStep);	//execute all events at current time step


/////////////////////////////////////////////////////////////////////////////////////////
		/// The next code section should be done through function "FillDrawingList()" once you
		/// decide the appropriate list type for Orders and Cooks

		//Let's add ALL randomly generated Cooks to GUI::DrawingList
		for (int i = 0; i < C_count; i++)
			pGUI->AddToDrawingList(&pC[i]);

		//Let's add ALL randomly generated Ordes to GUI::DrawingList
		int size = 0;
		Order** Demo_Orders_Array = DEMO_Queue.toArray(size);

		for (int i = 0; i < size; i++)
		{
			pOrd = Demo_Orders_Array[i];
			pGUI->AddToDrawingList(pOrd);
		}
		/////////////////////////////////////////////////////////////////////////////////////////

		pGUI->UpdateInterface();
		Sleep(1000);
		CurrentTimeStep++;	//advance timestep
		pGUI->ResetDrawingList();
	}

	delete[]pC;


	pGUI->PrintMessage("generation done, click to END program");
	pGUI->waitForClick();


}
////////////////
*/
/*void Restaurant::AddtoDemoQueue(Order* pOrd)
{
	DEMO_Queue.enqueue(pOrd);
}

/// ==> end of DEMO-related function
//////////////////////////////////////////////////////////////////////////////////////////////
*/
//// all of below done by moataz

int Restaurant::getNumberofCooks() {
	return NumberofCooks;
}

int Restaurant::getNumberWaitingNormal(){
	return NumberofWaitingNormal;
}

int Restaurant::getNumberWaitingVigen() {
	return NumberofWaitingVigen;
}

int Restaurant::getNumberWaitingVIP() {
	return NumberofWaitingVIP;
}

void Restaurant::setNumberofCooks(int x)
{
	NumberofCooks = x;
}

void Restaurant::setNumberWaitingNormal(int x) { NumberofWaitingNormal = x; }

void Restaurant::setNumberWaitingVigen(int x) { NumberofWaitingVigen = x; }

void Restaurant::setNumberWaitingVIP(int x) { NumberofWaitingVIP = x; }

int Restaurant::getCooksNormal() { return CooksNormal; }

int Restaurant::getCooksVigen() { return CooksVigen; }

int Restaurant::getCooksVIP() { return CooksVIP; }

void Restaurant::setCooksNormal(int x) { CooksNormal = x; }

void Restaurant::setCooksVigen(int x) { CooksVigen = x; }

void Restaurant::setCooksVIP(int x) { CooksVIP = x; }


///==============================================================
	///added by moataz for simulation
//TYPE_NRM,	//normal order
//TYPE_VGAN,	//vegan
//TYPE_VIP

void Restaurant::AssignVIP(int t)
{
	Order * ordToAssign;
	Cook* cookToAssign;
	while (!WaitingVIP.isempty()) {
        //WaitingVIP.peek(ordToAssign);
		if (!freeVIPCooks.isEmpty()) {
			WaitingVIP.pop(ordToAssign);
			freeVIPCooks.dequeue(cookToAssign);
			//set waiting time
			ordToAssign->SetWaitingTime(t);
			//set service time
			ordToAssign->SetServiceTime(cookToAssign);
			//set finish time
			ordToAssign->SetFinishTime();
			inServiceOrders.InsertSorted(ordToAssign, 3);//sort by finish time
			//set finish cooking(service) time
			cookToAssign->setFinishService(ordToAssign);
			// increase number of orders
			cookToAssign->setNumberOfOrders();
			//set the type of the order
			cookToAssign->setType(TYPE_VIP);
			busyCooks.InsertSorted(cookToAssign, 1);// sort by cooking(serving) time
	
		}
		else if (!freeNormalCooks.isEmpty()) {
			WaitingVIP.pop(ordToAssign);
			freeNormalCooks.dequeue(cookToAssign);
			//set waiting time
			ordToAssign->SetWaitingTime(t);
			//set service time
			ordToAssign->SetServiceTime(cookToAssign);
			//set finish time
			ordToAssign->SetFinishTime();
			inServiceOrders.InsertSorted(ordToAssign, 3);//sort by finish time
			//set finish cooking(service) time
			cookToAssign->setFinishService(ordToAssign);
			// increase number of orders
			cookToAssign->setNumberOfOrders();
			//set the type of the order
			cookToAssign->setType(TYPE_VIP);
			busyCooks.InsertSorted(cookToAssign, 1);// sort by cooking(serving) time
		}else if(!freeVegancooks.isEmpty()){
			WaitingVIP.pop(ordToAssign);
			freeVegancooks.dequeue(cookToAssign);
			//set waiting time
			ordToAssign->SetWaitingTime(t);
			//set service time
			ordToAssign->SetServiceTime(cookToAssign);
			//set finish time
			ordToAssign->SetFinishTime();
			inServiceOrders.InsertSorted(ordToAssign, 3);//sort by finish time
			//set finish cooking(service) time
			cookToAssign->setFinishService(ordToAssign);
			// increase number of orders
			cookToAssign->setNumberOfOrders();
			//set the type of the order
			cookToAssign->setType(TYPE_VIP);
			busyCooks.InsertSorted(cookToAssign, 1);// sort by cooking(serving) time
		}
	}

}
void Restaurant::AssignVigen(int t)
{
	Order * ordToAssign;
	Cook* cookToAssign;
	while (!WaitingVegan.isEmpty()) {

		if (!freeVegancooks.isEmpty()) {
			WaitingVegan.dequeue(ordToAssign);
			freeVegancooks.dequeue(cookToAssign);
			//set waiting time
			ordToAssign->SetWaitingTime(t);
			//set service time
			ordToAssign->SetServiceTime(cookToAssign);
			//set finish time
			ordToAssign->SetFinishTime();
			inServiceOrders.InsertSorted(ordToAssign, 3);//sort by finish time
			//set finish cooking(service) time
			cookToAssign->setFinishService(ordToAssign);
			// increase number of orders
			cookToAssign->setNumberOfOrders();
			//set the type of the order
			cookToAssign->setType(TYPE_VGAN);
			busyCooks.InsertSorted(cookToAssign, 1);// sort by cooking(serving) time

		}
	}
}
void Restaurant::AssignNormal(int t)
{
	Order * ordToAssign;
	Cook* cookToAssign;
	while (!WaitingNormal.isempty()) {

		if (!freeNormalCooks.isEmpty()) {
			WaitingNormal.pop(ordToAssign);
			freeNormalCooks.dequeue(cookToAssign);
			//set waiting time
			ordToAssign->SetWaitingTime(t);
			//set service time
			ordToAssign->SetServiceTime(cookToAssign);
			//set finish time
			ordToAssign->SetFinishTime();
			inServiceOrders.InsertSorted(ordToAssign, 3);//sort by finish time
			//set finish cooking(service) time
			cookToAssign->setFinishService(ordToAssign);
			// increase number of orders
			cookToAssign->setNumberOfOrders();
			//set the type of the order
			cookToAssign->setType(TYPE_NRM);
			busyCooks.InsertSorted(cookToAssign, 1);// sort by cooking(serving) time

		}else if (!freeVIPCooks.isEmpty()) {
			WaitingNormal.pop(ordToAssign);
			freeVIPCooks.dequeue(cookToAssign);
			//set waiting time
			ordToAssign->SetWaitingTime(t);
			//set service time
			ordToAssign->SetServiceTime(cookToAssign);
			//set finish time
			ordToAssign->SetFinishTime();
			inServiceOrders.InsertSorted(ordToAssign, 3);//sort by finish time
			//set finish cooking(service) time
			cookToAssign->setFinishService(ordToAssign);
			// increase number of orders
			cookToAssign->setNumberOfOrders();
			//set the type of the order
			cookToAssign->setType(TYPE_NRM);
			busyCooks.InsertSorted(cookToAssign, 1);// sort by cooking(serving) time

		}
	}
}

//void Restaurant::MoveToService(int t)
//{
//}

//phase 2 Caroline
void Restaurant::MoveToFinished(int t)
{
	Order * finishedord;
	Cook * finishedcook;
	busyCooks.peek(finishedcook);
	while (finishedcook->getFinishService()==t)
	{
		inServiceOrders.pop(finishedord);
		finishedOrders.enqueue(finishedord);
		busyCooks.pop(finishedcook);
		if(!finishedcook->isBreak())
		{
			if (finishedcook->getCookType()==TYPE_NRM_COOK)
				freeNormalCooks.enqueue(finishedcook);
			else if(finishedcook->getCookType()==TYPE_VGAN_COOK)
				freeVegancooks.enqueue(finishedcook);
			else
				freeVIPCooks.enqueue(finishedcook);
		}
		else
		{
			finishedcook->setFinishBreak(t);
			inBreakCooks.InsertSorted(finishedcook,2);
		}
	}
	Cook * finbreakcook;
	inBreakCooks.peek(finbreakcook);
	while (finbreakcook->getFinishBreak()==t)
	{
		inBreakCooks.pop(finbreakcook);
		if (finbreakcook->getCookType()==TYPE_NRM_COOK)
				freeNormalCooks.enqueue(finbreakcook);
			else if(finbreakcook->getCookType()==TYPE_VGAN_COOK)
				freeVegancooks.enqueue(finbreakcook);
			else
				freeVIPCooks.enqueue(finbreakcook);
	}
}
void Restaurant::PromoteNormal(int t)
{

}
////done by moataz
void Restaurant::checkUrgent(int t)
{
	Order* ordToAssign;
	if (!WaitingVIP.isempty())
	{
		int waitingVIPSize = 0;
		Order** Waiting_VIP_Orders = WaitingVIP.toArray(waitingVIPSize);
		for (int i = 0; i < waitingVIPSize; i++)
		{
			if (t - Waiting_VIP_Orders[i]->GetArrivalTime() >= VIP_WT)
			{
				assigntUrgent(Waiting_VIP_Orders[i], t);
			}
		}
	}
}

//done by moataz 
////
void Restaurant::assigntUrgent(Order* ordToAssign, int t)
{
	Cook* cookToAssign;
		//WaitingVIP.peek(ordToAssign);
		if (!freeVIPCooks.isEmpty()) {
			//WaitingVIP.pop(O);
			freeVIPCooks.dequeue(cookToAssign);
			//set waiting time
			ordToAssign->SetWaitingTime(t);
			//set service time
			ordToAssign->SetServiceTime(cookToAssign);
			//set finish time
			ordToAssign->SetFinishTime();
			inServiceOrders.InsertSorted(ordToAssign, 3);//sort by finish time
			//set finish cooking(service) time
			cookToAssign->setFinishService(ordToAssign);
			// increase number of orders
			cookToAssign->setNumberOfOrders();
			//set the type of the order
			cookToAssign->setType(TYPE_VIP);
			busyCooks.InsertSorted(cookToAssign, 1);// sort by cooking(serving) time

		}
		else if (!freeNormalCooks.isEmpty()) {
			freeNormalCooks.dequeue(cookToAssign);
			//set waiting time
			ordToAssign->SetWaitingTime(t);
			//set service time
			ordToAssign->SetServiceTime(cookToAssign);
			//set finish time
			ordToAssign->SetFinishTime();
			inServiceOrders.InsertSorted(ordToAssign, 3);//sort by finish time
			//set finish cooking(service) time
			cookToAssign->setFinishService(ordToAssign);
			// increase number of orders
			cookToAssign->setNumberOfOrders();
			//set the type of the order
			cookToAssign->setType(TYPE_VIP);
			busyCooks.InsertSorted(cookToAssign, 1);// sort by cooking(serving) time
		}
		else if (!freeVegancooks.isEmpty()) {
			freeVegancooks.dequeue(cookToAssign);
			//set waiting time
			ordToAssign->SetWaitingTime(t);
			//set service time
			ordToAssign->SetServiceTime(cookToAssign);
			//set finish time
			ordToAssign->SetFinishTime();
			inServiceOrders.InsertSorted(ordToAssign, 3);//sort by finish time
			//set finish cooking(service) time
			cookToAssign->setFinishService(ordToAssign);
			// increase number of orders
			cookToAssign->setNumberOfOrders();
			//set the type of the order
			cookToAssign->setType(TYPE_VIP);
			busyCooks.InsertSorted(cookToAssign, 1);// sort by cooking(serving) time
		}
		else if (!busyCooks.isempty())
		{
			busyCooks.pop(cookToAssign);
			//set waiting time
			ordToAssign->SetWaitingTime(t);
			//set service time
			ordToAssign->SetServiceTime(cookToAssign);
			//set finish time
			ordToAssign->SetFinishTime();
			inServiceOrders.InsertSorted(ordToAssign, 3);//sort by finish time
			//set finish cooking(service) time
			cookToAssign->setFinishService(ordToAssign);
			// increase number of orders
			cookToAssign->setNumberOfOrders();
			//set the type of the order
			cookToAssign->setType(TYPE_VIP);
			busyCooks.InsertSorted(cookToAssign, 1);// sort by cooking(serving) time
		}
		else if(!injCooks.isempty())
		{
			injCooks.pop(cookToAssign);
			//set waiting time
			ordToAssign->SetWaitingTime(t);
			//set service time
			ordToAssign->SetServiceTime(cookToAssign);
			//set finish time
			ordToAssign->SetFinishTime();
			inServiceOrders.InsertSorted(ordToAssign, 3);//sort by finish time
			//set finish cooking(service) time
			cookToAssign->setFinishService(ordToAssign);
			// increase number of orders
			cookToAssign->setNumberOfOrders();
			//set the type of the order
			cookToAssign->setType(TYPE_VIP);
			busyCooks.InsertSorted(cookToAssign, 1);// sort by cooking(serving) time
			/////////////fadl l part bta3 l speed
		}
}

///=========================================================================
//modes done by moataz
void Restaurant::InterActiveMode()
{
	pGUI->PrintMessage("Write Input File Name:");
	string fileName = pGUI->GetString();
	LoadingFunc(fileName);
	int timeStep = 1;
	while (!EventsQueue.isEmpty() || inServiceOrders.isempty() == false)
	{



		Event* E;
		EventsQueue.peekFront(E);
		while (E->getEventTime() == timeStep)
		{
			EventsQueue.dequeue(E);
			E->Execute(this);
			delete E;		
			EventsQueue.peekFront(E);
		}


		
		AssignVIP(timeStep);
		AssignVigen(timeStep);
		AssignNormal(timeStep);

		//MoveToService(timeStep);

		MoveToFinished(timeStep);
		PromoteNormal(timeStep);




		FillDrawingList();
		pGUI->UpdateInterface();

		char ts[10];
		itoa(timeStep, ts, 10);
		char CN[10];
		itoa(getCooksNormal(), CN, 10);
		char CG[10];
		itoa(getCooksVigen(), CG, 10);
		char CV[10];
		itoa(getCooksVIP(), CV, 10);
		char WN[10];
		itoa(getNumberWaitingNormal(), WN, 10);
		char WG[10];
		itoa(getNumberWaitingVigen(), WG, 10);
		char WV[10];
		itoa(getNumberWaitingVIP(), WV, 10);
		char OC[10];
		itoa(getNumberofCooks(), OC, 10);
		char OT[10];
		itoa(getNumberWaitingVIP() + getNumberWaitingVigen() + getNumberWaitingNormal(), OT, 10);
		pGUI->printInfo(ts, CN, CG, CV, WN, WG, WV, OC, OT);

		timeStep++;
		
		pGUI->ResetDrawingList();
		pGUI->waitForClick();





	}
}
void Restaurant::StepByStepMode()
{
	pGUI->PrintMessage("Write Input File Name:");
	string fileName = pGUI->GetString();
	LoadingFunc(fileName);
	int timeStep = 1;
	while (!EventsQueue.isEmpty() || inServiceOrders.isempty() == false)
	{



		Event* E;
		EventsQueue.peekFront(E);
		while (E->getEventTime() == timeStep)
		{
			EventsQueue.dequeue(E);
			E->Execute(this);
			delete E;
			EventsQueue.peekFront(E);
		}


		
		AssignVIP(timeStep);
		AssignVigen(timeStep);
		AssignNormal(timeStep);

		//MoveToService(timeStep);

		MoveToFinished(timeStep);
		PromoteNormal(timeStep);




		FillDrawingList();
		pGUI->UpdateInterface();

		char ts[10];
		itoa(timeStep, ts, 10);
		char CN[10];
		itoa(getCooksNormal(), CN, 10);
		char CG[10];
		itoa(getCooksVigen(), CG, 10);
		char CV[10];
		itoa(getCooksVIP(), CV, 10);
		char WN[10];
		itoa(getNumberWaitingNormal(), WN, 10);
		char WG[10];
		itoa(getNumberWaitingVigen(), WG, 10);
		char WV[10];
		itoa(getNumberWaitingVIP(), WV, 10);
		char OC[10];
		itoa(getNumberofCooks(), OC, 10);
		char OT[10];
		itoa(getNumberWaitingVIP() + getNumberWaitingVigen() + getNumberWaitingNormal(), OT, 10);
		pGUI->printInfo(ts, CN, CG, CV, WN, WG, WV, OC, OT);
		
		
		Sleep(1000);
		timeStep++;

		pGUI->ResetDrawingList();
		//pGUI->waitForClick();




	}
}
void Restaurant::SilentMode() 
{
	pGUI->PrintMessage("Write Input File Name:");
	string fileName = pGUI->GetString();
	LoadingFunc(fileName);
	int timeStep = 1;
	while (!EventsQueue.isEmpty() || inServiceOrders.isempty() == false)
	{



		Event* E;
		EventsQueue.peekFront(E);
		while (E->getEventTime() == timeStep)
		{
			EventsQueue.dequeue(E);
			E->Execute(this);
			delete E;
			EventsQueue.peekFront(E);
		}


		
		AssignVIP(timeStep);
		AssignVigen(timeStep);
        AssignNormal(timeStep);
		//MoveToService(timeStep);

		MoveToFinished(timeStep);
		PromoteNormal(timeStep);




		/*FillDrawingList();
		pGUI->UpdateInterface();

		char ts[10];
		itoa(timeStep, ts, 10);
		char CN[10];
		itoa(getCooksNormal(), CN, 10);
		char CG[10];
		itoa(getCooksVigen(), CG, 10);
		char CV[10];
		itoa(getCooksVIP(), CV, 10);
		char WN[10];
		itoa(getNumberWaitingNormal(), WN, 10);
		char WG[10];
		itoa(getNumberWaitingVigen(), WG, 10);
		char WV[10];
		itoa(getNumberWaitingVIP(), WV, 10);
		char OC[10];
		itoa(getNumberofCooks(), OC, 10);
		char OT[10];
		itoa(getNumberWaitingVIP() + getNumberWaitingVigen() + getNumberWaitingNormal(), OT, 10);
		pGUI->printInfo(ts, CN, CG, CV, WN, WG, WV, OC, OT);

		timeStep++;

		pGUI->ResetDrawingList();*/
		timeStep++;
	}
}
