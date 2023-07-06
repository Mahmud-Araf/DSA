// implementation of binary search tree using linked list

#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

class bst
{
private:

    node *emplace(node *parent, int data)
    {
        
        if(parent==NULL)
        {
            node * new_node = new node(data);
            parent=new_node;
            return parent;
        }

        if(parent->data<data)
        {
            parent->right=emplace(parent->right,data);
        }
        else if(parent->data>=data)
        {
            parent->left=emplace(parent->left,data);
        }

        return parent;
    }

    node *remove(node *parent,int x)
    {
        if(parent==NULL)
        {
            return NULL;
        }

        if(parent->data>x)
        {
          parent->left=remove(parent->left,x);
        }
        else if(parent->data<x)
        {
            parent->right=remove(parent->right,x);
        }
        else
        {
            if(parent->left==NULL and parent->right==NULL)
            {
                return NULL;
            }
            else if(parent->left==NULL)
            {
                node *temp=parent->right;
                free(parent);
                return temp;
            }
            else if(parent->right==NULL)
            {
                node *temp=parent->left;
                free(parent);
                return temp;
            }

            node *temp=parent->right;

            while(temp && temp->left!=NULL)
            {
                temp=temp->left;
            }

            parent->data=temp->data;

            parent->right=remove(parent->right,temp->data);

        }

        return parent;
        
    }

public:

    node *root;

    bst()
    {
        root=NULL;
    }

    

    void insert(int data)
    {
        root=emplace(root,data);
    }

    bool search(node *parent,int x)
    {
        if(parent==NULL)
        {
            return false;
        }

        if(parent->data==x)
        {
            return true;
        }

        if(parent->data>x)
        {
           return search(parent->left,x);
        }
        else 
        {
            return search(parent->right,x);
        }
    }


    void deleteNode(int data)
    {
        root=remove(root,data);
    }

    void print_inorder(node* n)
    {
        if(n==NULL)
        {
            return;
        }

        print_inorder(n->left);

        cout<<n->data<<" ";

        print_inorder(n->right);
    }
};

int main()
{
    bst tree;

    // insert some elements into the BST
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    // print the elements of the BST in inorder traversal
    cout<<"Inorder traversal of the BST: ";
    tree.print_inorder(tree.root);
    cout<<endl;

    // search for an element in the BST
    int x=40;
    if(tree.search(tree.root,x))
    {
        cout<<x<<" is present in the BST."<<endl;
    }
    else
    {
        cout<<x<<" is not present in the BST."<<endl;
    }

    // delete an element from the BST
    int y=20;
    tree.deleteNode(y);
    cout<<"Inorder traversal of the BST after deleting "<<y<<": ";
    tree.print_inorder(tree.root);
    cout<<endl;

    // search for the deleted element in the BST
    if(tree.search(tree.root,y))
    {
        cout<<y<<" is present in the BST."<<endl;
    }
    else
    {
        cout<<y<<" is not present in the BST."<<endl;
    }

    return 0;
}
