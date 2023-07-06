// implementation of fibonacci heap using circular doubly linked list

#include<bits/stdc++.h>
using namespace std;

// class structure of a node
class node {
public:
	node* parent; 
	node* child; 
	node* left; 
	node* right; 
	int data; 
	int degree; 
	char mark; 
	char c; 
};

class FibonacciMinHeap
{

public:

    node* minNode = NULL;

    // an integer for number of nodes in the heap
    int nodeNumber = 0;

    // function to insert a node in heap
    void insertion(int val)
    {
        node* new_node = new node();
        new_node->data = val;
        new_node->degree = 0;
        new_node->mark = 'W';
        new_node->c = 'N';
        new_node->parent = NULL;
        new_node->child = NULL;
        new_node->left = new_node;
        new_node->right = new_node;
        if (minNode != NULL) 
        {
            (minNode->left)->right = new_node;
            new_node->right = minNode;
            new_node->left = minNode->left;
            minNode->left = new_node;
            if (new_node->data < minNode->data)
                minNode = new_node;
        }
        else {
            minNode = new_node;
        }
        nodeNumber++;
    }

    // linking the heap nodes in parent child relationship
    void Fibonacci_Link(struct node* ptr2, struct node* ptr1)
    {
        (ptr2->left)->right = ptr2->right;
        (ptr2->right)->left = ptr2->left;
        if (ptr1->right == ptr1)
        {
            minNode = ptr1;
        }
        ptr2->left = ptr2;
        ptr2->right = ptr2;
        ptr2->parent = ptr1;
        if (ptr1->child == NULL)
        {
            ptr1->child = ptr2;
        }
        ptr2->right = ptr1->child;
        ptr2->left = (ptr1->child)->left;
        ((ptr1->child)->left)->right = ptr2;
        (ptr1->child)->left = ptr2;
        if (ptr2->data < (ptr1->child)->data)
        {
           ptr1->child = ptr2;
        }
            
        ptr1->degree++;
    }

    // consolidating the heap
    void consolidate()
    {
        int temp1;
        float temp2 = (log(nodeNumber)) / (log(2));
        int temp3 = temp2;
        struct node* arr[temp3+1];
        for (int i = 0; i <= temp3; i++)
            arr[i] = NULL;
        node* ptr1 = minNode;
        node* ptr2;
        node* ptr3;
        node* ptr4 = ptr1;
        do {
            ptr4 = ptr4->right;
            temp1 = ptr1->degree;
            while (arr[temp1] != NULL) {
                ptr2 = arr[temp1];
                if (ptr1->data > ptr2->data) {
                    ptr3 = ptr1;
                    ptr1 = ptr2;
                    ptr2 = ptr3;
                }
                if (ptr2 == minNode)
                    minNode = ptr1;
                Fibonacci_Link(ptr2, ptr1);
                if (ptr1->right == ptr1)
                    minNode = ptr1;
                arr[temp1] = NULL;
                temp1++;
            }
            arr[temp1] = ptr1;
            ptr1 = ptr1->right;
        } while (ptr1 != minNode);

        minNode = NULL;
        for (int j = 0; j <= temp3; j++) {
            if (arr[j] != NULL)
            {
                arr[j]->left = arr[j];
                arr[j]->right = arr[j];

                if (minNode != NULL) 
                {
                    (minNode->left)->right = arr[j];
                    arr[j]->right = minNode;
                    arr[j]->left = minNode->left;
                    minNode->left = arr[j];
                    if (arr[j]->data < minNode->data)
                        minNode = arr[j];
                }
                else 
                {
                    minNode = arr[j];
                }
                if (minNode == NULL)
                    minNode = arr[j];
                else if (arr[j]->data < minNode->data)
                    minNode = arr[j];
            }
        }
    }

    // function to extract minimum node in the heap
    void extract_min()
    {
        if (minNode == NULL)
            cout << "The heap is empty" << endl;
        else {
            node* temp = minNode;
            node* pntr;
            pntr = temp;
            node* x = NULL;
            if (temp->child != NULL) {

                x = temp->child;
                do {
                    pntr = x->right;
                    (minNode->left)->right = x;
                    x->right = minNode;
                    x->left = minNode->left;
                    minNode->left = x;
                    if (x->data < minNode->data)
                        minNode = x;
                    x->parent = NULL;
                    x = pntr;
                } while (pntr != temp->child);
            }
            (temp->left)->right = temp->right;
            (temp->right)->left = temp->left;
            minNode = temp->right;
            if (temp == temp->right && temp->child == NULL)
                minNode = NULL;
            else {
                minNode = temp->right;
                consolidate();
            }
            nodeNumber--;
        }
    }

