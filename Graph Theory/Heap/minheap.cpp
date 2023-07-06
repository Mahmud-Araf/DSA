//implementation of minheap using array

#include<bits/stdc++.h>
using namespace std;

class MinHeap
{
  public:
   int *heapArr;
   int capacity;
   int cur_size;

   MinHeap(int n)
   {
      capacity=n;
      heapArr=new int[capacity];
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

   bool insert(int data)
   {
      if(cur_size==capacity)
      {
        return false;
      }

      int i=cur_size;
      heapArr[i]=data;
      cur_size++;

      while(i!=0 && heapArr[i]<heapArr[parent(i)])
      {
        swap(heapArr[i],heapArr[parent(i)]);
        i=parent(i);
      }

      return true;
   }

   int peek()
   {
     return heapArr[0];
   }

   int extractMin()
   {
      if(cur_size<=0)
      {
        return INT_MAX;
      }

      if(cur_size==1)
      {
        cur_size--;
        return heapArr[0];
      }

      int root=heapArr[0];

      heapArr[0]=heapArr[cur_size-1];
      cur_size--;

      MinHeapify(0);

      return root;
   }

   void decreaseIndx(int indx, int new_data)
   {
    heapArr[indx]=new_data;

    int i=indx;

    while(i!=0 && heapArr[i]<heapArr[parent(i)])
    {
    swap(heapArr[i],heapArr[parent(i)]);
    i=parent(i);
    }

   }

   void deleteIndx(int indx)
   {
      decreaseIndx(indx,INT_MIN);
      extractMin();
   }

   void MinHeapify(int indx)
   {
      int l=left(indx);
      int r=right(indx);
      int smallest=indx;

      if(l<cur_size && heapArr[l]<heapArr[smallest])
      {
        smallest=l;
      }

      if(r<cur_size && heapArr[r]<heapArr[smallest])
      {
        smallest=r;
      }

      if(smallest!=indx)
      {
        swap(heapArr[indx],heapArr[smallest]);
        MinHeapify(smallest);
      }

   }
};


int main() {
    // create a new MinHeap object with capacity 10
    MinHeap minHeap(10);

    // insert some elements into the heap
    minHeap.insert(3);
    minHeap.insert(7);
    minHeap.insert(1);
    minHeap.insert(5);

    // print the minimum element in the heap
    cout << "Minimum element: " << minHeap.peek() << endl;

    // extract the minimum element from the heap
    cout << "Extracted minimum element: " << minHeap.extractMin() << endl;

    // decrease the value at index 1 to 2
    minHeap.decreaseIndx(1, 2);

    // print the minimum element in the heap
    cout << "Minimum element: " << minHeap.peek() << endl;

    // delete the element at index 2
    minHeap.deleteIndx(2);

    // print the minimum element in the heap
    cout << "Minimum element: " << minHeap.peek() << endl;

    return 0;
}
