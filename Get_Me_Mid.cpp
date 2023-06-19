#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;

    Node(int value)
    {
        val = value;
        next = NULL;
    }
};

void insert_head(Node **head, int value)
{
    Node *newNode = new Node(value);
    newNode->next = *head;
    *head = newNode;
}

void insert_Tail(Node **head, int value)
{
    Node *newNode = new Node(value);
    if (*head == NULL || value >= (*head)->val)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        Node *current = *head;
        while (current->next != NULL && current->next->val > value)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void find_the_Middle_pos(Node *head)
{
    if (head == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }

    Node *index1 = head;
    Node *index_first = head;
    Node *last = NULL;

    while (index_first != NULL && index_first->next != NULL)
    {
        index_first = index_first->next->next;
        last = index1;
        index1 = index1->next;
    }

    if (index_first == NULL)
    {
        cout << last->val << " " << index1->val << endl;
    }
    else
    {
        cout << index1->val << endl;
    }
}

void print_the_List(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}
int main()
{
    Node *head = NULL;
    int num;

    while (cin >> num && num != -1)
    {
        insert_Tail(&head, num);
    }

    find_the_Middle_pos(head);

    return 0;
}