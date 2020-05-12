#ifndef __RESTAURANT_H_
#define __RESTAURANT_H_

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\GUI\GUI.h"
#include "..\Generic_DS\Queue.h"
#include "..\Events\Event.h"
#include"..\Generic_DS\SortedList.h"
#include "Order.h"

// it is the maestro of the project
class Restaurant
{
private:
	GUI* pGUI;
	Queue<Event*> EventsQueue;	//Queue of all events that will be loaded from file
	Queue<Order*> WaitingVegan;
	Queue<Cook*> freeNormalCooks;
	Queue<Cook*> freeVegancooks;
	Queue<Cook*> freeVIPCooks;
	Queue<Order*> finishedOrders;

	SortedList<Cook*> busyCooks;
	SortedList<Cook*> inBreakCooks;
	SortedList<Order*> WaitingNormal;
	SortedList<Order*> WaitingVIP;
	SortedList <Order*> inServiceOrders;



	SortedList<Cook* > injCooks; ///add by moataz
	//lists of VIP orders ,normal orders,inservive orders,busy cooks and in bresk cooks


	/// ==> 
	//	DEMO-related members. Should be removed in phases 1&2
	Queue<Order*> DEMO_Queue;	//Important: This is just for demo
	/// ==>

	int NumberofCooks; ///done by moataz
	int NumberofWaitingNormal;
	int NumberofWaitingVigen;
	int NumberofWaitingVIP;
	int CooksNormal;
	int CooksVigen;
	int CooksVIP;

	///added by ola
	int auto_pro;
	int VIP_WT;
	double Inj_Prop; // The probability a busy cook gets injured
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
	void LoadingFunc(string address);
	void SimulationFunc_INTR();
	void Cancellation(int ordId);
	void Addtowaitingvegan(Order *pOrd);
	void Addtowaitingnormal(Order *pOrd);
	void Addtowaitingvip(Order *pOrd);
	void AddtoServiceList(Order* pOrd);
	
	void AddtofinishedOrders(Order* pOrd);
	Order* Removefromwaitingnormal(int ordId);

	/// ===================    DEMO-related functions. Should be removed in phases 1&2   ================= 

	//void Just_A_Demo();	//just to show a demo and should be removed in phase1 1 & 2
	//void AddtoDemoQueue(Order* po);	//adds an order to the demo queue

/// ================================================================================================== 
//// all of below done by moataz
	
	int getNumberofCooks();
	void setNumberofCooks(int x);
	int getNumberWaitingNormal();
	int getNumberWaitingVigen();
	int getNumberWaitingVIP();
	void setNumberWaitingNormal(int x);
	void setNumberWaitingVigen(int x);
	void setNumberWaitingVIP(int x);
	void setCooksNormal(int x);
	void setCooksVigen(int x);
	void setCooksVIP(int x);
	int getCooksNormal();
	int getCooksVigen();
	int getCooksVIP();


	///==============================================================
	///added by moataz for simulation

	
	void AssignVIP(int t);
	void AssignVigen(int t);
	void AssignNormal(int t);

	//void MoveToService(int t);// we can remove this

	void MoveToFinished(int t);
	void PromoteNormal(int t);

	void checkUrgent(int t);
	void assigntUrgent(Order* ordToAssign, int t);

	///=========================================================================
	//modes done by moataz
	void InterActiveMode();
	void StepByStepMode();
	void SilentMode();

};

#endif