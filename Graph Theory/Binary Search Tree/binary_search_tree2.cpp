// implementation of binary search tree using array

#include<bits/stdc++.h>
using namespace std;

class bst
{

public:
    int root;
    int *arr;
      
    bst(int k)
    {
        root=1;
        arr= new int[(int)(pow(2,k))+1];
        memset(arr,0,sizeof(arr));
    }

    void insert(int parent,int data)
    {
        if(arr[parent]==0)
        {
            arr[parent]=data;
        }

        if(arr[parent]>data)
        {
            insert(2*parent,data);
        }
        else if(arr[parent]<data)
        {
            insert(2*parent+1,data);
        }
    }

    bool search(int parent,int x)
    {
        if(arr[parent]==0)
        {
            return false;
        }

        if(arr[parent]==x)
        {
            return true;
        }

        if(arr[parent]>x)
        {
            return search(2*parent,x);
        }
        else
        {
            return search(2*parent+1,x);
        }
    }

    int deleteNode(int parent,int x)
    {
        if(arr[parent]==0)
        {
            return 0;
        }

        if(arr[parent]>x)
        {
            arr[2*parent]=deleteNode(2*parent,x);
        }
        else if(arr[parent]<x)
        {
            arr[2*parent+1]=deleteNode(2*parent+1,x);
        }
        else
        {
            if(arr[2*parent]==0 and arr[2*parent+1]==0)
            {
                return 0;
            }
            else if(arr[2*parent]==0)
            {
                arr[parent]=0;
                return arr[2*parent+1];
            }
            else if(arr[2*parent+1]==0)
            {
                arr[parent]=0;
                return arr[2*parent];
            }

            int temp=2*parent+1;

            while(arr[temp] && arr[2*temp])
            {
              temp=2*temp;
            }

            arr[parent]=arr[temp];

            arr[2*parent+1]=deleteNode(2*parent+1,arr[temp]);
        }

        return arr[parent];
        
    }

    void print_inorder(int n)
    {
        if(arr[n]==0)
        {
            return;
        }

        print_inorder(2*n);

        cout<<arr[n]<<" ";

        print_inorder(2*n+1);
    }
};

int main()
{
    bst tree=bst(7);

    // insert some elements into the BST
    tree.insert(tree.root,50);
    tree.insert(tree.root,30);
    tree.insert(tree.root,20);
    tree.insert(tree.root,40);
    tree.insert(tree.root,70);
    tree.insert(tree.root,60);
    tree.insert(tree.root,80);

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
    tree.deleteNode(tree.root,y);
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
