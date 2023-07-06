// implementation of maxheap using array

#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
public:
  int *arr;
  int capacity;
  int cur_size;

  MaxHeap(int n)
  {
    capacity = n;
    arr = new int[capacity];
    cur_size = 0;
  }

  int parent(int indx)
  {
    return (indx - 1) / 2;
  }

  int left(int indx)
  {
    return 2 * indx + 1;
  }

  int right(int indx)
  {
    return 2 * indx + 2;
  }

  bool push(int data)
  {
    if (cur_size == capacity)
    {
      return false;
    }

    int i = cur_size;
    arr[i] = data;
    cur_size++;

    while (i != 0 && arr[i] > arr[parent(i)])
    {
      swap(arr[i], arr[parent(i)]);
      i = parent(i);
    }

    return true;
  }

  int peek()
  {
    return arr[0];
  }

  int extractMax()
  {
    if (cur_size <= 0)
    {
      return INT_MIN;
    }

    if (cur_size == 1)
    {
      cur_size--;
      return arr[0];
    }

    int root = arr[0];

    arr[0] = arr[cur_size - 1];
    cur_size--;

    MaxHeapify(0);

    return root;
  }

  void decreaseIndx(int indx, int new_data)
  {
    arr[indx] = new_data;

    int i = indx;

    while (i != 0 && arr[i] > arr[parent(i)])
    {
      swap(arr[i], arr[parent(i)]);
      i = parent(i);
    }
  }

  void deleteIndx(int indx)
  {
    decreaseIndx(indx, INT_MAX);
    extractMax();
  }

  void MaxHeapify(int indx)
  {
    int l = left(indx);
    int r = right(indx);
    int biggest = indx;

    if (l < cur_size && arr[l] > arr[biggest])
    {
      biggest = l;
    }

    if (r < cur_size && arr[r] > arr[biggest])
    {
      biggest = r;
    }

    if (biggest != indx)
    {
      swap(arr[indx], arr[biggest]);
      MaxHeapify(biggest);
    }
  }
};


int main()
{
  MaxHeap maxHeap(10);

  maxHeap.push(4);
  maxHeap.push(1);
  maxHeap.push(7);
  maxHeap.push(3);
  maxHeap.push(9);

  cout << "Max Heap after inserting 4, 1, 7, 3, 9: ";
  for (int i = 0; i < maxHeap.cur_size; i++)
  {
    cout << maxHeap.arr[i] << " ";
  }
  cout << endl;

  cout << "Peek max value in heap: " << maxHeap.peek() << endl;

  cout << "Max Heap after popping max value: ";
  maxHeap.extractMax();
  for (int i = 0; i < maxHeap.cur_size; i++)
  {
    cout << maxHeap.arr[i] << " ";
  }
  cout << endl;

  maxHeap.decreaseIndx(2, 2);
  cout << "Max Heap after decreasing value at index 2 to 2: ";
  for (int i = 0; i < maxHeap.cur_size; i++)
  {
    cout << maxHeap.arr[i] << " ";
  }
  cout << endl;

  maxHeap.deleteIndx(1);
  cout << "Max Heap after deleting value at index 1: ";
  for (int i = 0; i < maxHeap.cur_size; i++)
  {
    cout << maxHeap.arr[i] << " ";
  }
  cout << endl;

  return 0;
}
