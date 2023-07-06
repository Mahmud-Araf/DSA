// implementation of stack using array

#include<bits/stdc++.h>
using namespace std;

class Stack
{
  private:

        int mx_size;
        int cur_size=0;
        int top=-1;
        int *st;
        

  public:
        
        Stack(int size)
        {
            this->mx_size=size;

            st=new int[mx_size];

        }
        
        void push(int x)
        {
            if(cur_size==mx_size)
            {
                return;
            }

            cur_size++;
            top++;

            st[top]=x;
        }

        void pop()
        {
            if(cur_size==0)
            {
                return;
            }

            cur_size--;
            top--;
        }

        int peek()
        {
            if(top>=0)
            {
              return st[top];
            }

            return INT_MIN;
        }

        int getsize()
        {
            return cur_size;
        }

        bool empty()
        {
           return cur_size==0?true:false;
        }

        void clear()
        {
            top=-1;
            cur_size=0;
        }

        bool search(int x)
        {
            for(int i=top;i>=0;i--)
            {
                if(st[i]==x)
                {
                    return true;
                }
            }

            return false;
        }

        void print()
        {
            for(int i=top;i>=0;i--)
            {
                cout<<st[i]<<" ";
            }
            
            cout<<endl;
        }
};
