// implementation of Queue using array

#include <bits/stdc++.h>
using namespace std;

class Queue
{
    private:
        int capacity;
        int size = 0;
        int *arr=NULL; 
        int rear,front;

    public:
        Queue(int capacity)
        {
            rear = 0;
            front = 0;
            this->capacity=capacity;
            arr=(int*)calloc(sizeof(int) ,this->capacity);
        }
        int getsize()
        {
            return size;
        }

        void push(int data)
        {
            if(rear==capacity)
            {
            return;
            }

            arr[rear]=data;
            rear++;
            size++;
        }

        void pop()
        {
            if(front==rear)
            {
                return;
            }

            for(int i=0;i<rear-1;i++)
            {
                arr[i]=arr[i+1];
            }

            rear--;
            size--;
        }

        int peek()
        {   
            return arr[front];
        }

        bool empty()
        {
            return (size == 0) ? true : false;
        }

        void clear()
        {
          size=0;
          rear=0;
          front=0;
        }

        bool search(int x)
        {
            for(int i=front;i<rear;i++)
            {
                if(arr[i]==x)
                {
                    return true;
                }
            }

            return false;
        }

        void print()
        {
            for(int i=front;i<rear;i++)
            {
                cout<<arr[i]<<" ";
            }

            cout<<endl;

        }
};
