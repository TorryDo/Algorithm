#include <iostream>

#include <algorithm>
#include <string>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

void printList(Node *l)
{
    Node *p = l;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

Node *splitEvens(Node *head)
{

    if (head == 0)
        return 0;
    Node *ptr = new Node;
    if (head->data & 1)
    {
        ptr = splitEvens(head->next);
    }
    else
    {
        ptr = head;
        ptr->next = splitEvens(head->next);
    }

    return ptr;
}

Node *splitOdds(Node *head)
{
    if (head == 0)
        return 0;
    Node *ptr = new Node;
    if (head->data & 1)
    {
        ptr = head;
        ptr->next = splitOdds(head->next);
    }
    else
    {
        ptr = splitOdds(head->next);
    }

    return ptr;
}

int main()
{

    Node *head = new Node;
    head->data = 1;
    head->next = 0;

    Node *ptr = head;

    for (int i = 2; i < 10; i++)
    {
        Node *temp = new Node;
        temp->data = i;
        temp->next = NULL;
        ptr->next = temp;
        ptr = temp;
    }

    ptr = head;
    Node *onlyEvens = splitEvens(ptr);

    ptr = head;
    Node *onlyOdds = splitOdds(ptr);

    printList(onlyEvens);
    cout << " || " << endl;
    printList(onlyOdds);

    return 0;
}
