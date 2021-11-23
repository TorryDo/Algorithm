#include <iostream>

#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>

using namespace std;

// true
// https://www.hackerrank.com/challenges/delete-duplicate-value-nodes-from-a-sorted-linked-list/problem?isFullScreen=true



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

SinglyLinkedListNode *removeDuplicates(SinglyLinkedListNode *llist)
{
    if(llist == 0) return 0;
    if(llist->next == 0) return llist;
    if(llist->data == llist->next->data) return removeDuplicates(llist->next);

    llist->next = removeDuplicates(llist->next);

    return llist;
}

int main()
{

    return 0;
}