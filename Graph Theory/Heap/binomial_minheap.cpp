// implementation of binomial min heap using linked list

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    int degree;
    node *parent;
    node *rightSibling;
    node *leftChild;

    node(int data)
    {
        this->data = data;
        degree = 0;
        parent = rightSibling = leftChild = NULL;
    }
};

class Binomial_MinHeap
{
public:
    node *root;

    node *mergeRootList(node *root1, node *root2)
    {
        node *root3 = new node(0);
        node *temp = root3;

        while (root1 != NULL && root2 != NULL)
        {
            if (root1->degree <= root2->degree)
            {
                temp->rightSibling = root1;
                root1 = root1->rightSibling;
            }
            else
            {
                temp->rightSibling = root2;
                root2 = root2->rightSibling;
            }

            temp = temp->rightSibling;
        }

        while (root1 != NULL)
        {
            temp->rightSibling = root1;
            root1 = root1->rightSibling;
            temp = temp->rightSibling;
        }
        while (root2 != NULL)
        {
            temp->rightSibling = root2;
            root2 = root2->rightSibling;
            temp = temp->rightSibling;
        }

        return root3->rightSibling;
    }

    node *findMinNode()
    {
        node *min = root;

        node *temp = root;

        while (temp != NULL)
        {
            if (temp->data < min->data)
            {
                min = temp;
            }
            temp = temp->rightSibling;
        }

        return min;
    }

    node *reverse(node *root1)
    {
        stack<node *> st;
        while (root1 != NULL)
        {
            st.push(root1);
            root1 = root1->rightSibling;
        }
        if (st.empty())
        {
            return NULL;
        }
        node *newRoot = st.top();
        node *prev = newRoot;
        st.pop();
        while (!st.empty())
        {
            prev->rightSibling = st.top();
            st.pop();
            prev = prev->rightSibling;
        }
        prev->rightSibling = NULL;
        return newRoot;
    }

    Binomial_MinHeap()
    {
        root = NULL;
    }

    void _union(Binomial_MinHeap *other)
    {
        node *root1 = this->root;
        node *root2 = other->root;

        node *newRoot = mergeRootList(root1, root2);
        this->root = newRoot;

        if (newRoot == NULL)
        {
            return;
        }

        node *prev = NULL;
        node *curr = newRoot;
        node *next = curr->rightSibling;

        while (next != NULL)
        {
            if (curr->degree != next->degree || (next->rightSibling != NULL && next->rightSibling->degree == curr->degree))
            {
                prev = curr;
                curr = next;
            }
            else if (curr->data <= next->data)
            {
                curr->rightSibling = next->rightSibling;
                next->parent = curr;
                next->rightSibling = curr->leftChild;
                curr->leftChild = next;
                curr->degree++;
            }
            else
            {
                if (prev == NULL)
                {
                    newRoot = next;
                }
                else
                {
                    prev->rightSibling = next;
                }
                curr->parent = next;
                curr->rightSibling = next->leftChild;
                next->leftChild = curr;
                next->degree++;
                curr = next;
            }

            next = curr->rightSibling;
        }

        this->root = newRoot;
    }

    int findMin()
    {
        return findMinNode()->data;
    }

    int extractMin()
    {
        node *curr = root;
        node *prevMin = NULL;
        node *minPtr = NULL;
        node *prevPtr = NULL;
        int min = INT_MAX;

        if (curr == NULL)
        {
            return INT_MIN;
        }

        while (curr != NULL)
        {
            if (curr->data <= min)
            {
                min = curr->data;
                prevMin = prevPtr;
                minPtr = curr;
            }
            prevPtr = curr;
            curr = curr->rightSibling;
        }

        if (prevMin != NULL && minPtr->rightSibling != NULL)
        {
            prevMin->rightSibling = minPtr->rightSibling;
        }
        else if (prevMin != NULL && minPtr->rightSibling == NULL)
        {
            prevMin->rightSibling = NULL;
        }
        else if (prevMin == NULL and minPtr->rightSibling != NULL)
        {
            root = minPtr->rightSibling;
        }
        else if (prevMin == NULL and minPtr->rightSibling == NULL)
        {
            root = NULL;
        }

        node *childPtr = minPtr->leftChild;

        while (childPtr != NULL)
        {
            childPtr->parent = NULL;
            childPtr = childPtr->rightSibling;
        }

        childPtr = minPtr->leftChild;
        node *newRoot = reverse(childPtr);

        Binomial_MinHeap *newHeap = new Binomial_MinHeap();

        newHeap->root = newRoot;

        _union(newHeap);

        free(minPtr);

        return min;
    }

    void insert(int data)
    {
        Binomial_MinHeap *newHeap = new Binomial_MinHeap();
        newHeap->root = new node(data);
        _union(newHeap);
    }

    void decrease_key(node *n, int newdata)
    {
        n->data = newdata;

        while (n->parent != NULL && n->parent->data > n->data)
        {
            swap(n->parent->data, n->data);
            n = n->parent;
        }
    }

    void deleteNode(node *n)
    {
        decrease_key(n, INT_MIN);
        extractMin();
    }

    void display(node *n, int depth = 0)
    {
        if (!n)
        {
            return;
        }

        for (int i = 0; i < depth; i++)
        {
            cout << "  ";
        }

        cout << n->data << endl;

        if (n->leftChild)
        {
            display(n->leftChild, depth + 1);
        }

        if (n->rightSibling)
        {
            display(n->rightSibling, depth);
        }
    }
};

int main()
{
    Binomial_MinHeap heap1;

    // Insert elements
    heap1.insert(4);
    heap1.insert(1);
    heap1.insert(3);
    heap1.insert(2);

    // Find minimum element
    cout << "Minimum element: " << heap1.findMin() << endl;

    // Extract minimum element
    int minElement = heap1.extractMin();
    cout << "Extracted minimum element: " << minElement << endl;
    cout << "New minimum element: " << heap1.findMin() << endl;

    // Create another heap
    Binomial_MinHeap heap2;
    heap2.insert(7);
    heap2.insert(5);
    heap2.insert(6);

    // Union of two heaps
    heap1._union(&heap2);
    cout << "Minimum element after union: " << heap1.findMin() << endl;

    // Print the heap
    cout << "Heap: " << endl;
    heap1.display(heap1.root);
    cout << endl;
    cout << heap1.root->data << endl;
    cout << endl;

    return 0;
}