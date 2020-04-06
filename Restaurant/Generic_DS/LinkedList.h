#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Node.h"

template <typename T>
class LinkedList
{
private:
	Node<T> *Head;	//Pointer to the head of the list
	//You can add tail pointer too (depending on your problem)
public:


	LinkedList()
	{
		Head = nullptr;
	}

	//List is being desturcted ==> delete all items in the list
	~LinkedList()
	{
		DeleteAll(); 
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: PrintList.
	* prints the values of all nodes in a linked list.
	*/
	/*void PrintList()	const
	{		
		cout<<"\nprinting list contents:\n\n";
		Node<T> *p = Head;

		while(p)
		{
			cout << "[ " << p->getItem() << " ]";
			cout << "--->";
			p = p->getNext();
		}
		cout << "NULL\n";
	}*/

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
	void InsertEnd( T data,int key) {
		key=0;
		if (Head)
		{
			Node<T>* p = Head;
			while (p->getNext() != nullptr)
			{
				p = p->getNext();
			}

			Node<T>* R = new Node<T>(data);
			p->setNext(R);
			//R->setItem(data);
			R->setNext(nullptr);
		}
		else
		{
			Node<T>* R = new Node<T>(data);
			Head = R;
			R->setNext(nullptr);

		}
	}


	/*void InsertEnd(Node * data) {
		if (Head)
		{
			Node<T>* p = Head;
			while (p->getNext() != nullptr)
			{
				p = p->getNext();
			}

			Node<T>* R = data;
			p->setNext(data);
			//R->setItem(data);
			data->setNext(nullptr);
		}
		else
		{
			//Node<T>* R = new Node<T>(data);
			Head = data;
			R->setNext(nullptr);

		}
	}*/


	//[2]Find 
	//searches for a given value in the list, returns true if found; false otherwise.
	bool Find(T Key) {
		Node<T>* p = Head;
		while (p != nullptr)
		{
			if (p->getItem() == Key)
			{
				return true;
			}
			p = p->getNext();
		}
		return false;
	}

	//[3]CountOccurance
	//returns how many times a certain value appeared in the list
	int CountOccurance(const T& value) {
		int c = 0;
		Node<T>* p = Head;
		while (p != nullptr)
		{
			if (p->getItem() == value)
			{
				c = c + 1;
			}
			p = p->getNext();
		}
		return c;
	}

	//[4] DeleteFirst
	//Deletes the first node in the list
	void DeleteFirst() {
		Node<T>* p = Head;
		Head = Head->getNext();
		delete p;
	}


	//[5] DeleteLast
	//Deletes the last node in the list
	void DeleteLast() {
		Node<T>* p = Head;
		while (p->getNext() != nullptr)
		{
			p=p->getNext();
		}
		Node<T>* O = Head;
		while (O->getNext() != p)
		{
			O = O->getNext();
		}
		delete p;
		O->setNext(nullptr);
	}

	//[6] DeleteNode
	//deletes the first node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	bool DeleteNode(const T& value) {
		Node<T>* p = Head;
		if (!Head)
		{
			return false;
		}
		if (Head->getItem() == value) {
			DeleteFirst();
			return true;
		}
		while (p->getNext() != nullptr)
		{
			Node<T>* O = p->getNext();
			if (O->getItem() == value)
			{
				p->setNext(O->getNext());
				delete O;
				O = p->getNext();
				return true;

			}
			p = p->getNext();

		}
		return false;
		

	}

	//[7] DeleteNodes
	//deletes ALL node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	bool DeleteNodes(const T& value)
	{
		int c=0;
		bool found = false;
		if (!Head)
		{
			return false;
		}
		
		Node<T>* p = Head;
		while (p->getNext() != nullptr)
		{
			Node<T>* O = p->getNext();
			if (O->getItem() == value)
			{
				p->setNext(O->getNext());
				delete O;
				O = p->getNext();
				c=c+1;
				found = true;
			}
			if (found==false)
			{
				//found = false;
				p = p->getNext();
			}
			found = false;
		}
		if (Head->getItem() == value) {
			DeleteFirst();
			c = c + 1;
		}
		if (c == 0)
		{
			return false;
		}
		return true;
	}

	//[8]Merge
	//Merges the current list to another list L by making the last Node in the current list 
	//point to the first Node in list L
	/*void Merge(const LinkedList& L)
	{
		Node<T>* p = Head;
		while (p->getNext() != nullptr)
		{
			p = p->getNext();
		}
		p->setNext(L.Head);
	}

	//[9] Reverse
	//Reverses the linked list (without allocating any new Nodes)
	void Reverse();
	*/


	bool RemoveEvensAfterOdds()
	{
		int c = 0;
		bool found = false;
		if (!Head)
		{
			return false;
		}

		Node<T>* p = Head;
		while (p->getNext() != nullptr)
		{
			Node<T>* O = p->getNext();
			if (O->getItem()%2==0 && p->getItem()%2 !=0)
			{
				p->setNext(O->getNext());
				delete O;
				O = p->getNext();
				c = c + 1;
				found = true;
			}
			if (found == false)
			{
				//found = false;
				p = p->getNext();
			}
			found = false;
		}
		if (c == 0)
		{
			return false;
		}
		return true;
	}

	void PrintList()	const
	{
		//cout << "\nprinting list contents:\n\n";
		Node<T>* p = Head;

		while (p)
		{
			cout << p->getItem() << " ";
			p = p->getNext();
		}
	}

