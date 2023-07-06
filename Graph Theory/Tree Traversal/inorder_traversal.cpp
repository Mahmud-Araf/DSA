// implementation of inorder traversal in binary tree

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

void inorder(node* n)
{
    if(n==NULL)
    {
         return;
    }

    inorder(n->left);

    cout<<n->data<<" ";

    inorder(n->right);
}