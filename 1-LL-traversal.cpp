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
void linkedListTraversal(node *ptr)
{
    cout<<endl;
    cout << "Printing linked list!!" << endl;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
int main()
{

    // cout<<n1->data<<endl;
    node *head = new node(10);

    node *second = new node(12);
    node *third = new node(14);

    head->next = second;
    second->next = third;
    third->next = NULL;

    linkedListTraversal(head);
    return 0;
}