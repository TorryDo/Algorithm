#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *initNode(int num)
{
    Node *p = new Node;
    p -> data = num;
    p -> next = NULL;

    return p;
}

Node *addElement(Node *p, int num)
{
    Node *newNode = initNode(num);
    p -> next = newNode;

    return newNode;
}

void printList(Node *l)
{
    Node *p = l;
    while(p != NULL)
    {
        cout << p -> data << " ";
        p = p -> next;
    }
}

Node *insertAt(Node *firstNode, int at, int num)
{
    Node *f = firstNode;
    for(int i=0; i<at-1; i++)
    {
        f = f -> next;
    }

    Node *newNode = initNode(num);
    newNode -> next = f-> next;

    f -> next = newNode;

    return firstNode;
}

Node *addHead(Node *firstNode, int num)
{
    // Node *tempNode = firstNode;
    Node *newNode = initNode(num);

    newNode -> next = firstNode;

    return newNode;

}

Node *addTail(Node *firstNode, int num)
{
    Node *lastNode = firstNode;

    while(lastNode -> next != NULL)
    {
        lastNode = lastNode -> next;
    }

    Node *realLastNode = initNode(num);
    
    lastNode -> next = realLastNode;

    return firstNode;

}

int main(){

    int n, nHeader, nTemp, k, x;
    cin >> n >> nHeader;

    Node *l = initNode(nHeader);
    Node *p = l;

    for(int i=1; i<n; i++)
    {
        cin >> nTemp;
        p = addElement(p, nTemp);

    }

    cin >> k >> x;

    // logic code here

    if(k == 0){
        l = addHead(l, x);
    }else if(k == n){
        l = addTail(l, x);
    }else{
        l = insertAt(l, k, x);
    }

    // ending.
    printList(l);

    return 0;
}