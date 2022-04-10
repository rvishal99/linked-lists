// Reverse a linked list
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};
// 1st iterative approach
Node* reverseLinkedList(Node *head) // 1st iterative approach
{
    Node * prev = NULL;
   Node * curr = head;

   if(head==NULL || head->next==NULL) //1st one is empty list and 2nd case is single node case
   {
       return head;
   }  
   while(curr!=NULL)
   {
       Node * forward = curr->next; // order: prev , curr , forward
       curr->next = prev;  //backward point kiya
       prev = curr; // updating previous
       curr = forward; // current ko aage badadiye
   }
   return prev;
}

void inserAtEnd(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}
void print(node *&head)
{
    node * temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}
// reversing ll using 1st recursive method
void reverseLLRecursion(Node*&head,Node*&curr,Node*&prev)
{
	//base case
	if(curr==NULL)
	{
		head = prev;
		return ;
	}
	
	Node * forward = curr->next; // order: prev,curr,forward
	curr->next = prev; // pointing backwards
	
	reverseLLRecursion(head,forward,curr);
	
}
Node* reverseLinkedList(Node *head) // recursive method
{
   Node* curr =  head;
   Node* prev = NULL;
   reverseLLRecursion(head,curr,prev);
   return head; // here the head is head of reversed ll
}
//recursion approach part-2
// It will return head of the reverse list
Node * reverse1(Node*head)
{
	//base case
	if(head==NULL || head->next ==NULL)
	{
		return head;
	}
	Node*smallHead = reverse1(head->next);
	
	head->next->next = head; // pointing backwards
	head->next = NULL; // pointing backwards
	return smallHead;
}
Node* reverseLinkedList(Node *head)
{
    return reverse1(head);
}
int main()
{
    node * n1 = new node(10);

    node * head = n1;
    node * tail = n1;


    inserAtEnd(tail,15);
    inserAtEnd(tail,20);
    inserAtEnd(tail,25);
    inserAtEnd(tail,30);

    print(head);

    // reverseIterative(head);

    
    print(head);

    return 0;
}
