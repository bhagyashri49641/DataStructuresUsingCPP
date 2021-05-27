#include<iostream>
using namespace std;
///////////////////what our LL node contains //////////////////

typedef struct Node
{
	int Data;
	struct Node* Next;
	struct Node* Prev;
}NODE,*PNODE; //typedef for node and pointer to node

//////////////////////////Class Creation /////////////////////
class DoublyLL
{

private:
	PNODE Head;					//characteristics
	int iSize;
public:
	// 8 function che prototype lihile ith			
	DoublyLL();										//constructor

	void Display();				//Behaviors declairation 
	int Count();
	void InsertFirst();
	void InsertLast();
	void InsertAtPos();
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos();

};	//End of class declaration
////////////////////////////////////////////////////////////////
// Fololowing is the constructor of class
//This initialises class charateristics
//
///////////////////////////////////////////////////////////////
DoublyLL::DoublyLL()
{
	Head=NULL;
	iSize=0;
	cout<<"Initialisation done\n";
}

////////////////////////////////////////////////////////////////
// Fololowing is count function which counts total number of
// nodes in LL
///////////////////////////////////////////////////////////////
int DoublyLL::Count()
{
	return iSize;
}

////////////////////////////////////////////////////////////////
// Fololowing is Display which displays data of each node
//
///////////////////////////////////////////////////////////////
void DoublyLL :: Display()
{
	if(Head==NULL)
	{
		cout<<"LL is empty\n";
		return;
	}

	PNODE Temp=Head;
	while(Temp !=NULL)
	{
		cout<<Temp->Data<<"<=>";
		Temp=Temp->Next;
	}
	cout<<"NULL\n";

}
////////////////////////////////////////////////////////////////
// Fololowing function is used to insert the new Node into the
// LL at first location
///////////////////////////////////////////////////////////////

void DoublyLL:: InsertFirst()
{
	int Value;
	cout<<"Enter Value to insert\n";
	cin>>Value;
	
	PNODE newn=new NODE;

	newn->Data=Value;
	newn->Next=NULL;
	newn->Prev=NULL;

	if(Head==NULL)
	{
		Head=newn;
	}
	else
	{
		newn->Next=Head;
		Head->Prev=newn;
		Head=newn;
		
	}
	iSize++;
}

////////////////////////////////////////////////////////////////
// Fololowing function is used to insert the new Node into the
// LL at Last location
///////////////////////////////////////////////////////////////
void DoublyLL::InsertLast()
{
	int Value;
	cout<<"Enter Value to insert\n";
	cin>>Value;

	PNODE newn=new NODE;

	newn->Data=Value;
	newn->Next=NULL;
	newn->Prev=NULL;

	if(Head==NULL)
	{
		Head=newn;
	}
	else
	{
		PNODE Temp = Head;
		while(Temp->Next != NULL)
		{
			Temp=Temp->Next;
		}
		Temp->Next=newn;
		newn->Prev=Temp;
		
	}
	iSize++;
	
}

////////////////////////////////////////////////////////////////
// Fololowing function is used to insert the new Node into the
// LL at position given by user
///////////////////////////////////////////////////////////////
void DoublyLL::InsertAtPos()
{
	int iPos=0;
	cout<<"Enter position to insert node:\n";
	cin>>iPos;

	if((iPos<1)||(iPos>iSize+1))
	{
		cout<<"Invalid position\n";
		return;
	}
	
	if(iPos == 1)
	{
		InsertFirst();
	}
	else if(iPos == iSize+1)
	{
		InsertLast();
	}
	else
	{
		int Value;
		cout<<"Enter data to insert at position\n";
		cin>>Value;

		PNODE newn=new NODE;

		newn->Data=Value;
		newn->Next=NULL;
		newn->Prev=NULL;

		PNODE Temp=Head;

		for(int i=1;i<iPos-1;i++)
		{
			Temp=Temp->Next;
		}
		newn->Next=Temp->Next;
		Temp->Next->Prev=newn;
		
		Temp->Next=newn;
		newn->Prev=Temp;
		iSize++;
	}

}
///////////////////////////////////////////////////////////////
// Fololowing function is used to Delete First Node of LL
///////////////////////////////////////////////////////////////
void DoublyLL::DeleteFirst()
{
	PNODE Temp=Head;

	if((Head==NULL)&&(iSize==0))
	{
		cout<<"LL is empty\n";
		return;
	}
	else if(iSize==1)
	{
		delete Temp;
		Head=NULL;
		iSize--;
	}
	else
	{
		Temp->Next->Prev=NULL;
		Head=Head->Next;
		free(Temp);	
		iSize--;
	}
	cout<<"Node deleted successfully\n";
}

