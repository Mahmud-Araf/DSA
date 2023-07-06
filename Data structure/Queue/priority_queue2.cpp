// implementation of priority queue using maxheap

#include<bits/stdc++.h>
using namespace std;

class Priority_Queue
{
  public:
   int *arr;
   int capacity;
   int cur_size;

   Priority_Queue(int n)
   {
      capacity=n;
      arr=new int[capacity];
      cur_size=0;
   }

   int parent(int indx)
   {
    return (indx-1)/2;
   }

   int left(int indx)
   {
    return 2*indx+1;
   }

   int right(int indx)
   {
    return 2*indx+2;
   }

   bool push(int data)
   {
      if(cur_size==capacity)
      {
        return false;
      }

      int i=cur_size;
      arr[i]=data;
      cur_size++;

      while(i!=0 && arr[i]>arr[parent(i)])
      {
        swap(arr[i],arr[parent(i)]);
        i=parent(i);
      }

      return true;
   }

   int peek()
   {
     return arr[0];
   }

   int pop()
   {
      if(cur_size<=0)
      {
        return INT_MIN;
      }

      if(cur_size==1)
      {
        cur_size--;
        return arr[0];
      }

      int root=arr[0];

      arr[0]=arr[cur_size-1];
      cur_size--;

      MaxHeapify(0);

      return root;
   }

   void MaxHeapify(int indx)
   {
      int l=left(indx);
      int r=right(indx);
      int biggest=indx;

      if(l<cur_size && arr[l]>arr[biggest])
      {
        biggest=l;
      }

      if(r<cur_size && arr[r]>arr[biggest])
      {
        biggest=r;
      }

      if(biggest!=indx)
      {
        swap(arr[indx],arr[biggest]);
        MaxHeapify(biggest);
      }

   }
};

int main()
{
  Priority_Queue pq =Priority_Queue(5);
  pq.push(4);
  pq.push(1);
  pq.push(5);
  pq.push(2);
  pq.push(3);

  for(int i=0;i<5;i++)
  {
    cout<<pq.pop()<<" ";
  }
  cout<<endl;
}
