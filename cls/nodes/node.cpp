#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

void insert(Node *prevNode, int newData)
{
    if (prevNode == nullptr)
    {
        cout << "node cannot be null." << endl;
        return;
    }

    Node *newNode = new Node(newData);
    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if (prevNode->next != nullptr)
    {
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
}

void print(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int node()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    cout << "原始链表： ";
    print(head);

    insert(second, 4);

    cout << "插入后链表: ";
    print(head);

    return 0;
}