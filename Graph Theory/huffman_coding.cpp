// implementation of huffman coding using minheap

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char ch;
    unsigned int freq;
    Node *left;
    Node *right;

    Node(char ch, unsigned int freq)
    {
        this->ch = ch;
        this->freq = freq;
        left = NULL;
        right = NULL;
    }
};

class MinHeap
{

public:
    Node **heapArr;
    unsigned size;
    unsigned capacity;

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

    void createMinHeap(unsigned capacity)
    {
        this->size = 0;
        this->capacity = capacity;

        heapArr = new Node *[capacity];
    }

    bool isSizeOne()
    {
        return size == 1 ? true : false;
    }

    void MinHeapify(int indx)
    {
        int smallest = indx;
        int l = left(indx);
        int r = right(indx);

        if (l < size && heapArr[l]->freq < heapArr[smallest]->freq)
            smallest = l;

        if (r < size && heapArr[r]->freq < heapArr[smallest]->freq)
            smallest = r;

        if (smallest != indx)
        {
            swap(heapArr[smallest], heapArr[indx]);
            MinHeapify(smallest);
        }
    }

    Node *extractMin()
    {
        Node *temp = heapArr[0];

        heapArr[0] = heapArr[size - 1];

        size--;

        MinHeapify(0);

        return temp;
    }

    void insert(Node *node)
    {
        size++;
        int i = size - 1;

        while (i && node->freq < heapArr[parent(i)]->freq)
        {
            heapArr[i] = heapArr[parent(i)];

            i = parent(i);
        }

        heapArr[i] = node;
    }
};

MinHeap *buildMinHeap(char data[], int freq[], int size)
{
    MinHeap *minheap = new MinHeap();

    minheap->createMinHeap(size);

    for (int i = 0; i < size; i++)
    {
        minheap->heapArr[i] = new Node(data[i], freq[i]);
    }

    minheap->size = size;

    return minheap;
}

bool isLeaf(Node *node)
{
    return !(node->left) && !(node->right);
}

class HuffmanCoding
{
public:

    Node *buildHuffmanTree(char data[], int freq[], int size)
    {
        MinHeap *mh = buildMinHeap(data, freq, size);

        Node *left, *right, *top;

        while (!mh->isSizeOne())
        {
            left = mh->extractMin();

            right = mh->extractMin();

            top = new Node('$', left->freq + right->freq);

            top->left = left;

            top->right = right;

            mh->insert(top);
        }

        return mh->heapArr[0];
    }

    void printCodes(Node *root, int arr[], int top)
    {
        if (root->left)
        {
            arr[top] = 0;
            printCodes(root->left, arr, top + 1);
        }

        if (root->right)
        {
            arr[top] = 1;
            printCodes(root->right, arr, top + 1);
        }

        if (isLeaf(root))
        {
            cout << root->ch << ": ";
            for (int i = 0; i < top; i++)
            {
                cout << arr[i];
            }
            cout << endl;
        }
    }

    void HuffmanCodes(char data[], int freq[], int size)
    {
        Node *root = buildHuffmanTree(data, freq, size);

        int arr[2 * size];
        int top = 0;

        printCodes(root, arr, top);
    }
};

int main()
{
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
 
    int size = sizeof(arr) / sizeof(arr[0]);
 
    HuffmanCoding hc = HuffmanCoding();

    hc.HuffmanCodes(arr,freq,size);
 
    return 0;
}