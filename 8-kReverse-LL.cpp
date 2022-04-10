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
bool isCircularLL(Node* &head)
{
    if(head==NULL)
    {
        return true;

    }
    
    Node*temp = head->next;
    while(temp!=NULL && temp!=head)
    {
       temp = temp->next;
    }
    if(temp==head)
    {
        return true;
    } 
       return false;
}
int main()
{

    return 0;
}