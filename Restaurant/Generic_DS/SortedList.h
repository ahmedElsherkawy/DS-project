#ifndef _SORTEDLIST
#define _SORTEDLIST

#include "Node.h"
#include"..\Rest\Cook.h"
#include"..\Rest\Order.h"
template <typename T>
class SortedList
{
private:
	Node<T> *Head;	//Pointer to the head of the list
	//You can add tail pointer too (depending on your problem)
public:


	SortedList()
	{
		Head = nullptr;
	}

	//List is being desturcted ==> delete all items in the list
	~SortedList()
	{
		DeleteAll(); 
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: PrintList.
	* prints the values of all nodes in a linked list.
	*/
	void PrintList()	const
	{		
		//cout<<"\nprinting list contents:\n\n";
		Node<T> *p = Head;

		while(p)
		{
			cout << p->getItem() <<" ";
			p = p->getNext();
		}
		//cout << "NULL\n";
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: InsertBeg.
	* Creates a new node and adds it to the beginning of a linked list.
	* 
	* Parameters:
	*	- data : The value to be stored in the new node.
	*/
	void InsertBeg(const T &data)
	{
		Node<T> *R = new Node<T>(data);
		R->setNext(Head);
		Head = R;

	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: DeleteAll.
	* Deletes all nodes of the list.
	*/
	void DeleteAll()
	{
		Node<T> *P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
	}



	////////////////     Requirements   ///////////////////
	//
	// Implement the following member functions


	//[1]InsertEnd 
	//inserts a new node at end if the list
	void InsertSorted( T data ,int key){
		Node<T>*ptr =new Node<T>(data);
		if(!Head){Head=ptr;return;}
		Node<T> *p=Head;
		while (p->getNext())
		{p=p->getNext();}
		p->setNext(ptr);
	}


	bool isempty()
	{
		if (Head == nullptr)
			return true;

		return false;
	}

	bool pop(T& frntEntry)
	{
		if (!Head)return false;
		

		Node<T>* nodeToDeletePtr = Head;
		frntEntry = Head->getItem();
		Head = Head->getNext();
		// Free memory reserved by the dequeued node
		delete nodeToDeletePtr;


		return true;

	}
	bool peek(T& frntEntry) const
	{
		if (!Head)
			return false;

		frntEntry = Head->getItem();
		return true;

	}
	//[2]Find 
	//searches for a given value in the list, returns true if found; false otherwise.
	/*bool Find(T Key){
		Node<T>* p=Head;
		
		while (p)
		{
			if(p->getItem()==Key)
				return true;
			p=p->getNext();
		}
		return false;
	}
*/
	//[3]CountOccurance
	//returns how many times a certain value appeared in the list
	/*int CountOccurance(const T &value){
	int count=0;
	Node<T>*p=Head;
	while (p)
	{if(p->getItem()==value)count++;
	p=p->getNext();

	}return count;
	}
*/
	//[4] DeleteFirst
	//Deletes the first node in the list
	/*void DeleteFirst(){
		if(!Head){cout<<"empty";return;}
		Node<T>* temp=Head;
		Head=Head->getNext();
		delete temp;
	}*/


	//[5] DeleteLast
	//Deletes the last node in the list
	/*void DeleteLast(){
	if(!Head){cout<<"empty";return;}
	if(Head->getNext()==nullptr){ DeleteFirst();return;}
	Node<T>* p=Head->getNext();
	Node<T>* ptr=Head;
	while (p->getNext())
	{ptr=p;
		p=p->getNext();
	}
	ptr->setNext(nullptr);
		delete p;
	}*/
	

	//[6] DeleteNode
	//deletes the first node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted

	/*bool DeleteNode(const T &value){
		if(!Head){return false;}
		if(Head->getNext()==nullptr){ DeleteFirst();return false;}
		Node<T>* p=Head->getNext();
		Node<T>* ptr=Head;
		while (p)
		{
			if(p->getItem()==value){
				ptr->setNext(p->getNext());
				delete p;
				return true;}
			ptr=p;
			p=p->getNext();
		}
		return false;
	}	*/

	////[7] DeleteNodes
	////deletes ALL node with the given value (if found) and returns true
	////if not found, returns false
	////Note: List is not sorted
	//bool DeleteNodes(const T &value){
	//if(!Head){cout<<"empty";return false;}
	//	if(Head->getNext()==nullptr){ DeleteFirst();return false;}
	//	Node<T>* p=Head->getNext();
	//	Node<T>* ptr=Head;
	//	int c=0;
	//	Node<T>* temp;
	//	while (p)
	//	{
	//		while (p->getItem()==value&&p){
	//			//ptr->setNext(p->getNext());
	//			temp=p;
	//			p=p->getNext();
	//			delete temp;
	//			c++;
	//			}
	//		if(!p)break;
	//		ptr=p;
	//		p=p->getNext();
	//	}
	//	if(c==0)
	//	return false;
	//	else
	//		return true;
	//}	

    T* toArray(int& count);



};

#endif

template<>
class SortedList<Cook *>
{
	Node<Cook *> *Head;
public:
	SortedList()
	{
		Head = nullptr;
	}

	Cook** toArray(int& count)
	{
		count = 0;

		if (!Head)
			return nullptr;
		//counting the no. of items in the Queue
		Node<Cook*>* p = Head;
		while (p)
		{
			count++;
			p = p->getNext();
		}


		Cook** Arr = new Cook* [count];
		p = Head;
		for (int i = 0; i < count; i++)
		{
			Arr[i] = p->getItem();
			p = p->getNext();
		}
		return Arr;
	}

	bool isempty()
	{
		if (Head == nullptr)
			return true;

		return false;
	}


	void InsertSorted( Cook * data, int key) {
		Node <Cook *>* nptr = new Node<Cook *>(data);
		if (!Head) {
			Head = nptr;
			return;
		}
		Node <Cook*> *p = Head;
		if (key == 1) // sorting according to finishservice
		{
			if (Head->getItem()->getFinishService() >= nptr->getItem()->getFinishService()) {
				nptr->setNext(Head);
				Head = nptr;
				return;
		    }
			while (p->getNext())
			{
				if (p->getNext()->getItem()->getFinishService() >= nptr->getItem()->getFinishService()) {
					nptr->setNext(p->getNext());
					p->setNext(nptr);
					return;
				}
				else {
					p = p->getNext();
				}
			}
			nptr->setNext(nullptr);
			p->setNext(nptr);

		}
		else if (key == 2) // sorting according to finish break
		{
			if (Head->getItem()->getFinishBreak() >= nptr->getItem()->getFinishBreak()) {
				nptr->setNext(Head);
				Head = nptr;
				return;
			}
			while (p->getNext())
			{
				if (p->getNext()->getItem()->getFinishBreak() >= nptr->getItem()->getFinishBreak()) {
					nptr->setNext(p->getNext());
					p->setNext(nptr);
					return;
				}
				else {
					p = p->getNext();
				}
			}
			nptr->setNext(nullptr);
			p->setNext(nptr);

		}

	}
<<<<<<< HEAD
	bool pop(Cook*& frntEntry)
=======
bool pop(Cook*& frntEntry)
>>>>>>> 12af53d728fb03f4aeb667ed01fb5f194b8802ae
	{
		if (!Head)return false;


		Node<Cook*>* nodeToDeletePtr = Head;
		frntEntry = Head->getItem();
		Head = Head->getNext();
<<<<<<< HEAD
		// Free memory reserved by the dequeued node
=======
		//Free memory reserved by the dequeued node
>>>>>>> 12af53d728fb03f4aeb667ed01fb5f194b8802ae
		delete nodeToDeletePtr;


		return true;
<<<<<<< HEAD

	}
	bool peek(Cook*& frntEntry) const
	{
		if (!Head)
			return false;

		frntEntry = Head->getItem();
		return true;

	}
=======
>>>>>>> 12af53d728fb03f4aeb667ed01fb5f194b8802ae

	}

	bool peek(Cook*& frntEntry) const
	{
		if (!Head)
			return false;

		frntEntry = Head->getItem();
		return true;

	}
};
template<>
class SortedList<Order *>
{
	Node<Order *> *Head;
	  
public:

	SortedList()
	{
		Head = nullptr;
	}


		bool isempty()
	    {
		if (Head == nullptr)
			return true;

		return false;
	    }


		Order** toArray(int & count)
		{
			count = 0;

			if (!Head)
				return nullptr;
			//counting the no. of items in the Queue
			Node<Order*>* p = Head;
			while (p)
			{
				count++;
				p = p->getNext();
			}


			Order** Arr = new Order * [count];
			p = Head;
			for (int i = 0; i < count; i++)
			{
				Arr[i] = p->getItem();
				p = p->getNext();
			}
			return Arr;
		}


	//List is being desturcted ==> delete all items in the list
	~SortedList()
	{
		DeleteAll();
	}
	void DeleteAll()
	{
		Node<Order*> *P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
	}

	void DeleteOrder(int ordID,Order * & ord) {
		if (!Head) 
		{ return; }
		Node<Order *> *temp;
		if (Head->getItem()->GetID() == ordID) {
			temp = Head;
			ord = Head->getItem();
			Head = Head->getNext();
			delete temp;
			return;
		}
		Node<Order*>* p = Head;
		while (p->getNext()) {
			if (p->getNext()->getItem()->GetID() == ordID) {
				temp = p->getNext();
				ord = p->getNext()->getItem();
				p->setNext(temp->getNext());
				delete temp;
				return;
			}
			else
			{
				p = p->getNext();
			}
		}
		ord = nullptr;
	}

	void InsertSorted(Order* ordp, int key) {
		if (!Head)
		{
			Node<Order*> *R = new Node<Order*>(ordp);
			R->setNext(Head);
			Head = R;
			return;
		}

		if (key == 1)//comparing priority desecndingly for vip orders
		{
			Node<Order*> *P = Head;
			Node<Order*> *R = P->getNext();

			while (R)
			{
				Order* op = P->getItem();
				Order* oR = R->getItem();
				if (ordp->GetPriority() > op->GetPriority())
				{
					Node<Order*> *N = new Node<Order*>(ordp);
					N->setNext(Head);
					Head = N;
					return;
				}

				else if ((ordp->GetPriority() < op->GetPriority() && ordp->GetPriority() > oR->GetPriority()) || (ordp->GetPriority() == op->GetPriority() && oR->GetPriority() != op->GetPriority()))
				{
					Node<Order*> *N = new Node<Order*>(ordp);
					N->setNext(R);
					P->setNext(N);
					return;
				}
				else
				{
					P = P->getNext();
					R = R->getNext();
				}

			}
			if (!R)
			{
				Order* op = P->getItem();
				if (ordp->GetPriority() > op->GetPriority())
				{
					Node<Order*> *N = new Node<Order*>(ordp);
		 			N->setNext(Head);
					Head = N;
					return;
				}
				else
				{
					Node<Order*> *N = new Node<Order*>(ordp);
					N->setNext(R);
					P->setNext(N);
					return;
				}
			}
		}

		if (key == 2) //by arrival Time
		{
			Node<Order*> *P = Head;
			Node<Order*> *R = P->getNext();
			while (R)
			{
				Order* op = P->getItem();
				Order* oR = R->getItem();
				if (ordp->GetArrivalTime() < op->GetArrivalTime())
				{
					Node<Order*> *N = new Node<Order*>(ordp);
					N->setNext(Head);
					Head = N;
					return;
				}
				else if ((ordp->GetArrivalTime() > op->GetArrivalTime() && ordp->GetArrivalTime() < oR->GetArrivalTime()) || (ordp->GetArrivalTime() == op->GetPriority() && oR->GetPriority() != op->GetPriority()))
				{
					Node<Order*> *N = new Node<Order*>(ordp);
					N->setNext(R);
					P->setNext(N);
					return;
				}
				else
				{
					P = P->getNext();
					R = R->getNext();
				}

			}

			if (!R)
			{
				Order* op = P->getItem();
				if (ordp->GetArrivalTime() < op->GetArrivalTime())
				{
					Node<Order*> *N = new Node<Order*>(ordp);
					N->setNext(Head);
					Head = N;
					return;
				}
				else
				{
					Node<Order*> *N = new Node<Order*>(ordp);
					N->setNext(R);
					P->setNext(N);
					return;
				}
			}


		}

		if (key == 3)// by finish time
		{
			Node<Order*>* P = Head;
			Node<Order*>* R = P->getNext();
			while (R)
			{
				Order* op = P->getItem();
				Order* oR = R->getItem();
				if (ordp->GetFinishTime() < op->GetFinishTime())
				{
					Node<Order*>*N = new Node<Order*>(ordp);
					N->setNext(Head);
					Head = N;
					return;
				}
				else if ((ordp->GetFinishTime() > op->GetFinishTime() && ordp->GetFinishTime() < oR->GetFinishTime()) || (ordp->GetFinishTime() == op->GetFinishTime() && oR->GetFinishTime() != op->GetFinishTime()))
				{
					Node<Order*> *N = new Node<Order*>(ordp);
					N->setNext(R);
					P->setNext(N);
					return;
				}
				else
				{
					P = P->getNext();
					R = R->getNext();
				}

			}

			if (!R)
			{
				Order* op = P->getItem();
				if (ordp->GetFinishTime() < op->GetFinishTime())
				{
					Node<Order*> *N = new Node<Order*>(ordp);
					N->setNext(Head);
					Head = N;
					return;
				}
				else
				{
					Node<Order*>* N = new Node<Order*>(ordp);
					N->setNext(R);
					P->setNext(N);
					return;
				}
			}
		}


	}


	bool pop(Order*& frntEntry)
	{
		if (!Head)return false;


		Node<Order*>* nodeToDeletePtr = Head;
		frntEntry = Head->getItem();
		Head = Head->getNext();
		//Free memory reserved by the dequeued node
		delete nodeToDeletePtr;


		return true;

	}

	bool peek(Order*& frntEntry) const
	{
		if (!Head)
			return false;

		frntEntry = Head->getItem();
		return true;

	}
};


template <typename T>
T* SortedList<T>::toArray(int& count)
{
	count = 0;

	if (!Head)
		return nullptr;
	//counting the no. of items in the Queue
	Node<T*>* p = Head;
	while (p)
	{
		count++;
		p = p->getNext();
	}


	T** Arr = new T*[count];
	p = Head;
	for (int i = 0; i < count; i++)
	{
		Arr[i] = p->getItem();
		p = p->getNext();
	}
	return Arr;

}
