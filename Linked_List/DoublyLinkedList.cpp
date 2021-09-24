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

DuoList *initDuoList(int num)
{
    DuoList *duoList = new DuoList;
    duoList -> head = new Node;
    duoList -> head -> data = num;
    duoList -> head -> next = NULL;
    duoList -> head -> pre  = NULL;

    duoList -> tail = duoList -> head;

    return duoList;
}

Node *initNode(int num)
{
    Node *newNode = new Node;
    newNode -> data= num;
    newNode -> pre = NULL;
    newNode -> next = NULL;

    return newNode; 
}

DuoList *addTail(DuoList *duo, int num)
{
    Node *newNode = new Node;
    newNode -> data = num;
    newNode -> pre = duo -> tail;
    newNode -> next = NULL;

    duo -> tail -> next = newNode;
    duo -> tail  = newNode;

    return duo;
}

DuoList *addHead(DuoList *duo, int num)
{
    Node *newFirstNode = new Node;
    newFirstNode -> data = num;
    newFirstNode -> pre = NULL;
    newFirstNode -> next = duo -> head;

    duo -> head -> pre = newFirstNode;
    duo -> head = newFirstNode;

    return duo; 
}

void printList(DuoList *l)
{
    Node *p = l -> head;
    while(p != NULL)
    {
        cout << p -> data << " ";
        p = p -> next;
    }
}

int main()
{

    int n;
    cin >> n;

    DuoList *duoL = initDuoList(1);

    for(int i=2; i<=n; i++)
    {
        addHead(duoL, i);
        addTail(duoL, i);
    }

    printList(duoL);

    return 0;
}