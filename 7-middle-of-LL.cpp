#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};
//1st approach O(n) time complexity
int getLen(Node *head)
{
	int len = 0;
	while(head!=NULL)
	{
		len++;
		head = head->next;
	}
	return len;
}
Node *findMiddle(Node *head) {
    
	int ans = (getLen(head)/2);
	Node* temp = head;
	int cnt = 0;
	while(cnt<ans)
	{
		temp = temp->next;
		cnt++;
	}
	
	return temp;
}

//2nd approach 
Node * getMiddle(Node* head)
{
	if(head==NULL||head->next==NULL)
	{
		return NULL;
	}
	
	//case of 2 nodes
	if(head->next->next==NULL)
	{
		return head->next;
	}
	
	Node * slow = head;
	Node * fast = head->next;
	
	while(fast!=NULL)
	{
		fast = fast->next;
		slow = slow->next;
		if(fast!=NULL)
		{
			fast = fast->next;
		}
	}
	return slow;
}
Node *findMiddle(Node *head) {
    return getMiddle(head);
}
int main()
{

    return 0;
}