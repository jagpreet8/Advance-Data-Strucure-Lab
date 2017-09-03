#include<iostream>
using namespace std;
//Define node pointer
struct node{
	int data;
	node* next;
};
//Head and tail pointers
node* head;
node*tail;
//Push element in stack
void push(node *& head, node *&tail, int data)
{
	if (head==NULL)
	{   node* n= new node;
	    n->data=data;
	    n->next=NULL;
		head=n;
		tail=n;
	}
	else if (head!=NULL)
	{
	  node* n= new node;
	  n->data=data;
	  n->next=head; 
		head=n;
	}
}
//Show elements in stack
void showdata(node *& head)
{    node* temp=new node;
     temp=head;
	if (temp==NULL)
	{
	cout<<"The stack is empty"<<endl;
	}
	else
	{
		cout<<"The elements in the stack are: "<<endl;
		while(temp!=NULL)
		{
			cout<<temp->data<<endl;
			temp=temp->next;
		}
	}
}
// Pop first element in stack
void pop(node *&head, node *& tail)
{
	if (head==NULL)
	{
		cout<<"The stack is empty"<<endl;
	}
	else if (head==tail)
	{   cout<<"The value "<<head->data<<" was popped"<<endl;
	    delete head; 
		head=NULL;
		tail=NULL;
	}
	else 
	{
		node* delptr=new node;
		delptr=head;
		head=head->next;
		cout<<"The value "<<delptr->data<<" was popped"<<endl;
		delete delptr;
	}
}
//Show top-most element in stack
void top(node *& head)
{
	node* temp=new node;
	temp=head;
	if (temp==NULL)
	{
	cout<<"The stack is empty"<<endl;
    }   
	else
	{
	cout<<"The value at the top of the stack is "<<temp->data<<endl;
    }
}
//Show number of elements in stack
void sizeofstack(node *& head)
{   
    node* temp = new node;
	temp=head; 
	int count=0;
	if (temp==NULL)
	{
	cout<<"The size of the stack is "<<count<<endl;
    }
	else
	{
		while(temp!=NULL)
		{
			count++;
			temp=temp->next;
		}
		cout<<"The size of the stack is "<<count<<endl;
	}
}
//Destroy stack
void destroystack(node *& head)
{
	node* delptr=new node;
	if (head==NULL)
	{
	cout<<"The stack is empty"<<endl;	
	}
	else
	{
	while(head!=NULL)
	{
	delptr=head;
	head=head->next;
	delete delptr;
  }
  cout<<"Stack has been destroyed!"<<endl;
  }
}
//Menu function
char menu()
{
char choice;
    cout<<"Menu: \n";
    cout<<"1. Push values in stack."<<endl;
    cout<<"2. Pop value from top of stack."<<endl;
    cout<<"3. Show the stack."<<endl;
    cout<<"4. Show the top of the stack."<<endl;
    cout<<"5. Number of elements in stack."<<endl;
    cout<<"6. Destroy stack."<<endl;
    cout<<"7. Exit."<<endl;
    cout<<"Enter your choice (1-6) from above: ";
    cin>>choice;
    return choice;
}
//Main function
int main()
{
	node* head;
	node* tail;
	head=NULL;
	tail=NULL;
    char choice;
    do{
    cout<<"-----------------------------------------------------"<<endl;
	choice=menu();
	cout<<"-----------------------------------------------------"<<endl;
	switch(choice)
    {
    	case '1':
    	int data;
		cout<<"Enter value to be stored in stack: ";
		cin>>data; 
		push(head,tail,data);
		break;
		
		case '2': 
		pop(head,tail);
		break;
		case '3':
		showdata(head);
		break;
		case '4':
		top(head);
		break;
		case '5':
		sizeofstack(head);
		break;		
		case '6':
		destroystack(head);
		break;
		default:
		cout<<"Exiting Menu";
	}
}while(choice!='7');
		return 0;
	
}

