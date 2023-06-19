#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
};

void insert_new_node(Node **head, int val)
{
    Node *newNode = new Node();
    newNode->val = val;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

bool same_Linked_list(Node *head1, Node *head2)
{
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->val != head2->val)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return (head1 == NULL && head2 == NULL);
}

void delete_list(Node **head)
{
    Node *tmp = *head;
    Node *next = NULL;
    while (tmp != NULL)
    {
        next = tmp->next;
        delete tmp;
        tmp = next;
    }
    *head = NULL;
}

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;

    int value;
    cin >> value;
    while (value != -1)
    {
        insert_new_node(&head1, value);
        cin >> value;
    }

    cin >> value;
    while (value != -1)
    {
        insert_new_node(&head2, value);
        cin >> value;
    }

    if (same_Linked_list(head1, head2))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    delete_list(&head1);
    delete_list(&head2);

    return 0;
}