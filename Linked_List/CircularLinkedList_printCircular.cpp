#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *initNode(int num)
{
    Node *newNode = new Node;
    newNode -> data = num;
    newNode -> next = NULL;

    return newNode;
}

Node *addNode(Node *node, int num)
{
    Node *newNode = initNode(num);

    node -> next = newNode;

    return newNode;
}

void cirulate(Node *firstNode)
{
    Node *lastNode = firstNode;
    while(lastNode -> next != NULL)
    {
        lastNode = lastNode -> next;
    }

    lastNode -> next = firstNode;
}

void printList(Node *firstNode, int position, int size)
{
    Node *p = firstNode;

    for(int i=0; i<position; i++)
    {
        // cout << p -> data << " ";
        p = p -> next;
    }

    for(int i=0; i<size; i++)
    {
        cout << p -> data << " ";
        p = p -> next;
    }


}

int main()
{

    int n, firstNum, tempNum, k;
    
    cin >> n >> firstNum;

    Node *firstNode = initNode(firstNum);
    Node *p = firstNode;

    for(int i=1; i<n; i++)
    {
        cin >> tempNum;
        p = addNode(p,tempNum);
    }

    cin >> k;

    cirulate(firstNode);

    printList(firstNode, k, n);

    return 0;
}