    // cutting a node in the heap to be placed in the root list
    void cut(struct node* found, struct node* temp)
    {
        if (found == found->right)
            temp->child = NULL;

        (found->left)->right = found->right;
        (found->right)->left = found->left;
        if (found == temp->child)
            temp->child = found->right;

        temp->degree = temp->degree - 1;
        found->right = found;
        found->left = found;
        (minNode->left)->right = found;
        found->right = minNode;
        found->left = minNode->left;
        minNode->left = found;
        found->parent = NULL;
    }

    // recursive cascade cutting function
    void cascase_cut(struct node* temp)
    {
        node* ptr5 = temp->parent;
        if (ptr5 != NULL) {
            if (temp->mark == 'W') {
                temp->mark = 'B';
            }
            else {
                cut(temp, ptr5);
                cascase_cut(ptr5);
            }
        }
    }

    // function to decrease the value of a node in the heap
    void decrease_key(struct node* found, int val)
    {
        if (minNode == NULL)
            cout << "The Heap is Empty" << endl;

        if (found == NULL)
            cout << "Node not found in the Heap" << endl;

        found->data = val;

        struct node* temp = found->parent;
        if (temp != NULL && found->data < temp->data) {
            cut(found, temp);
            cascase_cut(temp);
        }
        if (found->data < minNode->data)
            minNode = found;
    }

    //Function to reset color 
    void resetColors(struct node* mini) 
    {
        if (mini == NULL) return;
        mini->c = 'N';
        resetColors(mini->child);
        resetColors(mini->right);
    }


    // Function to find the given node
    void findNode(struct node* mini, int old_val, int val)
    {
        struct node* found = NULL;
        node* temp5 = mini;
        temp5->c = 'Y';
        node* found_ptr = NULL;
        if (temp5->data == old_val) {
            found_ptr = temp5;
            temp5->c = 'N';
            found = found_ptr;
            decrease_key(found, val);
        }
        if (found_ptr == NULL) {
            if (temp5->child != NULL)
                findNode(temp5->child, old_val, val);
            if ((temp5->right)->c != 'Y')
                findNode(temp5->right, old_val, val);
        }
        temp5->c = 'N';
        found = found_ptr;
    }

    // deleting a node from the heap
    void deletion(int val)
    {
        if (minNode == NULL)
            cout << "The heap is empty" << endl;
        else {

            // decreasing the value of the node to 0
            findNode(minNode, val, 0);

            // calling Extract_min function to
            // delete minimum value node, which is 0
            extract_min();
            cout << "Key Deleted" << endl;
        }
    }

    // function to display the heap
    void display()
    {
        node* ptr = minNode;
        if (ptr == NULL)
            cout << "The Heap is Empty" << endl;

        else {
            cout << "The root nodes of Heap are: " << endl;
            do {
                cout << ptr->data;
                ptr = ptr->right;
                if (ptr != minNode) {
                    cout << "-->";
                }
            } while (ptr != minNode && ptr->right != NULL);
            cout << endl
                << "The heap has " << nodeNumber << " nodes" << endl;
        }
    }
  
};


int main()
{
    FibonacciMinHeap heap;

    // Insert some values into the heap
    heap.insertion(10);
    heap.insertion(20);
    heap.insertion(30);
    heap.insertion(40);
    heap.insertion(50);

    // Display the contents of the heap
    cout << "Contents of the heap after inserting 5 elements: " << endl;
    cout<<"min element"<<": "<<heap.minNode->data<<endl;
    heap.display();


    // Extract the minimum element from the heap
     heap.extract_min();

    // Display the contents of the heap after extracting minimum element
    cout << "Contents of the heap after extracting minimum element: " << endl;
    cout<<"min element"<<": "<<heap.minNode->data<<endl;
    heap.display();

    // Insert some more values into the heap
    heap.insertion(5);
    heap.insertion(25);
    heap.insertion(35);
    heap.insertion(15);
    heap.insertion(45);

    // Display the contents of the heap after inserting more elements
    cout << "Contents of the heap after inserting 5 more elements: " << endl;
    heap.display();

    // Decrease the value of an element in the heap
    heap.deletion(40);

    // Display the contents of the heap after decreasing key
    cout << "Contents of the heap after decreasing key of an element: " << endl;
    heap.display();

    return 0;
}

