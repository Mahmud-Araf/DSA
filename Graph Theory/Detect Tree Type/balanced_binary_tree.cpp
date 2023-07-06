// implementation of detecting if a binary tree is balanced

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

bool isBalancedBinary(node *root)
{
    set<int> st;
    int l = 0;
    level_checker(root, st, l);
    if (st.size() == 2)
    {
        auto it = st.begin();
        int t1 = *it;
        int t2 = *(++it);

        return abs(t1 - t2) <= 1 ? true : false;
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

    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node4->left = node5;
    node5->right = node6;

    // Check if the tree is a balanced binary tree
    if (isBalancedBinary(root))
        cout << "The binary tree is a balanced binary tree." << endl;
    else
        cout << "The binary tree is not a balanced binary tree." << endl;

    return 0;
}
