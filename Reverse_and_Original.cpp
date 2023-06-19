#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
};

void insert_new_node(Node **head, int value)
{
    Node *newNode = new Node();
    newNode->val = value;
    newNode->next = *head;
    *head = newNode;
}

void printReverse(Node *head)
{

    if (head->next != NULL)
    {
        printReverse(head->next);
    }

    cout << head->val << " ";
}

void printLinkedList(Node *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

int main()
{
    Node *head = NULL;
    int value;

    while (cin >> value && value != -1)
    {
        insert_new_node(&head, value);
    }

    printLinkedList(head);
    cout << endl;

    printReverse(head);
    cout << endl;
    return 0;
}