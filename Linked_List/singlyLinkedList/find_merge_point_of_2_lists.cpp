#include <iostream>

#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>

using namespace std;

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

// true
// https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/problem?isFullScreen=true&h_r=next-challenge&h_v=zen

// idea :

int findMergeNode(SinglyLinkedListNode *head1, SinglyLinkedListNode *head2)
{
    SinglyLinkedListNode *runner1 = head1;
    SinglyLinkedListNode *runner2 = head2;

    for (; runner1 != NULL; runner1 = runner1->next)
    {
        runner2 = head2;

        for (; runner2 != NULL; runner2 = runner2->next)
        {

            if (runner1 == runner2)
                return runner1->data;
        }
    }

    return 0;
}

int main()
{
    int i1 = 6;
    int *p1 = &i1;
    int *p2 = &i1;

    bool isTrue = p1 == p2;
    cout << isTrue;
}
