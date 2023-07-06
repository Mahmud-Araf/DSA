// implementation of detecting if a binary tree is right skewed

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;
};

bool isRightSkewed(node *root)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->left == NULL)
    {
        return isRightSkewed(root->right);
    }
    else
    {
        return false;
    }
}

int main()
{
    // Create the binary tree
    node *root = new node();
    root->data = 1;

    node *node2 = new node();
    node2->data = 2;

    node *node3 = new node();
    node3->data = 3;

    node *node4 = new node();
    node4->data = 4;

    node *node5 = new node();
    node5->data = 5;

    root->right = node2;
    node2->right = node3;
    node3->right = node4;
    node4->right = node5;

    // Check if the tree is a right skewed binary tree
    if (isRightSkewed(root))
        cout << "The binary tree is a right skewed binary tree." << endl;
    else
        cout << "The binary tree is not a right skewed binary tree." << endl;

    return 0;
}
