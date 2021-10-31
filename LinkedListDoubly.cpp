#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node* pre;

	Node(int data)
	{
		this->data = data;
		next = NULL;
		pre = NULL;
	}

};
Node* create()
{
	int data;	cin>>data;
	Node* head = NULL;
	Node* temp = NULL;

	while(data != -1)
	{
		Node* newNode = new Node(data);

		if(head == NULL)
		{
			head = newNode;
			temp = head;
		}
		else
		{
			newNode->pre = temp;
			temp->next = newNode;
			temp = newNode;
		}
		cin>>data;
	}
	return head;
}
void printlist(Node* head)
{
	Node* last;
	Node* n = head;
	cout<<"\nTraversal in forward direction \n";
	while(n != NULL)
	{
		cout<<n->data<<" ";
		last = n;
		n = n->next;
	}
	cout<<endl;
	cout<<"\nTraversal in reverse direction \n";
	while(last != NULL)
	{
		cout<<last->data<<" ";
		last = last->pre;
	}
	cout<<endl;
}

Node* InsertBegn(Node* head, int data)
{
	Node* newNode = new Node(data);
	newNode->next = head;
	if(head != NULL)
	{
		head->pre = newNode;
	}
	return newNode;
}
Node* InsertEnd(Node* head, int data)
{
	Node* newNode = new Node(data);
	Node* temp = head;
	if(temp == NULL)
		return newNode;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->pre = temp;
	return head;
}
Node* DelBegn(Node* head)
{
	
	if(head == NULL){
		cout<<"Linked list is empty.\n";
		return NULL;
	}
	if(head->next == NULL){
		delete head;
		return NULL;
	}
	else{
		Node* temp = head;
		head = head->next;
		head->pre = NULL;
		delete temp;
		return head;
	}
}
Node* DelEnd(Node* head)
{
	if(head->next == NULL)
	{
		delete head;
		return NULL;
	}
	Node* temp =head;
	while(temp->next->next != NULL)
	{
		temp = temp->next;
	}
		delete(temp->next);
	return head;
}
int main()
{
	Node* head = create();

	printlist(head);
	head = InsertBegn(head, 1);
	printlist(head);
	head = InsertEnd(head,20);
	printlist(head);
	head = DelBegn(head);
	printlist(head);
	head = DelEnd(head);
	printlist(head);
	return 0;
}


