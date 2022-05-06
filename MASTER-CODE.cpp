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
    ~node()
    {
        int k = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Node with data " << k << " has been freed up!!" << endl;
    }
};
void insertAtPosition(node *&head, int data, int position)
{
    if (position == 1)
    {
        node *temp = new node(data);
        temp->next = head;
        head = temp;
    }
    else
    {
        node *temp = new node(data);
        node *ptr = head;

        int i = 0;
        while (i != 0)
        {
            ptr = ptr->next;
            i++;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
}
void insertAtEnd(node *&head, int data)
{
    node *temp = head;
    node *ptr = new node(data);

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
    ptr->next = NULL;
}
void deleteAtHead(node *&head)
{
    node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
}
void deleteAtPosition(node *&head, int position)
{
    if (position == 1)
    {
        deleteAtHead(head);
    }
    else
    {
        node *prev = NULL;
        node *curr = head;

        int count = 1;

        while (count < position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
void deleteAtlast(node*&head)
{
    node *prev = NULL;
    node *curr = head;

    while (curr->next!=NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    delete curr;
}
void Print(node *&head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }cout<<endl;
}
int main()
{
    node * head = NULL;

    while (1)
    {
        cout << "1: insertAthead\t 2: insertAtPosition\t 3: insertAtlast \t 4: Display \t 5: Exit \t 6: deleteAThead \t 7: dP \t 8: dLL" << endl;
        cout << endl;
        int c;
        cout<< "Enter your choice: " << endl;
        cin >> c;
        switch (c)
        {
        case 1:
        {
            int n;
            cout << "Enter value of node to be inserted: " << endl;
            cin>>n;
            insertAtPosition(head,n,1);
            break;
        }
        case 2:
        {
            int n;
            cout << "Enter value of node to be inserted: " << endl;
            cin>>n;
            int m;
            cout << "Enter position of node to be inserted: " << endl;
            cin>>m;

            
            insertAtPosition(head,n,m);
            break;
        }
        case 3:
        {
            int n;
            cout << "Enter value of node to be inserted: " << endl;
            cin>>n;
            insertAtEnd(head,n);
            break;
        }
        case 4:
        {
           Print(head);
           break; 
        }
        case 6:
        {
            deleteAtHead(head);
            break;
        }
        case 7:
        {
            int p;
            cout<<"Enter position: "<<endl;
            cin>>p;
            deleteAtPosition(head,p);
            break;
        }
        case 5:
        {
            exit(0);
        }
        case 8:
        {
            deleteAtlast(head);
            break;
        }
        default:
        {
            cout << "Invalid character!!!" << endl;
        }
        }
    }

    return 0;
}