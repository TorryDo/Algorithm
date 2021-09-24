#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *pre;
    Node *next;
};

struct DuoList{
    Node *head;
    Node *tail;
};

Node *initNode(int num)
{
    Node *newNode = new Node;
    newNode -> data = num;
    newNode -> next = NULL;
    newNode -> pre = NULL;

    return newNode;
}

Node *addElement(Node *node, DuoList *duoL, int num)
{
    Node *newNode = initNode(num);
    newNode -> next = NULL;
    newNode -> pre = duoL -> tail;

    duoL -> tail -> next = newNode;
    duoL -> tail = newNode;

    return newNode;
}

Node *addHead(DuoList *duo, int num)
{
    Node *newNode = initNode(num);
    newNode -> next = duo -> head;
    newNode -> pre = NULL;

    duo -> head -> pre = newNode;
    duo -> head = newNode;

    return newNode;
}

Node *addTail(DuoList *duo, int num)
{
    Node *newNode = initNode(num);
    newNode -> pre = duo -> tail;
    newNode -> next = NULL;

    duo -> tail -> next = newNode;
    duo -> tail = newNode;

    return newNode;
}

Node *addAt(DuoList *duo, int num, int position)
{
    Node *prevNode = duo -> head;
    Node *nextNode = duo -> head;

    for(int i=0; i<position; i++)
    {
        if(i < position-1)
        {
            prevNode = prevNode -> next;
        }
        nextNode = nextNode -> next;
    } 

    Node *newNode = initNode(num);
    newNode -> pre = prevNode;
    newNode -> next = nextNode;

    prevNode -> next = newNode;
    nextNode -> pre = newNode;

    return newNode;
}

DuoList *initDuolist(Node *newNode)
{
    // Node *newNode = initNode(num);
    DuoList *duo  = new DuoList;
    
    duo -> head = newNode;
    duo -> tail = newNode;

    return duo;
}

void printList(Node *firstNode)
{
    Node *p = firstNode;
    while(p != NULL)
    {
        cout << p -> data << " ";
        p = p -> next;
    }
}

int main()
{
    int n, firstNum, tempNum, k, x;

    cin >> n >> firstNum;

    Node *firstNode = initNode(firstNum);
    Node *p = firstNode;

    DuoList *duoL = initDuolist(firstNode);

    for(int i=1; i<n; i++)
    {
        cin >> tempNum;
        p = addElement(p,duoL,tempNum);
    }

    cin >> k >> x;

    if( k == 0 )
    {
        addHead(duoL,x);
    }else if( k == n )
    {
        addTail(duoL,x);
    }else
    {
        addAt(duoL,x,k);
    }

    printList(duoL -> head);

}