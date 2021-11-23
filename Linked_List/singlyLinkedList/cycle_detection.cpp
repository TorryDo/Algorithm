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
// https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/problem?isFullScreen=true&h_r=next-challenge&h_v=zen

// idea :  Floyd’s Cycle detection algorithm
// - create 2 pointer, the first one has step = 1, the second one has step = 2
// - if they meet each other, the linkedlist has a cycle

// q: line 41 : Why && instead of || ?
// a: both pointers must not be null

bool has_cycle(SinglyLinkedListNode *head)
{
    if (head == 0)
        return 0;

    SinglyLinkedListNode *slow = head;
    SinglyLinkedListNode *fast = head;

    while (slow != 0 && fast != 0)
    {

        slow = slow->next;
        try
        {
            if (fast->next == 0)
                throw 0;
            if (fast->next->next == 0)
                throw 0;
            fast = fast->next->next;
        }
        catch (int n)
        {
            fast = 0;
        }

        if (slow == fast)
            return 1;
    }

    return 0;
}
