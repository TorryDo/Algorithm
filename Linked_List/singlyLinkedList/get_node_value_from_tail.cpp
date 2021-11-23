#include <iostream>

#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>

using namespace std;

// true
// https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail/problem?isFullScreen=true&h_r=next-challenge&h_v=zen

class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

// solution 1 : use vector
int getNode(SinglyLinkedListNode *llist, int positionFromTail)
{

    SinglyLinkedListNode *root = llist;

    vector<int> pList;

    while (true)
    {
        pList.push_back(root->data);
        if (root->next == 0)
            break;
        root = root->next;
    }

    return pList[pList.size() - 1 - positionFromTail];
}

// solution 2 : use logic
int getNode(SinglyLinkedListNode *llist, int positionFromTail)
{

    SinglyLinkedListNode *current = llist;
    SinglyLinkedListNode *runner = llist;

    for(int i=0; runner != 0; i++){
        runner = runner->next;
        if(i>positionFromTail) current = current->next;
    }

    return current->data;
}

int main()
{

    return 0;
}