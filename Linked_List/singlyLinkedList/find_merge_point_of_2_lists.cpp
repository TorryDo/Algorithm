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

// 
// https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/problem?isFullScreen=true&h_r=next-challenge&h_v=zen

// idea :  


int findMergeNode(SinglyLinkedListNode *head1, SinglyLinkedListNode *head2)
{
    SinglyLinkedListNode *temp1 = head1;
    SinglyLinkedListNode *temp2 = head2;

    while(temp1 != 0){

        while(temp2 != 0){
            if(&temp1 == &temp2){
                return temp1->data;
            }
            temp2 = temp2->next;
        }

        temp1 = temp1->next;
    }

    return -1;
}
