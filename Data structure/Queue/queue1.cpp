// implementation of Queue using linked list

#include <bits/stdc++.h>
using namespace std;
class node
{
    public:
        int data;
        node *next;

        node(int x)
        {
            data = x;
            next = NULL;
        }

        node()
        {
            next = NULL;
        }
};

class Queue
{
    private:
        int size = 0;
        node *rear = new node();
        node *front = new node();

    public:
        Queue()
        {
            rear = NULL;
            front = NULL;
        }
        int getsize()
        {
            return size;
        }

        void push(int data)
        {
            node *new_node = new node(data);
            new_node->next = NULL;
            if(rear!=NULL)
            {
              rear->next= new_node;
            }
            rear=new_node;
            if (front == NULL)
            {
                front = new_node;
            }
            size++;
        }

        void pop()
        {
            if(empty())
            {
                return;
            }
            node*del=front;
            front=del->next;
            free(del);
            size--;
        }

        int peek()
        {
            return front->data;
        }

        bool empty()
        {
            return (size == 0) ? true : false;
        }

        void clear()
        {
            node *t = front;

            front=NULL;
            rear=NULL;

            while (t != NULL)
            {
                node *del = t;
                t = del->next;
                free(del);
            }
            size = 0;
        }

        bool search(int x)
        {
            node *t =front;

            while (t != NULL)
            {
                if (t->data == x)
                {
                    return true;
                }
                t = t->next;
            }

            return false;
        }

        void print()
        {
            node *t = front;

            while (t != NULL)
            {
                cout << t->data << " ";
                t = t->next;
            }
            cout << endl;
        }
};
