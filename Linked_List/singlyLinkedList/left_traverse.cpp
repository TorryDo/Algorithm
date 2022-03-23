#include <iostream>

#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

void Left_Traverse(Node *head)
{
    if (head == NULL)
        return;

    if (head->next != NULL)
        Left_Traverse(head->next);

    cout << head->data;
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

    Left_Traverse(head);

    return 0;
}
