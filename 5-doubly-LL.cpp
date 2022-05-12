#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *prev, *next;

    node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int getLen(node *head)
{
    node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {

        temp = temp->next;
        cnt++;
    }
    return cnt;
}
void insertAtHead(node *&head,node *&tail, int d)
{   
    if(head == NULL) {
        node* temp = new node(d);
        head = temp;
        tail = temp;
    }
    else
    {
    node *temp = new node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
    }
}
void insertAttail(node*& head,node *&tail, int d)
{   
    if(tail ==NULL)
    {
        node * temp = new node(d);
        tail = temp;
        head = temp;
    }
    else{
    node *temp = new node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
    }
}
void insertAtposition(node *head, node *tail, int d, int position)
{
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }
    node *temp = head;
    int i = 1;
    while (i < position - 1)
    {
        temp = temp->next;
        i++;
    }
    if (temp->next == NULL)
    {
        insertAttail(tail, d);
        return;
    }
    node *tobeInserted = new node(d);
    tobeInserted->next = temp->next;
    temp->next->prev = tobeInserted;
    temp->next = tobeInserted;
    tobeInserted->prev = temp;
}
void deleteNode(node * &head,int position)
{
    if(position==1)
    {
        node * temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        
        temp->next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle 
        node * curr = head;
        node * prev = NULL;

        int cnt = 1;
        while(cnt<position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;

        delete curr;
    }
}

int main()
{
    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;

    print(head);

    insertAtHead(head,tail, 9);
    print(head);

    insertAtHead(head,tail, 8);
    print(head);

    insertAtHead(head,tail, 7);
    print(head);

    insertAttail(head,tail, 11);
    print(head);

    insertAtposition(head, tail, 9, 3);
    print(head);

    insertAtposition(head, tail, 6, 2);
    print(head);
    cout << "\nThe Length of the given linked list is: " << getLen(head) << endl;
    return 0;
}
