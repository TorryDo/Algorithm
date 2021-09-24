#include <iostream>
#include <math.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *insert(Node *node, int num)
{

    if (node == NULL)
    {
        Node *temp = new Node;
        temp->data = num;
        temp->left = NULL;
        temp->right = NULL;

        return temp;
    }
    else
    {
        if (num >= node->data)  // da sua
        {
            node->right = insert(node->right, num);
        }
        else
        {
            node->left = insert(node->left, num);
        }
    }
}

int getTreeLevel(Node *node)
{
    if (node == NULL)
        return -1;

    return 1 + max(getTreeLevel(node->left), getTreeLevel(node->right));
}

bool checkAvl(Node *node)
{
    if (node == NULL)
        return true;
    if (abs(getTreeLevel(node->left) - getTreeLevel(node->right)) > 1)
        return false;
    return checkAvl(node->left) && checkAvl(node->right);
}

Node *turnRight(Node *node)
{
    Node *daddyLeft = node->left;
    Node *childRight = daddyLeft->right;

    node->left = childRight;
    daddyLeft->right = node;

    return daddyLeft;
}

Node *turnLeft(Node *node)
{
    Node *daddyRight = node->right;
    Node *childLeft = daddyRight->left;

    node->right = childLeft;
    daddyRight->left = node;

    return daddyRight;
}

Node *updateAvlTree(Node *node)
{
    if (!checkAvl(node)) // nếu chưa phải avl tree
    {
        if (getTreeLevel(node->left) > getTreeLevel(node->right)) // với treeLeft > treeRight
        {
            Node *p = node->left;

            if (getTreeLevel(p->left) >= getTreeLevel(p->right))
            {
                node = turnRight(node);
            }
            else
            {
                node->left = turnLeft(node->left);
                node = turnRight(node);
            }
        }
        else
        {
            Node *p = node->right;
            if (getTreeLevel(p->right) >= getTreeLevel(p->left))
            {
                node = turnLeft(node);
            }
            else
            {
                node->right = turnRight(node->right);
                node = turnLeft(node);
            }
        }
    }

    if (node->left != NULL)
        node->left = updateAvlTree(node->left);
    if (node->right != NULL)
        node->right = updateAvlTree(node->right);

    return node;
}

int main()
{
    int n, temp;
    cin >> n;
    Node *t = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        t = insert(t, temp);
    }

    while (!checkAvl(t))
    {
        t = updateAvlTree(t);
    }

    cout << getTreeLevel(t);

    return 0;
}