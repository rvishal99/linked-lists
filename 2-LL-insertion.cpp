#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void linkedListTraversal(node *ptr)
{

    cout << "Printing linked list!!" << endl;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
void insertAthead(node *&head, int d)
{
    node *ptr = new node(d);
    ptr->next = head;
    ptr->data = d;
    head = ptr;
    // return head;
}
void inserAtIndex(node *&head, int d, int index)
{
    node *ptr = new node(d);
    node *p = head;

    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
}
void inserAtEnd(node *&head, int d)
{
    node *ptr = new node(d);
    node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
}
void insertAfterNode(node *&head, node *&previous, int d)
{
    node * ptr = new node (d);
    ptr->next = previous->next;
    previous->next = ptr;
}
int main()
{
    cout << endl;
    node *head = new node(10);

    node *second = new node(12);
    node *third = new node(14);

    head->next = second;
    second->next = third;
    third->next = NULL;

    cout << "Before insertion" << endl;
    linkedListTraversal(head);

    insertAthead(head, 4);

    cout << endl;

    cout << "After insertion" << endl;
    linkedListTraversal(head);
    cout << endl;

    cout << "After insertion at index=1 " << endl;
    inserAtIndex(head, 6, 1);
    linkedListTraversal(head); // note: index starts from index 0
    cout << endl;

    cout << "After insertion at end " << endl;

    inserAtEnd(head, 18);
    linkedListTraversal(head);
    cout << endl;

    node * prev = second;
    insertAfterNode(head,prev,99);
    linkedListTraversal(head);
    cout<<endl;

    return 0;
}