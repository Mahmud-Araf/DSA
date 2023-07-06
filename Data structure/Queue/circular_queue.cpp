//implementation of circular queue using array

#include<bits/stdc++.h>
using namespace std;


class Circular_Queue
{
    private:
        int capacity;
        int size = 0;
        int *arr=NULL;
        int rear,front;

    public:

        Circular_Queue(int capacity)
        {
            rear = -1;
            front = -1;
            this->capacity=capacity;
            arr=new int[this->capacity];
        }

        int getsize()
        {
            return size;
        }

        void push(int data)
        {
            if((front==0 && rear==capacity-1 )||(rear==(front-1)%(capacity-1)))
            {
                return;
            }
            else if(empty())
            {
                front=rear=0;
                arr[rear]=data;
            }
            else if(rear==capacity-1 && front!=0)
            {
                rear=0;
                arr[rear]=data;
            }
            else
            {
                rear++;
                arr[rear]=data;
            }

            size++;
            
        }

        void pop()
        {
           if(empty())
           {
            return;
           }
           else if(front==rear)
           {
             front=-1;
             rear=-1;
           }
           else if(front==capacity-1)
           {
            front=0;
           }
           else
           {
            front++;
           }

           size--;
        }

        int peek()
        {
            if(empty())
            {
                return INT_MIN;
            }
            return arr[front];
        }

        bool empty()
        {
            return (size == 0) ? true : false;
        }

        void clear()
        {
          size=0;
          rear=-1;
          front=-1;
        }

        bool search(int x)
        {
            if(empty())
            {
                return false;
            }

            if(rear>=front)
            {
                for(int i=front;i<=rear;i++)
                {
                    if(arr[i]==x)
                    {
                        return true;
                    }
                }
            }
            else
            {
                for(int i=front;i<capacity;i++)
                {
                    if(arr[i]==x)
                    {
                        return true;
                    }
                }

                for(int i=0;i<=rear;i++)
                {
                    if(arr[i]==x)
                    {
                        return true;
                    }
                }
            }
            
            return false;
        }

        void print()
        {
            if(empty())
            {
                return;
            }

            if(rear>=front)
            {
                for(int i=front;i<=rear;i++)
                {
                    cout<<arr[i]<<" ";
                }
            }
            else
            {
                for(int i=front;i<capacity;i++)
                {
                    cout<<arr[i]<<" ";
                }

                for(int i=0;i<=rear;i++)
                {
                    cout<<arr[i]<<" ";
                }
            }

            cout<<endl;

        }
};
