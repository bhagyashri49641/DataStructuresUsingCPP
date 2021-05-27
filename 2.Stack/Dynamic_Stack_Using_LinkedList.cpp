#include<iostream>	// input output stream header file
using namespace std; // standard namespace

struct Node
{
	int Data;
	struct Node* Next;
};

typedef struct Node NODE;
typedef struct Node* PNODE;

class stack
{
public:				// Access specifier
	PNODE Top;		// Characteristics

	stack() 			//Default constructor
	{
		Top=NULL;
	}

	void Push()
	{
		int No=0;
		cout<<"Enter element to insert:";
		cin>>No;

		PNODE newn=NULL;
		newn=new NODE; // like malloc in c++ use new operator
		newn->Data=No;
		newn->Next=NULL;

		if(Top==NULL)
		{
			Top=newn;	
		}
		else
		{
			newn->Next=Top;
			Top=newn;
		}
	}

	int Pop()
	{
		PNODE Temp=Top;
		if(Top==NULL)
		{
			cout<<"Stack is empty\n";
			return -1;
		}
		else 			// Stack conrtains atleast one node
		{
			int value=Top->Data;
			PNODE temp=Top;
			Top=Top->Next;
			delete Temp;		//delete is llike a free in c
			return value;
		}

	}

	int Peek()
	{
		int Value=0;

		if(Top==NULL)
		{
			cout<<"Stack is empty\n";
			return -1;
		}
		else
		{
			Value=Top->Data;
			return Value;
		}
	}
	void Display()
	{
		PNODE temp=Top;
		if(Top==NULL)
		{
			cout<<"Stack is empty\n";
			return;
		}
		while(temp !=NULL)
		{
			cout<<temp->Data<<endl;
			temp=temp->Next;
		}
	}
	int Count()
	{
		PNODE temp=Top;
		int iCnt=0;
		
		while(temp !=NULL)
		{
			iCnt++;
		}
		return iCnt;

	}	

};

int main()
{
	int choice=1;
	int iRet=0;

	stack obj1;		// Object os stack class

	cout<<"Welcome to the stack:Following are the operations you can perform\n";

	while(choice != 0)
	{
		cout<<"\n**********************************************************\n";
		cout<<"1.Push\n";
		cout<<"2.Pop\n";
		cout<<"3.Peek\n";
		cout<<"4.Display\n";
		cout<<"5.Count\n";
		cout<<"0.Exit\n";
		cout<<"\n**********************************************************\n";

		cout<<"Enter your choice:";
		cin>>choice;		// cin is like scanf of C

		switch(choice)
		{
			case 1: obj1.Push();
			break;


			case 2: 
					iRet=obj1.Pop();
					cout<<"Poped element is:"<<iRet<<endl;

			break;


			case 3: 
					iRet=obj1.Peek();
					cout<<"Top most element is:"<<iRet<<endl;
			break;


			case 4: cout<<"Displaying Stack elments:\n";
					obj1.Display();
			break;


			case 5:
					iRet=obj1.Count();
					cout<<"number of elements in stack are:"<<iRet<<endl;
			break;


			case 0:cout<<"Thank you for using this application\n";
			break;
			default:cout<<"Wrong choice !! try again";

		}//end of switch 
	}//end of while 
	return 0;
}//end of main





/*


int main()
{
    int choice = 1;
    int no = 0;
    
    Stack obj1;       
    Stack obj2;
    
    while(choice != 0)
    {
        cout<<"Enter your choice\n";
        cout<<"1: Push the element\n";
        cout<<"2: Pop the element\n";
        cout<<"3: Display the elements\n";
        cout<<"0: Terminate the application\n";
        
        cin>>choice;            
        
        switch(choice)
        {
            case 1:
                cout<<"Enter the element\n";
                cin>>no;
                obj1.Push(no);
                break;
            
            case 2:
                no = obj1.Pop();
                cout<<"Poped element is : "<<no<<"\n";
                break;
            
            case 3:
                cout<<"Elements of stack are\n";
                obj1.Display();
                break;
                
            case 0:
                cout<<"Thank you for using the application\n";
                break;
                
            default:
                cout<<"Wrong choice\n";
        }
    }//end of while
    
    return 0;
}// end of main



*/






















