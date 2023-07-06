// implementation of detecting if a binary tree is complete

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;
};

bool isCompleteBinary(node *root)
{
    queue<node *> q;
    q.push(root);
    bool flag = false;
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            flag = true;
        }
        else
        {
            if (flag)
            {
                return false;
            }

            q.push(temp->left);
            q.push(temp->right);
        }
    }
    return true;
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
    root->right = node3;
    node2->left = node4;
    node2->right = node5;

    // Check if the tree is a complete binary tree
    if (isCompleteBinary(root))
        cout << "The binary tree is a complete binary tree." << endl;
    else
        cout << "The binary tree is not a complete binary tree." << endl;

    return 0;
}