	void CompletesTen()
	{
		Node<T>* M = Head;
		
		while (M != nullptr)
		{
			if (M->getItem() < 10)
			{
				Node<T>* O = new Node<T>(10 - M->getItem());
				O->setNext(M->getNext());
				M->setNext(O);
				M = O;
				//PrintList();
			}
			M = M->getNext();
			//PrintList();
		}
		/*M = M->getNext();
		if (M->getItem() < 10)
		{
			Node<T>* A = new Node<T>(10 - M->getItem());
			A->setNext(nullptr);
			M->setNext(A);
			M = A;
		}*/
	}


	void RemoveEquals()
	{
		int c = 0;
		bool found = false;
		bool fin = false;


		Node<T>* p = Head;
		while (p && p->getNext() != nullptr)
		{
			Node<T>* O = p->getNext();
			if (O->getItem() == p->getItem())
			{
				p->setNext(O->getNext());
				delete O;
				O = p->getNext();
				c = c + 1;
				found = true;
				if (O==nullptr || O->getItem() != p->getItem()) { fin = true; }
			}
			if (fin == true)
			{
				Node<T>* U = Head;
				Node<T>* I = p;
				if (p == Head)
				{
					DeleteFirst();
					p = Head;
				}
				else
				{
					while (U->getNext() != p)
					{
						U = U->getNext();
					}
					U->setNext(p->getNext());
					p = p->getNext();
					delete I;
				}
				fin = false;
			}
			if (found == false)
			{
				//found = false;
				p = p->getNext();
			}
			found = false;
		}
		/*if (Head->getItem() == value) 
		{
			DeleteFirst();
			c = c + 1;
		}*/
	}

	void CompressEquals()
	{
		int c = 1;
		bool found = false;
		bool fin = false;


		Node<T>* p = Head;
		while (p && p->getNext() != nullptr)
		{
			Node<T>* O = p->getNext();
			if (O->getItem() == p->getItem())
			{
				p->setNext(O->getNext());
				delete O;
				O = p->getNext();
				c = c + 1;
				found = true;
				if (O == nullptr || O->getItem() != p->getItem()) { fin = true; }
			}
			if (fin == true)
			{

				O = p;
				p = p->getNext();
				O->setItem(O->getItem() * c);
				c = 1;
				fin = false;
			}
			if (found == false)
			{
				//found = false;
				p = p->getNext();
			}
			found = false;
		}
		/*if (Head->getItem() == value)
		{
			DeleteFirst();
			c = c + 1;
		}*/
	}




	T getFirst()
	{
		Node<T>* p = Head;
		Head = Head->getNext();
		T x = p->getItem();
		delete p;
		return x;
		//done by moataz
	}

};

#endif
//done by caroline
template <>
class LinkedList<Order*>
{
private:
	Node<Order*> *Head;	//Pointer to the head of the list
	//You can add tail pointer too (depending on your problem)
public:
	LinkedList()
	{
		Head = nullptr;
	}

	//List is being desturcted ==> delete all items in the list
	~LinkedList()
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
void InsertEnd( Order* ordp,int key) {
	if(!Head)
	{
		Node<Order*> *R = new Node<Order*>(ordp);
		R->setNext(Head);
		Head = R;
		return;
	}
	
	if (key==1)//comparing priority desecndingly for vip orders
	{
		Node<Order*> *P = Head;
		Node<Order*> *R= P->getNext();

		while(R)
		{
			Order* op=P->getItem();
			Order* oR=R->getItem();
			if (ordp->GetPriority() > op->GetPriority())
			{
				Node<Order*> *N = new Node<Order*>(ordp);
				N->setNext(Head);
				Head = N;
				return;
			}

			else if((ordp->GetPriority() < op->GetPriority() && ordp->GetPriority() > oR->GetPriority()) || (ordp->GetPriority() == op->GetPriority() && oR->GetPriority() != op->GetPriority()))
			{
				Node<Order*> *N = new Node<Order*>(ordp);
				N->setNext(R);
				P->setNext(N);
				return;
			}
			else
			{
				P=P->getNext();
				R=R->getNext();
			}
	
		}
		if(!R)
		{
			Order* op=P->getItem();
			if (ordp->GetPriority()>op->GetPriority())
			{
				Node<Order*> *N = new Node<Order*>(ordp);
				N->setNext(Head);
				Head= N;
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

	if (key==2) 
	{
		Node<Order*> *P = Head;
		Node<Order*> *R= P->getNext();
		while(R)
		{
			Order* op=P->getItem();
			Order* oR=R->getItem();
			if (ordp->GetArrivalTime() < op->GetArrivalTime())
			{
				Node<Order*> *N = new Node<Order*>(ordp);
				N->setNext(Head);
				Head = N;
				return;
			}
			else if((ordp->GetArrivalTime() > op->GetArrivalTime() && ordp->GetArrivalTime() < oR->GetArrivalTime()) || (ordp->GetArrivalTime() == op->GetPriority() && oR->GetPriority() != op->GetPriority()))
			{
				Node<Order*> *N = new Node<Order*>(ordp);
				N->setNext(R);
				P->setNext(N);
				return;
			}
			else
			{
				P=P->getNext();
				R=R->getNext();
			}

		}

		if(!R)
		{
			Order* op=P->getItem();
			if (ordp->GetArrivalTime()<op->GetArrivalTime())
			{
				Node<Order*> *N = new Node<Order*>(ordp);
				N->setNext(Head);
				Head= N;
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


	}



	Order* getFirst()
	{
		Node<Order*>* p = Head;
		Head = Head->getNext();
		Order* x = p->getItem();
		delete p;
		return x;
		//done by moataz
	}




};