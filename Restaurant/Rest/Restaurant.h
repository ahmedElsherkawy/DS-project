#ifndef __RESTAURANT_H_
#define __RESTAURANT_H_

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\GUI\GUI.h"
#include "..\Generic_DS\Queue.h"
#include "..\Generic_DS\LinkedList.h"
#include "..\Events\Event.h"


#include "Order.h"

// it is the maestro of the project
class Restaurant  
{	
private:
	GUI *pGUI;
	Queue<Event*> EventsQueue;	//Queue of all events that will be loaded from file
	Queue<Order *> WaitingVegan;
	Queue<Cook *> freeNormalCooks;
	Queue<Cook *> freeVegancooks;
	Queue<Cook *> freeVIPCooks;
	Queue<Order*> finishedOrders;
	LinkedList<Cook*> busyCooks;
	LinkedList<Cook*> inBreakCooks;
	LinkedList<Order*> WaitingNormal;
	LinkedList<Order*> WaitingVIP;
	LinkedList <Order*> inServiceOrders;

	//lists of VIP orders ,normal orders,inservive orders,busy cooks
	

	/// ==> 
	//	DEMO-related members. Should be removed in phases 1&2
	Queue<Order*> DEMO_Queue;	//Important: This is just for demo
	/// ==>
	
	
	

	//
	// TODO: Add More Data Members As Needed
	//

public:
	
	Restaurant();
	~Restaurant();
	
	void ExecuteEvents(int TimeStep);	//executes all events at current timestep
	void RunSimulation();

	


	void FillDrawingList();

	//
	// TODO: Add More Member Functions As Needed
	//
	void addToEventQueue(Event* E);
	void LoadingFunc(char * address);
	void SimulationFunc_INTR();
/// ===================    DEMO-related functions. Should be removed in phases 1&2   ================= 

	void Just_A_Demo();	//just to show a demo and should be removed in phase1 1 & 2
	void AddtoDemoQueue(Order* po);	//adds an order to the demo queue

/// ================================================================================================== 



};

#endif