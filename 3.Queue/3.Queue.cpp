#include<iostream>
using namespace std;

typedef struct Node
{
	int Data;
	struct Node *Next;
}NODE,*PNODE;

class Queue
{
private:	//charateristics
	PNODE Head;
	int iSize;
public:	
	Queue();	//constructor
	void Enqueue();	//behaviours
	int Dequeue();
	int Count();
	void Display();
};//End of class declaration

Queue::Queue()
{
	Head=NULL;
	iSize=0;
}

void Queue::Enqueue()//Insert last 
{
	int Value;
	cout<<"Enter Value to insert\n";
	cin>>Value;

	PNODE newn = new NODE;
	newn->Data = Value;
	newn->Next = NULL;

	if(Head == NULL)
	{
		Head = newn;
	}
	else
	{
		PNODE Temp=Head;
		while(Temp->Next != NULL)
		{
			Temp=Temp->Next;
		}
		Temp->Next=newn;
	}
	iSize++;
}

int Queue::Dequeue()//Delete First
{
	int No=0;

	if(Head == NULL)
	{
		cout<<"Queue is empty\n";
		return -1;
	} 
	else
	{
		PNODE Temp=Head;
		Head=Head->Next;
		No=Temp->Data;
		delete Temp;
	}
	iSize--;
	return No;
}

void Queue::Display()
{
	PNODE Temp=Head;

	if(Head==NULL)
	{
		cout<<"LL is empty\n";
		return;
	}
	while(Temp != NULL)
	{
		cout<<Temp->Data<<"->";
		Temp=Temp->Next;
	}
	cout<<"\n";
}
int Queue::Count()
{
	return iSize;
}

int main()
{
	int Choice=1;
	int iRet=0;
	Queue obj;

	while(Choice !=0)
	{
		cout<<"*****************************************\n";
		cout<<"Queue Operations\n";
		cout<<"1.Enqueue\n";
		cout<<"2.Dequeue\n";
		cout<<"3.Display\n";
		cout<<"4.Count\n";
		cout<<"0.Exit\n";
		cout<<"*****************************************\n";
		cout<<"Enter Your Choice\n";
		cin>>Choice;

		switch(Choice)
		{
			case 1:obj.Enqueue();
			break;

			case 2:iRet=obj.Dequeue();
					cout<<"Removed element is: "<<iRet<<endl;
			break;

			case 3:obj.Display();
			break;

			case 4:iRet=obj.Count();
				cout<<"Total number of nodes in queue are: "<<iRet<<endl;
			break;

			case 0:cout<<"Thank you for using my application\n";
			break;

			default:cout<<"Wrong choice Try again\n";
			break;

		}
	}


}
