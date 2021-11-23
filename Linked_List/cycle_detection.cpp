#include <iostream>

#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>

using namespace std;

// 
// https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/problem?isFullScreen=true&h_r=next-challenge&h_v=zen
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

bool has_cycle(SinglyLinkedListNode *head)
{
}

int main()
{

    return 0;
}