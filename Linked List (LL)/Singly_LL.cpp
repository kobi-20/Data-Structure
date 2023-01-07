#include <iostream>
using namespace std;
// Node Structure
struct node
{
    int data;
    struct node *next;
};
// Global Pointers
struct node *head = NULL;
struct node *top = NULL;

void beginInsert(int data)
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
            new_node->data = data;
            new_node->next = NULL;
            head = new_node;
            top = new_node;
            cout << "<--Node Inserted-->" << endl;
        }
        else
        {
            new_node->data = data;
            new_node->next = head;
            head = new_node;
            cout << "<--Node Inserted-->" << endl;
        }
    }
}

void lastInsert(int data)
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
            new_node->data = data;
            new_node->next = NULL;
            head = new_node;
            top = new_node;
            cout << "<--Node Inserted-->" << endl;
        }
        else
        {
            new_node->data = data;
            new_node->next = NULL;
            top->next = new_node;
            top = new_node;
            cout << "<--Node Inserted-->" << endl;
        }
    }
}

void random_insert(int data, int key)
{
    struct node *new_node = new struct node;
    struct node *temp = new struct node;
    if (new_node == NULL)
    {
        cout << "Overflow" << endl;
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
                    lastInsert(data);
                    break;
                }
                else
                {
                    new_node->data = data;
                    new_node->next = temp->next;
                    temp->next = new_node;
                    cout << "<-- Node Inserted-->" << endl;
                    break;
                }
            }
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Key not found" << endl;
        }
        temp = NULL;
        delete temp;
    }
}

void traversal()
{
    struct node *temp = new struct node;
    if (head == NULL)
    {
        cout << "Underflow" << endl;
    }
    else
    {
        temp = head;
        cout << "Data ";
        while (temp != NULL)
        {
            cout << " -> " << temp->data;
            temp = temp->next;
        }
    }
    cout << endl;
}
void beginDelete()
{
    struct node *temp = new struct node;
    if (head == NULL)
    {
        cout << "Underflow" << endl;
    }
    else
    {
        temp = head;
        cout << "Deleted Element is " << temp->data << endl;
        head = temp->next;
    }
    delete temp;
}
void randomDelete(int key)
{
    struct node *temp = new struct node;
    if (head == NULL)
    {
        cout << "underflow" << endl;
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            if (temp->next->data == key)
            {
                temp->next = temp->next->next;
                cout << "Node Deleted" << endl;
                break;
            }
            temp = temp->next;
        }
    }
}
void lastDelete()
{
    struct node *temp = new struct node;
    struct node *ptr = new struct node;
    if (head == NULL)
    {
        cout << "Underflow" << endl;
    }
    else if (head->next == NULL)
    {
        temp = head;
        cout << "Deleted Element is " << head->next;
        delete temp;
        head = NULL;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            ptr = temp;
            temp = temp->next;
        }
        cout << "Deleted Element is " << temp->data << endl;
        ptr->next = NULL;
        delete temp;
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
        cout << "7.Show List " << endl;
        cout << "0. Exit " << endl;
        cout << "Enter Response : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value : ";
            cin >> data;
            beginInsert(data);
            break;
        case 2:
            cout << "Enter value : ";
            cin >> data;
            lastInsert(data);
            break;
        case 3:
            cout << "Enter value : ";
            cin >> data;
            cout << "Enter key after data should store : ";
            cin >> key;
            random_insert(data, key);
            break;
        case 4:
            beginDelete();
            break;
        case 5:
            lastDelete();
            break;
        case 6:
            cout << "Enter value : ";
            cin >> data;
            randomDelete(data);
            break;
        case 7:
            traversal();
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