#include <iostream>
#include <math.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *insert(Node *node, int n)
{
    if (node == NULL)
    {
        Node *temp = new Node;

        temp->data = n;
        temp->right = NULL;
        temp->left = NULL;

        return temp;
    }
    else
    {
        if (n < node->data)
            node->left = insert(node->left, n);
        else
            node->right = insert(node->right, n);
    }
}

int getTreeLevel(Node *root)
{
    if (root == NULL)
        return -1;

    return 1 + max(getTreeLevel(root->left), getTreeLevel(root->right));
}

bool isAvlTree(Node *root)
{
    if (root == NULL)
        return true;
    if (abs(getTreeLevel(root->left) - getTreeLevel(root->right)) > 1)
        return false;

    return isAvlTree(root->left) && isAvlTree(root->right);
}

Node *turnRight(Node *root)
{
    Node *daddyLeft = root->left;
    Node *childRight = daddyLeft->right;

    root->left = childRight;
    daddyLeft->right = root;

    return daddyLeft;
}

Node *turnLeft(Node *root)
{
    Node *daddyRight = root->right;
    Node *childLeft = daddyRight->left;

    root->right = childLeft;
    daddyRight->left = root;

    return daddyRight;
}

Node *updateAvlTree(Node *root)
{
    if (!isAvlTree(root))
    {
        if (getTreeLevel(root->left) > getTreeLevel(root->right))
        {
            Node *daddyLeft = root->left;

            if (getTreeLevel(daddyLeft->left) < getTreeLevel(daddyLeft->right))
                root->left = turnLeft(root->left);

            root = turnRight(root);
        }
        else
        {
            delete(root);
            Node *daddyRight = root->right;
            if (getTreeLevel(daddyRight->right) < getTreeLevel(daddyRight->left))
                root->right = turnRight(root->right);

            root = turnLeft(root);
        }
    }

    if (root->left != NULL)
        root->left = updateAvlTree(root->left);
    if (root->right != NULL)
        root->right = updateAvlTree(root->right);

    return root;
}

int count(Node *root, int target)
{
    if (root == NULL)
        return 0;

    if (target == root->data)
        return 1 + count(root->left, target) + count(root->right, target);
    else if (target > root->data)
        return count(root->right, target);

    return count(root->left, target);
}

int main()
{
    int n, target, temp;
    cin >> n;
    Node *node = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        node = insert(node, temp);
    }
    while (!isAvlTree(node))
    {
        node = updateAvlTree(node);
    }
    cin >> target;
    cout << count(node, target);

    return 0;
}