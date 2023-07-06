//implementation of circular linked list using array

#include<bits/stdc++.h>
using namespace std;



class cll
{
    public:

    int head,tail;

    int *arr;

    int max_size,cur_size=0;

    cll(int n)
    {
        max_size=n;
        head=tail=-1;

        arr= new int[max_size];
    }

    bool full()
    {
        return cur_size==max_size?true:false;
    }

    bool empty()
    {
        return cur_size==0?true:false;
    }

    void push_front(int data)
    {
        if(full())
        {
            return;
        }

        if(empty())
        {
            head=tail=0;
        }
        else if(head==0)
        {
            head=max_size-1;
        }
        else
        {
            head--;
        }

        arr[head]=data;

        cur_size++;
        
    }

    void push_back(int data)
    {
        if(full())
        {
            return;
        }

        if(empty())
        {
            head=tail=0;
        }
        else if(tail==max_size-1)
        {
            tail=0;
        }
        else
        {
            tail++;
        }

        arr[tail]=data;

        cur_size++;
        
    }

    
    void remove_front()
    {
       if(empty())
       {
         return;
       }

       if(head==tail)
       {
         head=tail=-1;
       }
       else if(head==max_size-1)
       {
        head=0;
       }
       else
       {
        head++;
       }

       cur_size--;
    }

    void remove_back()
    {
       if(empty())
       {
         return;
       }

       if(head==tail)
       {
        head=tail=-1;
       }
       else if(tail==0)
       {
        tail=max_size-1;
       }
       else
       {
        tail--;
       }

       cur_size--;
       
    }

    int front()
    {
        if(empty())
        {
            return -1;
        }

        return arr[head];
    }

    int back()
    {
        if(empty())
        {
            return -1;
        }

        return arr[tail];
    }

    void print()
    {
        if(empty())
        {
            return;
        }

        int curr=head;

        while(curr!=tail)
        {
            cout<<arr[curr]<<" ";
            curr=(curr+1)%max_size;
        }

        cout<<arr[curr]<<endl;
    }
    
};

