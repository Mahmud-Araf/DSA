// implementation of postorder traversal in binary tree

#include<bits/stdc++.h>
using namespace std;

class node
{

  public:
    int data;
    node* left;
    node* right;

    node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }

};

void postorder(node* n)
{
    if(n==NULL)
    {
        return;
    }

    postorder(n->left);

    postorder(n->right);

    cout<<n->data<<" ";
}