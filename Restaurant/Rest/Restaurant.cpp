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
		SimulationFunc_INTR();
		break; //mode to use
	case MODE_STEP:
		break;
	case MODE_SLNT:
		break;
	case MODE_DEMO:
		Just_A_Demo();

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

	/*string fileName = pGUI->GetString();
	//get file name
	LoadingFunc(fileName);
	//call loading function
	int timeStep = 1;
	//make time var   int timestep=1;
	while (!EventsQueue.isEmpty())
	{
		//print current timestep
		char ts[10];
		itoa(timeStep, ts, 10); // 3awz as2l de bt3ml eh
		pGUI->PrintMessage(ts);

		Event* E;
		EventsQueue.peekFront(E);
		if (E->getEventTime() == timeStep)
		{
			E->Execute(this);
			EventsQueue.dequeue(E);	//remove event from the queue
			delete E;		//deallocate event object from memory
		}



		Order* ON = WaitingNormal.getFirst();
		inServiceOrders.InsertEnd(ON);
		Order* OV = WaitingVIP.getFirst();
		inServiceOrders.InsertEnd(OV);
		Order* OG;
		WaitingVegan.dequeue(OG);
		inServiceOrders.InsertEnd(OG);



	}

	//logic
	//call filldrawinglist
	//call updateinterface
	*/
}
void Restaurant::FillDrawingList()
{
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
void Restaurant::LoadingFunc(char* address) {
	fstream input_file;
	input_file.open(address);
	int cookN, cookG, cookV, sn, sg, sv, BO, BN, BG, BV, pro;
	input_file >> cookN >> cookG >> cookV >> sn >> sg >> sv >> BO >> BN >> BG >> BV >> pro;
	//cout << cookN << cookG << cookV << sn << sg << sv << BO << BN << BG << BV;
	Cook* NC;

	for (int i = 0; i < cookN; i++) {
		NC = new Cook(i, TYPE_NRM_COOK, sn, BO, BN);
		freeNormalCooks.enqueue(NC);
	}
	for (int i = cookN; i < cookN + cookG; i++) {
		NC = new Cook(i, TYPE_VGAN_COOK, sg, BO, BG);
		freeVegancooks.enqueue(NC);

	}
	for (int i = cookG + cookN; i < cookN + cookG + cookV; i++) {
		NC = new Cook(i, TYPE_VIP_COOK, sv, BO, BV);
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
void Restaurant::Just_A_Demo()
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

void Restaurant::AddtoDemoQueue(Order* pOrd)
{
	DEMO_Queue.enqueue(pOrd);
}

/// ==> end of DEMO-related function
//////////////////////////////////////////////////////////////////////////////////////////////


