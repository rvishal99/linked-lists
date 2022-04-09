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
void linkedListTraversal(node *&head)
{
    // cout<<endl;
    // cout << "Printing linked list!!" << endl;
    // while (ptr != NULL)
    // {
    //     cout << ptr->data << " ";
    //     ptr = ptr->next;
    // }
    // cout << endl;
    if (head == NULL)
    {
        cout << "List is empty " << endl;
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void DelNode(node *&head, int position)
{
    node *temp = head;

    if (position == 1)
    {
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        node *prev = NULL;
        node *curr = head;

        int i = 1;
        while (i < position)
        {
            prev = curr;
            curr = curr->next;
            i++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
void insertAtHead(node *&head, int d)
{
    node *temp = head;
    temp->next = head;
    head = temp;
}

void inserAtEnd(node *&tail, int d)
{
    // node *ptr = new node(d);
    // node *p = head;

    // while (p->next != NULL)
    // {
    //     p = p->next;
    // }
    // p->next = ptr;
    // ptr->next = NULL;

    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}
void insertAtPosition(node *&head, node *&tail,int position,int d)
{
    if(position==1)
    {
        insertAtHead(head,d);
        return ;
    }
    node * temp = head;
    int i=1;
    while(i<position-1)
    {
        temp = temp->next;
        i++;
    }

    if(temp->next==NULL)
    {
        inserAtEnd(tail,d);
        return ;
    }

    node * tobeInserted = new node(d);
    tobeInserted->next = temp->next;
    temp->next = tobeInserted;

}
int main()
{
    node *n1 = new node(2);
    node *head = n1;
    node *tail = n1;
    inserAtEnd(tail, 4);
    inserAtEnd(tail, 6);
    inserAtEnd(tail, 8);
    inserAtEnd(tail, 10);

    cout<<"Before deletion"<<endl;
    linkedListTraversal(head);

    DelNode(head, 1);
    // deletion(head,8);
    cout<<"After deletion"<<endl;

    // linkedListTraversal(head);
    // cout << endl;

    linkedListTraversal(head);
    // cout << endl;

    // inserAtEnd(head, 12);
    insertAtPosition(head,tail,5,16);
    linkedListTraversal(head);

    return 0;
}