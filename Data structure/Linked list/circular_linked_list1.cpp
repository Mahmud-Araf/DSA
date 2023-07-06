//implementation of circular linked list using dynamic memory allocation

#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node*next;

    node()
    {
      next=NULL;
    }

};

class cll
{
    public:

    node*head=NULL;
    int size=0;

    void push_front(int data)
    {
        size++;
        node*new_node=new node();

        new_node->data=data;

        if(head==NULL)
        {
            head=new_node;
            head->next=head;
            return;
        }
        node*temp=head;

        while(temp->next!=head)
        {
            temp=temp->next;
        }

        temp->next=new_node;
        new_node->next=head;
        head=new_node;
    }

    void push(int indx,int data)
    {
        if(indx<1||indx>size && size!=0)
        {
            return;
        }

        size++;

        node*temp=head;
        node*new_node=new node();
        new_node->data=data;

        if(temp==NULL)
        {
            head=new_node;
            head->next=head;
            return;
        }

        for(int i=1;i<indx;i++)
        {
            temp=temp->next;
        }

        new_node->next=temp->next;
        temp->next=new_node;
    }

    void push_back(int data)
    {
        size++;
        node*new_node=new node();

        new_node->data=data;

        if(head==NULL)
        {
            head=new_node;
            head->next=head;
            return;
        }

        new_node->next=head;

        node*temp=head;

        while(temp->next!=head)
        {
            temp=temp->next;
        }

        temp->next=new_node;
    }

    bool search(int x)
    {
        node*i=head;

        while(i->next!=head)
        {
           if(i->data==x)
           {
             return true;
           }
           i=i->next;
        }

        return false;
        
    }

    void remove_data(int x)
    {
       node*i=head;

       if(i->data==x)
       {
         head=i->next;
         free(i);
         return;
       }

       while(i->next!=head)
       {
         if(i->next->data==x)
         {
            break;
         }
         i=i->next;
       }

       if(i->next==head)
       {
        return;
       }
    
       node*temp=i->next;

       i->next=temp->next;

       free(temp);
       size--;
    }

    void remove(int indx)
    {
        if(indx<1 || indx>size)
        {
            return;
        }
        size--;
        node*temp=head;

        node*last=head;
        while(last->next!=head)
        {
            last=last->next;
        }
        if(indx==1)
        {
            head=temp->next;
            last->next=head;
            free(temp);
            return;
        }

        for(int i=1;i<indx-1;i++)
        {
            temp=temp->next;
        }

        node*del=temp->next;

        temp->next=del->next;

        free(del);
    }

    void remove_front()
    {
        node*temp=head;

        while(temp->next!=head)
        {
            temp=temp->next;
        }

        temp->next=head->next;

        temp=head;
        head=temp->next;
        free(temp);
        size--;

    }

    void remove_back()
    {
        node*temp=head;

        while(temp->next->next!=head)
        {
            temp=temp->next;
        }

        node*last=temp->next;
        temp->next=head;
        free(last);
        size--;
    }

    void print()
    {
        node*i=head;

        cout<<i->data;

        i=i->next;

        while(i->next!=head->next)
        {
            cout<<" "<<i->data;
            i=i->next;
        }
        
        cout<<endl;
    }
    
};

