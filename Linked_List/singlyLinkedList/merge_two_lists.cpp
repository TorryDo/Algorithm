#include <iostream>

#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>

using namespace std;

// true
// https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists/problem?isFullScreen=true

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

SinglyLinkedListNode *mergeLists(SinglyLinkedListNode *head1, SinglyLinkedListNode *head2)
{

    if (head1 == 0 && head2 != 0)
    {
        return head2;
    }
    else if (head1 != 0 && head2 == 0)
    {
        return head1;
    }
    else if (head1 == 0 && head2 == 0)
    {
        return 0;
    }

    SinglyLinkedListNode *root;

    if (head1->data < head2->data)
    {
        root = head1;
        root->next = mergeLists(head1->next, head2);
    }
    else
    {
        root = head2;
        root->next = mergeLists(head1, head2->next);
    }

    return root;
}