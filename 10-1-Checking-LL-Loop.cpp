#include<iostream>
#include<map>
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
bool detectLoop(Node *head)
{
    if(head==NULL)
    {
        return false;
    }
    map<Node*,bool> visited;
    Node* temp = head;

    while(temp!= NULL)
    {
        //cycle present hai
        if(visited[temp] ==true) //already its true
        {
            cout<<"present on element "<<temp->data <<endl; // it gives on which element it starts to loop.
           return true;
        }
        visited[temp] = true; //// For the first time it becomes true.
        temp = temp->next;
    }
    return false;
}
Node * floydDetectLoop(Node * head)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node * slow = head;
    Node * fast = head;

    while(slow!=NULL && fast!=NULL)
    {
        fast = fast->next;
        slow = slow->next;
        if(fast!=NULL)
        {
            fast = fast->next;
        }
        
        if(slow==fast)
        {
            cout<<"Loop is present at "<<slow->data<<endl;
            return slow;
        }
    }
}
Node * getStartingNode(Node *head) // loop starts at getStartingNode;
{
    if(head==NULL)
    {
        return NULL;
    }
    Node * intersection = floydDetectLoop(head); // here intersection is between slow anf fast pointer
    if(intersection==NULL)
    {
        return NULL;
    }
    Node * slow  = head;

    while(slow!=intersection)
    {
        slow= slow->next;
        intersection = intersection->next;
    }
    return slow;
}
void removeLoop(Node * head) // removes loop and points the last element to NULL
{
    if(head==NULL)
    {
        return ;
    }
    Node * startofLOOP = getStartingNode(head);
    if(startofLOOP==NULL)
    {
        return ; //return head in question
    }
    Node * temp = startofLOOP;

    while(temp->next!=startofLOOP)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}
int main(){



return 0;
}