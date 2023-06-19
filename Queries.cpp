#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int valu) // Constructor
    {
        val = valu;
        next = NULL;
    }
};

void insert_in_Head(Node **head, Node **tail, int valu)
{
    Node *newNode = new Node(valu);
    newNode->next = *head;

    if (*head == NULL)
    {
        *tail = newNode;
    }

    *head = newNode;
}

void insert_in_Tail(Node **head, Node **tail, int valu)
{
    Node *newNode = new Node(valu);

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        (*tail)->next = newNode;
    }

    *tail = newNode;
}

void print_Head_Tail(Node *head, Node *tail)
{
    if (head == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }

    cout << head->val << " " << tail->val << endl;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int s, t;
        cin >> s >> t;

        if (s == 0)
        {
            insert_in_Head(&head, &tail, t);
        }
        else if (s == 1)
        {
            insert_in_Tail(&head, &tail, t);
        }

        print_Head_Tail(head, tail);
    }
    return 0;
}