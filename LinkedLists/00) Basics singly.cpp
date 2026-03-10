#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* createNode(int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node*& head, int value)
{
    Node* newNode = createNode(value);
    newNode->next = head;
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
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void printList(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

void insertAtPosition(Node*& head, int value, int pos)
{
    Node* newNode = createNode(value);

    if(pos == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;

    for(int i = 1; i < pos-1; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

int main()
{
    Node* head = NULL;

    insertAtBeginning(head, 10);
    insertAtBeginning(head, 5);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);

    printList(head);

    return 0;
}


#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void printList(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

void deleteFromBeginning(Node*& head)
{
    if(head == NULL)
        return;

    Node* temp = head;
    head = head->next;
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

    while(temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;
    temp->next = NULL;
}

void deleteAtPosition(Node*& head, int pos)
{
    if(head == NULL)
        return;

    if(pos == 1)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    for(int i = 1; i < pos - 1; i++)
        temp = temp->next;

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;

    delete nodeToDelete;
}

void deleteByValue(Node*& head, int value)
{
    if(head == NULL)
        return;

    if(head->data == value)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL && temp->next->data != value)
        temp = temp->next;

    if(temp->next == NULL)
        return;

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;

    delete nodeToDelete;
}

int main()
{
    // Creating list manually
    Node* head = new Node{10, NULL};
    head->next = new Node{20, NULL};
    head->next->next = new Node{30, NULL};
    head->next->next->next = new Node{40, NULL};

    cout << "Original List:\n";
    printList(head);

    deleteFromBeginning(head);
    cout << "After deleting from beginning:\n";
    printList(head);

    deleteFromEnd(head);
    cout << "After deleting from end:\n";
    printList(head);

    deleteAtPosition(head, 2);
    cout << "After deleting at position 2:\n";
    printList(head);

    deleteByValue(head, 10);
    cout << "After deleting value 10:\n";
    printList(head);

    return 0;
}