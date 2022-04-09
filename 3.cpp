#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node * next;

    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    ~node()
    {   
        int value = this->data;
        if(this->next!=NULL)
        {
            delete next;
            this->next = NULL;  
        }
        cout<<" memory is free for node with data "<<value<<endl;
    }
};
// void deleteAtHead(node *& head)
// {
//     node * ptr = head;
//     head = head->next;
//     ptr->next = NULL;
//     delete ptr;
// }
void deleteNode(node * & head,int position)
{
    if(position==1)
    {
        node * temp = head;
        head = head->next;
        delete temp;
    }
    else{
        node * prev = NULL;
        node * curr = head;

        int cnt =1;
        while(cnt<position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
void Print(node *& head)
{
    node * ptr = head;
    while(ptr!=NULL)
    {
        cout<< ptr->data <<" ";
        ptr = ptr->next; 
    }
}
int main()
{
    node * head = new node(1);
    node * second = new node(2);
    node * third = new node(3);

    head->next = second;
    second->next = third;
    third->next = NULL;

    Print(head);
    
    // deleteAtHead(first);
    // deleteNode(first,1);
    deleteNode(head,3);
    // Print(head);

    return 0;
}