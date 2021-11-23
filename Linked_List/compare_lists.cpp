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

bool compare_lists(SinglyLinkedListNode *head1, SinglyLinkedListNode *head2)
{
    if(head1 == 0 && head2 == 0) return true;
    if((head1 == 0 && head2 != 0) || (head1 != 0 && head2 == 0)) return false;
    if(head1->data != head2->data) return false;

    return true && compare_lists(head1->next, head2->next);
}

int main()
{

    return 0;
}