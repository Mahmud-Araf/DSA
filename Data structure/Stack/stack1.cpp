// implementation of stack using linked list

#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
        int data;
        node*prev;

        node(int x)
        {
            data=x;
            prev=NULL;
        }

        node()
        {
          prev=NULL;
        }
};


class Stack
{
    private:

        int size=0;
        node*top=new node();
        
    public:

        Stack()
        {
            top=NULL;
        }
        int getsize()
        {
          return size;
        }

        void push(int data)
        {
            node*new_node=new node(data);
            new_node->prev=top;
            top=new_node;
            size++;
        }

        void pop()
        {
            if(top==NULL)
            {
                return;
            }

            node*del=top;
            top=del->prev;
            free(del);
            size--;
        }

        int peek()
        {
            return top->data;
        }

        bool empty()
        {
            return (size==0)? true:false;
        }

        void clear()
        {
            node*t=top;
            top=NULL;

            while(t!=NULL)
            {
                node*del=t;
                t=del->prev;
                free(del);
            }
            size=0;
        }

        bool search(int x)
        {
            node*t=top;

            while(t!=NULL)
            {
                if(t->data==x)
                {
                    return true;
                }
                t=t->prev;
            }

            return false;
        }

        void print()
        {
            node*t=top;

            while(t!=NULL)
            {
                cout<<t->data<<" ";
                t=t->prev;
            }
            cout<<endl;
        }   
};
