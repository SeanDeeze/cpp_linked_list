// LinkedList.cpp : Defines the entry point for the application.

#include "LinkedList.h"

using namespace std;

class Node
{
public:
	int data;
	Node *next;
};

class List
{
public:
	Node *head, *tail;

public:
	List()
	{
		head = NULL;
		tail = NULL;
	}

	void CreateNode(int value)
	{
		Node *temp = new Node;
		temp->data = value;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}
};

void print_list(List * list) {

	Node *n = list->head;

    while (n != NULL) {
        cout << n->data << endl;
        n = n->next;
    }
	cout << endl;
}

int count_list(List * list) {
	int size = 0;
	Node *n = list->head;
    while (n != NULL) {
        size++;
		n = n->next;
    }
	return size;
}

int main()
{
	cout << "Begin Program Execution" << endl;
	List *mainList = new List();

	int listLength = rand() % 10000;
	for (int i = 0; i < listLength; i++)
	{
		mainList->CreateNode(rand() % 100000);
	}

	cout << "Final List" << endl;
	print_list(mainList);
	cout << "List Length: " << to_string(count_list(mainList)) << endl;
	cout << "End Program Execution" << endl;
	return 0;
}
