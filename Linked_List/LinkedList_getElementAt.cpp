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

Node *addElement(Node *node, int num)
{
    Node *newNode = initNode(num);
    node -> next = newNode;

    return newNode;

}

Node *getElementAt(Node *firstNode, int position)
{
    Node *p = firstNode;

    for(int i=0; i<position; i++)
    {
        p = p->next;
    }

    return p;

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

    cin >> k;

    cout << getElementAt(firstNode, k) -> data ;

}