// implementation of priority queue using linked list

#include<bits/stdc++.h>
using namespace std;

class node
{

 public:
   int data;
   int priority;
   node*next;

   node(int data,int priority)
   {
     this->data=data;
     this->priority=priority;
     next=NULL;
   }
};

class Priority_Queue
{
  private:

        node*front;
        int size;

  public:
    
   Priority_Queue()
    {
        front=NULL;
        size=0;
    }

    int getsize()
    {
        return size;
    }

    void push(int d,int p)
    {
         node* new_node= new node(d,p);

         if(front==NULL)
         {
            front=new_node;
         }
         else if(front->priority<p)
         {
            new_node->next=front;
            front=new_node;
         }
         else
         {
            node* current=front;

            while(current->next!=NULL && current->next->priority>=p)
            {
                current=current->next;
            }

            new_node->next=current->next;
            current->next=new_node;

         }

         size++;   
    }

    void pop()
    {
        if(size==0)
        {
            return;
        }
        node* del=front;
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
        return size==0?false:true;
    }

    void clear()
    {
        size=0;
        node* temp=front;
        front=NULL;
        while(temp->next!=0)
        {
            node* del=temp;
            temp=temp->next;
            free(del);
        }
    }

    void print()
    {
        node* it=front;

        while(it!=NULL)
        {
            cout<<it->data<<" ";
            it=it->next;
        }
        cout<<endl;
    }
};
