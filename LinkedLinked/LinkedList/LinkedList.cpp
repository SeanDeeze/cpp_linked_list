// LinkedList.cpp : Defines the entry point for the application.
//

#include "LinkedList.h"

using namespace std;

int main()
{
	cout << "Begin Program Execution" << endl;
	createnode(15);
	createnode(9);
	return 0;
}

void createnode(int value)
{
	node *temp=new node;
	temp->data=value;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
		tail=temp;
		temp=NULL;
	}
	else
	{	
		tail->next=temp;
		tail=temp;
	}
}

struct Node { 
public: 
    int data; 
    Node* next; 
};

class list
  {
    Private:
    node *head, *tail;
    public:
    list()
    {
      head=NULL;
      tail=NULL;
    }
  };


