#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *initNode(int num)
{
    Node *node = new Node;
    node -> data = num;
    node -> next = NULL;

    return node;
}

Node *addElement(Node *l, int num)
{
    Node *newNode = initNode(num);
    l -> next = newNode;

    return newNode;
}

Node *removeAt(Node *node, int position)
{
    Node *firstNode = node;
    Node *lastNode = node;
    for(int i=0; i<position-1; i++)
    {
        firstNode = firstNode -> next;
    }
    for(int i=0; i<position+1; i++)
    {
        lastNode = lastNode -> next;
    }

    firstNode -> next = lastNode;

    return node;

}

Node *removeHead(Node *l)
{
    Node *newFirstNode = l -> next;

    // l -> data = NULL;
    // l -> next = NULL;
    delete(l);

    return newFirstNode;
}

Node *removeTail(Node *l, int size)
{
    Node *lastNode = l;
    for(int i=0; i<size-1; i++)
    {
        lastNode = lastNode -> next;
    }
    lastNode -> next = NULL;

    return l;
}

void printList(Node *firstNode)
{
    Node *p = firstNode;
    while( p != NULL )
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
        p = addElement(p, tempNum);
    } 
    p = firstNode;

    cin >> k;

    if(k == 0)
    {
        p = removeHead(firstNode);
    }else if(k == n)
    {
        p = removeTail(firstNode, n);
    }else
    {
        p = removeAt(firstNode,k);
    }
    

    //ending
    printList(p);

}