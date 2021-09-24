#include <iostream>

using namespace std;

struct node{
    int data;
    node *next;
};

node *initNode(int x){
    node *temp = new node;
    temp -> next = NULL;
    temp -> data = x;

    return temp;
}

node *addElement(node *p, int x){
    node *temp = initNode(x);
    p -> next = temp;
    return temp;
}

void printList(node *l)
{
    node *p = l;
    while(p != NULL){
        cout << p -> data << " ";
        p = p -> next;
    }
}
int main(){

    int n,x;
    cin >> n >> x;

    node *l = initNode(x);
    node *p = l;

    for(int i=1; i<n; i++)
    {
        cin >> x;
        p = addElement(p, x);
    }
    
    printList(l);
    return 0;
}