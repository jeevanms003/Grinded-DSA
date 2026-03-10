#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

Node* createNode(int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node*& head, int value)
{
    Node* newNode = createNode(value);

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtEnd(Node*& head, int value)
{
    Node* newNode = createNode(value);

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(Node*& head, int value, int pos)
{
    if(pos == 1)
    {
        insertAtBeginning(head, value);
        return;
    }

    Node* newNode = createNode(value);
    Node* temp = head;

    for(int i = 1; i < pos - 1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

void printList(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main()
{
    Node* head = NULL;

    insertAtBeginning(head, 10);
    insertAtBeginning(head, 5);

    insertAtEnd(head, 20);
    insertAtEnd(head, 30);

    insertAtPosition(head, 15, 3);

    cout << "Doubly Linked List:\n";
    printList(head);

    return 0;
}




#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

Node* createNode(int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node*& head, int value)
{
    Node* newNode = createNode(value);

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void deleteFromBeginning(Node*& head)
{
    if(head == NULL)
        return;

    Node* temp = head;

    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    delete temp;
}

void deleteFromEnd(Node*& head)
{
    if(head == NULL)
        return;

    if(head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;

    delete temp;
}

void deleteAtPosition(Node*& head, int pos)
{
    if(head == NULL)
        return;

    Node* temp = head;

    if(pos == 1)
    {
        deleteFromBeginning(head);
        return;
    }

    for(int i = 1; i < pos; i++)
        temp = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    if(temp->prev != NULL)
        temp->prev->next = temp->next;

    delete temp;
}

void printList(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main()
{
    Node* head = NULL;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    cout << "Original List:\n";
    printList(head);

    deleteFromBeginning(head);
    cout << "After deleting from beginning:\n";
    printList(head);

    deleteFromEnd(head);
    cout << "After deleting from end:\n";
    printList(head);

    deleteAtPosition(head, 2);
    cout << "After deleting position 2:\n";
    printList(head);

    return 0;
}