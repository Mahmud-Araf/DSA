// implementation of avl tree using linked list

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;

    Node()
    {
        data = 0;
        left = NULL;
        right = NULL;
        height = -1;
    }

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

class AVL_Tree
{

private:
    
    int getBF(Node *node) // Balance Factor
    {
        if (node == NULL)
        {
            return 0;
        }

        return (getHeight(node->left) - getHeight(node->right));
    }

    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *t = x->right;

        x->right = y;
        y->left = t;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *t = y->left;

        y->left = x;
        x->right = t;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return y;
    }

    Node *emplace(Node *parent, int val)
    {
        if (parent == NULL)
        {
            parent = new Node(val);
            return parent;
        }

        if (val < parent->data)
        {
            parent->left = emplace(parent->left, val);
        }
        else if (val >= parent->data)
        {
            parent->right = emplace(parent->right, val);
        }

        parent->height = 1 + max(getHeight(parent->left), getHeight(parent->right));

        int bf = getBF(parent);

        // left-left case
        if (bf > 1 && val < (parent->left->data))
        {
            return parent = rightRotate(parent);
        }

        // left-right case
        if (bf > 1 && val > (parent->left->data))
        {
            parent->left = leftRotate(parent->left);
            return parent = rightRotate(parent);
        }

        // right-right case
        if (bf < -1 && val > (parent->right->data))
        {
            return parent = leftRotate(parent);
        }

        // right-left case
        if (bf < -1 && val < (parent->right->data))
        {
            parent->right = rightRotate(parent->right);
            return parent = leftRotate(parent);
        }

        return parent;
    }

    Node *remove(Node *node, int x)
    {
        if (node == NULL)
        {
            return NULL;
        }

        if (x < node->data)
        {
            node->left = remove(node->left, x);
        }
        else if (x > node->data)
        {
            node->right = remove(node->right, x);
        }
        else
        {

            if (node->left == NULL && node->right == NULL)
            {
                free(node);
                return NULL;
            }
            else if (node->left != NULL && node->right == NULL)
            {
                Node *temp = node->left;
                free(node);
                return temp;
            }
            else if (node->left == NULL && node->right != NULL)
            {
                Node *temp = node->right;
                free(node);
                return temp;
            }

            Node *temp = findMinNode(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int bf = getBF(node);

        // left-left case
        if (bf > 1 && getBF(node->left) > 0)
        {
            return node = rightRotate(node);
        }

        // left-right case
        if (bf > 1 && getBF(node->left) < 0)
        {
            node->left = leftRotate(node->left);
            return node = rightRotate(node);
        }

        // right-right case
        if (bf < -1 and getBF(node->right) < 0)
        {
            return node = leftRotate(node);
        }

        // right-left case
        if (bf < -1 and getBF(node->right) > 0)
        {
            node->right = rightRotate(node->right);
            return node = leftRotate(node);
        }

        return node;
    }

public:
    Node *root;

    AVL_Tree()
    {
        root = NULL;
    }

    int getHeight(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }

        return node->height;
    }

    void insert(int val)
    {
        root=emplace(root,val);
    }

    
    void deleteNode(int val)
    {
        root=remove(root,val);
    }
    

    Node *findMinNode(Node *parent)
    {
        Node *curr = parent;

        while (curr->left != NULL)
        {
            curr = curr->left;
        }

        return curr;
    }

    bool search(Node *parent, int x)
    {
        if (parent == NULL)
        {
            return false;
        }

        if (parent->data == x)
        {
            return true;
        }

        if (parent->data > x)
        {
            return search(parent->left, x);
        }
        else
        {
            return search(parent->right, x);
        }
    }

    

    void print_inorder(Node *node)
    {
        if (node == NULL)
        {
            return;
        }

        print_inorder(node->left);

        cout << node->data << " ";

        print_inorder(node->right);
    }

    void print_level(Node *node, int level)
    {
        if (node == NULL)
        {
            return;
        }
        if (level == 1)
        {
            cout << node->data << " ";
            return;
        }
        else if (level > 1)
        {
            print_level(node->left, level - 1);
            print_level(node->right, level - 1);
        }
    }

    void print_tree()
    {
        int h=getHeight(root);

        for(int i=1;i<=h;i++)
        {
            print_level(root,i);
            cout<<endl;
        }
    }
};

int main()
{
     AVL_Tree tree;

    // Insert values into the tree
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    tree.print_tree();

    tree.deleteNode(40);
    
    tree.print_tree();
}
