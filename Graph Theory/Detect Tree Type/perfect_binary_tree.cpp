// implementation of detecting if a binary tree is perfect

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;
};

void level_checker(node *root, set<int> &s, int l)
{

    if (root == NULL)
    {
        return;
    }
    if (root != NULL && root->left == NULL && root->right == NULL)
    {

        s.insert(l);
    }
    else
    {
        l++;
        level_checker(root->left, s, l);
        level_checker(root->right, s, l);
    }
}

bool isFullBinary(node *root)
{
    if ((root->left == NULL) && (root->right == NULL))
    {
        return true;
    }
    else if ((root->left == NULL))
    {

        return false;
    }
    else if ((root->right == NULL))
    {
        return false;
    }
    else
    {
        bool t1 = isFullBinary(root->left);
        bool t2 = isFullBinary(root->right);
        return t1 & t2;
    }
}

bool isPerfectBinary(node *root)
{
    if (isFullBinary(root))
    {
        set<int> st;
        int l = 0;

        level_checker(root, st, l);

        if (st.size() == 1)
        {
            return true;
        }
        else
        {
            false;
        }
    }
    return false;
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

    node *node6 = new node();
    node6->data = 6;

    node *node7 = new node();
    node7->data = 7;

    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;

    // Check if the tree is a perfect binary tree
    if (isPerfectBinary(root))
        cout << "The binary tree is a perfect binary tree." << endl;
    else
        cout << "The binary tree is not a perfect binary tree." << endl;

    return 0;
}
