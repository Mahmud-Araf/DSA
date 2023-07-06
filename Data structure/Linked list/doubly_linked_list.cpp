//implementation of doubly linked list

#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node*next;
    node*prev;

    node()
    {
      next=NULL;
      prev=NULL;
    }

};

class dll
{
    public:

    node*head= NULL;

    int size=0;

    void push_front(int data)
    {
        size++;

        node*new_node=new node();
        new_node->data=data;

        if(head==NULL)
        {
            head=new_node;
            return;
        }

        new_node->next=head;
        new_node->prev=NULL;

        if(head!=NULL)
        {
            head->prev=new_node;
        }

        head=new_node;

    }

    void push_back(int data)
    {  
       size++;

       node*new_node=new node();
       new_node->data=data;

       if(head==NULL)
       {
         head=new_node;
         return;
       }

       node*last=head;
       while(last->next!=NULL)
       {
         last=last->next;
       }

       last->next=new_node;
       new_node->prev=last;
    }

    void insert_before(int indx,int data)
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
            return;
          }

          for(int i=1;i<indx;i++)
          {
            temp=temp->next;
          }

          if(temp==head)
          {
            new_node->prev=NULL;
            new_node->next=head;
            head=new_node;
            
          }
          else
          {
            node* pre=temp->prev;
            pre->next=new_node;
            new_node->prev=pre;
            new_node->next=temp;
            temp->prev=new_node;
            
          }
          

          
    }

    void insert_after(int indx,int data)
    {     
          if(indx<1||indx>size && size!=0)
          {
            return;
          }

          node*temp=head;
          node*new_node=new node();
          new_node->data=data;

          if(temp==NULL)
          {
            head=new_node;
            return;
          }

          for(int i=1;i<indx;i++)
          {
            temp=temp->next;
          }

          if(indx==size)
          {
            new_node->next=NULL;
            new_node->prev=temp;
            temp->next=new_node;
          }
          else 
          {
              node* nxt=temp->next;
              nxt->prev=new_node;
              new_node->next=nxt;
              new_node->prev=temp;
              temp->next=new_node;
            
          }

          size++;
    }

    bool search(int x)
    {
        node *i = head;

        while (i != NULL)
        {
            if (i->data == x)
            {
                return true;
            }
            i = i->next;
        }

        return false;
    }

    void remove_data(int x)
    {
       node*i=head;

       while(i!=NULL)
       {
          if(i->data==x)
          {
            break;
          }
          i=i->next;
       }

       if(i==NULL)
       {
        return;
       }

       node*temp1=i->prev;
       node*temp2=i->next;

       temp1->next=temp2;
       temp2->prev=temp1;

       free(i);
       size--;
    }

    void remove(int indx)
    {
      if(indx<1||indx>size)
      {
        return;
      }

      size--;

      node*temp=head;
      node*last=head;

      while(last->next!=NULL)
      {
        last=last->next;
      }

      for(int i=1;i<indx;i++)
      {
        temp=temp->next;
      }
      
      node*temp1=temp->prev;
      node*temp2=temp->next;

      if(temp==head)
      {
        head=temp2;
        temp2->prev=NULL;
      }
      else if(temp==last)
      {
        temp1->next=NULL;
      }
      else
      {
        temp1->next=temp2;
        temp2->prev=temp1;
      }

      free(temp);

    }

    void remove_front()
    {
        size--;

        node*temp=head;

        head=temp->next;

        head->prev=NULL;

        free(temp);
    }

    void remove_back()
    {
        size--;

        node*temp=head;

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }

        node*i=temp->prev;
        i->next=NULL;
        free(temp);

    }

    void print()
    {
        node*i=head;

        while(i!=NULL)
        {
            cout<<i->data<<" ";
            i=i->next;
        }
        cout<<endl;
    }
    
};