///////////////////////////////////////////////////////////////
// Fololowing function is used to Delete Last Node of LL
///////////////////////////////////////////////////////////////
void DoublyLL::DeleteLast()
{
	PNODE Temp = Head;

	if((Head==NULL)&&(iSize==0))
	{
		cout<<"LL is empty\n";
		return;
	}
	else if(iSize == 1)
	{
		delete Temp;
		Head=NULL;
		iSize--;
	}
	else
	{
		while(Temp->Next->Next != NULL)
		{
			Temp=Temp->Next;
		}
		delete(Temp->Next);
		Temp->Next=NULL;
		iSize--;
	}
	cout<<"Node deleted successfully\n";

}

///////////////////////////////////////////////////////////////
// Fololowing function is used to 
// Delete Node of position given by user
///////////////////////////////////////////////////////////////
void DoublyLL::DeleteAtPos()
{
	int iPos;
	cout<<"Enter position to delete node\n";
	cin>>iPos;

	if((Head==NULL)&&(iSize==0))
	{
		cout<<"LL is empty\n";
		return;
	}
	else if((iPos<1) || (iPos>iSize))
	{
		cout<<"Invalid Position\n";
		return;
	}
	else if(iPos==1)
	{
		DeleteFirst();
	}
	else if(iPos==iSize)
	{
		DeleteLast();
	}
	else
	{
		PNODE Temp =Head;

		for(int i=1;i<iPos;i++)
		{
			Temp=Temp->Next;
		}
		Temp->Next->Prev=Temp->Prev;
		Temp->Prev->Next=Temp->Next;
		delete Temp;
		iSize--;
	}
}

///////////////////////// Entry Point Function ////////////////
int main()
{
	DoublyLL obj;
	int Choice=1;
	int iRet=0;

	while(Choice !=0)
	{
		cout<<"********************************************\n";
		cout<<"Doubly LL operations\n";
		cout<<"1.InsertFirst\n";
		cout<<"2.InsertLast\n";
		cout<<"3.InsertAtPos\n";
		cout<<"4.Display\n";
		cout<<"5.Count\n";
		cout<<"6.DeleteFirst\n";
		cout<<"7.DeleteLast\n";
		cout<<"8.DeleteAtPos\n";
		cout<<"0.Exit\n";
		cout<<"*******************************************\n";
		cout<<"Enter your choice\n";
		cin>>Choice;

		switch(Choice)
		{
			case 1:obj.InsertFirst();
			break;

			case 2:obj.InsertLast();
			break;

			case 3:obj.InsertAtPos();
			break;

			case 4:obj.Display();
			break;

			case 5:iRet=obj.Count();
				   cout<<"LL contains "<<iRet<<" Nodes\n";
			break;

			case 6:obj.DeleteFirst();
			break;

			case 7:obj.DeleteLast();
			break;

			case 8:obj.DeleteAtPos();
			break;

			case 0:cout<<"Thank you for using my application\n";
			break;

			default:cout<<"Invalid choice...Try agian\n";
		}//End of switch
	}//End of while
	
	return 0;
}//End of main
////////////////////  End of main ////////////////////