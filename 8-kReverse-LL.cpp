#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
Node* kReverse(Node* head, int k) {
    //base case 
    if(head==NULL)
    {
       return NULL; 
    }
    //step1 revesre first k nodes
    Node* forward = NULL;
    Node* curr = head;
    Node * prev  = NULL;
    int cnt  = 0;
    
    while(curr !=NULL && cnt<k)
    {
 	    forward = curr -> next  ;
        curr->next =prev;
        prev = curr;
        curr  = forward;
        cnt++;
    }
    
    //Step 2 Recursion dek legaa aage ka
    if(forward !=NULL)
    {
        head->next = kReverse(forward,k);
    }
    //Step 3: return head of reversed list
    return prev;
    
}int main()
{

    return 0;
}
