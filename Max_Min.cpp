#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
};

void insert_value(Node **head, int value)
{
    Node *newNode = new Node();
    newNode->val = value;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *tmp = *head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}

void Min_Max(Node *head)
{
    if (head == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }

    int maxVal = head->val;
    int minVal = head->val;
    Node *tmp = head->next;

    while (tmp != NULL)
    {
        if (tmp->val > maxVal)
        {
            maxVal = tmp->val;
        }
        if (tmp->val < minVal)
        {
            minVal = tmp->val;
        }
        tmp = tmp->next;
    }

    cout << maxVal << " ";
    cout << minVal;
}

void delete_node_List(Node **head)
{
    Node *tmp = *head;
    Node *nextNode;

    while (tmp != NULL)
    {
        nextNode = tmp->next;
        delete tmp;
        tmp = nextNode;
    }

    *head = NULL;
}

int main()
{
    Node *head = NULL;
    int value;

    while (cin >> value && value != -1)
    {
        insert_value(&head, value);
    }

    Min_Max(head);

    delete_node_List(&head);

    return 0;
}