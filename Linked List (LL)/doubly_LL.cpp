#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void pushFront(int data)
{
    struct node *new_node = new struct node;
    if (new_node == NULL)
    {
        cout << "Overflow" << endl;
    }
    else
    {
        if (head == NULL)
        {
            head = new_node;
            new_node->prev = NULL;
            new_node->next = NULL;
            new_node->data = data;
            cout << "Node Inserted" << endl;
        }
        else
        {
            new_node->data = data;
            new_node->prev = NULL;
            head->prev = new_node;
            new_node->next = head;
            head = new_node;
            cout << "Node Inserted" << endl;
        }
    }
}

void pushEnd(int data)
{
    struct node *new_node = new struct node;
    struct node *temp = new struct node;
    if (new_node == NULL)
    {
        cout << "List Overflow" << endl;
    }
    else
    {
        if (head == NULL)
        {
            pushFront(data);
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            new_node->data = data;
            new_node->next = NULL;
            new_node->prev = temp;
            temp->next = new_node;
            cout << "Node Inserted" << endl;
        }
    }
    temp = NULL;
    delete temp;
}

void pushRandom(int data, int key)
{
    struct node *new_node = new struct node;
    struct node *temp = new struct node;
    if (new_node == NULL || temp == NULL)
    {
        cout << "List Overflow";
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                if (temp->next == NULL)
                {
                    pushEnd(data);
                }
                else
                {
                    new_node->data = data;
                    new_node->prev = temp;
                    new_node->next = temp->next;
                    temp->next = new_node;
                    cout << "Node Inserted" << endl;
                }
                break;
            }
            temp = temp->next;
        }
    }
}

void popFront()
{
    struct node *temp = new struct node;
    if (head == NULL)
    {
        cout << "List Underflow" << endl;
    }
    else
    {
        if (head->next == NULL)
        {
            temp = head;
            head = NULL;
            delete temp;
        }
        else
        {
            temp = head;
            head = temp->next;
            head->prev = NULL;
            cout << "Node Deleted" << endl;
            delete temp;
        }
    }
}

void popEnd()
{
    struct node *temp = new struct node;
    if (head == NULL)
    {
        cout << "List Underflow" << endl;
    }
    else if (head->next == NULL)
    {
        temp = head;
        head = NULL;
        delete temp;
        cout << "Node Deleted" << endl;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
        cout << "Node Deleted" << endl;
    }
}

void popRandom(int key)
{
    struct node *temp = new struct node;
    if (head == NULL)
    {
        cout << "List Underflow" << endl;
    }
    else if (head->data == key)
    {
        popFront();
        cout << "Node deleted" << endl;
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                if (temp->next == NULL)
                {
                    popEnd();
                    cout << "Node Deleted" << endl;
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                    cout << "Node Deleted" << endl;
                }
                break;
            }
            temp = temp->next;
        }
        if(temp==NULL){
            cout<<"Key not Found"<<endl;
        }
    }
}

void traversalFront()
{
    struct node *temp = new struct node;
    if (head == NULL)
    {
        cout << "List is Underflow" << endl;
    }
    else
    {
        temp = head;
        cout << "List ";
        while (temp != NULL)
        {
            cout << " -> " << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }
}
void traversalEnd()
{
    struct node *temp = new struct node;
    if (head == NULL)
    {
        cout << "List Underflow" << endl;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        cout << "List ";
        while (temp->prev != NULL)
        {
            cout << "-> " << temp->data;
            temp = temp->prev;
        }
        cout << "-> " << temp->data << endl;
    }
}
int main()
{
    // Driver Code
    int choice = -1, data, key;
    do
    {
        cout << "\t\t\t<----- Singly Linked List ---->" << endl;
        cout << "1.Insert Data at beginning " << endl;
        cout << "2.Insert Data at Ending " << endl;
        cout << "3.Insert after data  " << endl;
        cout << "4.Delete Data at Beginning " << endl;
        cout << "5.Delete Data at Ending " << endl;
        cout << "6.Delete specified data node " << endl;
        cout << "7.Show List from Start" << endl;
        cout << "8.Show List from End" << endl;
        cout << "0. Exit " << endl;
        cout << "Enter Response : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value : ";
            cin >> data;
            pushFront(data);
            break;
        case 2:
            cout << "Enter value : ";
            cin >> data;
            pushEnd(data);
            break;
        case 3:
            cout << "Enter value : ";
            cin >> data;
            cout << "Enter key after data should store : ";
            cin >> key;
            pushRandom(data, key);
            break;
        case 4:
            popFront();
            break;
        case 5:
            popEnd();
            break;
        case 6:
            cout << "Enter value : ";
            cin >> key;
            popRandom(key);
            break;
        case 7:
            traversalFront();
            break;
        case 8:
            traversalEnd();
            break;
        case 0:
            exit(0);
            break;
        default:
            cout << " Error Renter Choice !!" << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}
