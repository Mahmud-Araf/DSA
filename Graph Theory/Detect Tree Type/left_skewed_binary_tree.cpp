// implementation of detecting if a binary tree is left skewed

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;
};

bool isLeftSkewed(node *root)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->right == NULL)
    {
        return isLeftSkewed(root->left);
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

    root->left = node2;
    node2->left = node3;
    node3->left = node4;
    node4->left = node5;

    // Check if the tree is a left skewed binary tree
    if (isLeftSkewed(root))
        cout << "The binary tree is a left skewed binary tree." << endl;
    else
        cout << "The binary tree is not a left skewed binary tree." << endl;

    return 0;
}
