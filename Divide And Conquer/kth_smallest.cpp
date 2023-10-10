// implementation of kth smallest element in a unsorted array

#include<bits/stdc++.h>
using namespace std;

// Function to partition the array and return the pivot index
int partition(vector<int>& arr, int left, int right) {
    int pivotIndex = left + rand() % (right - left + 1); // Choose a random pivot
    int pivotValue = arr[pivotIndex];
    swap(arr[pivotIndex], arr[right]); // Move pivot to the right
    int i = left;
    
    for (int j = left; j < right; j++) {
        if (arr[j] < pivotValue) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    
    swap(arr[i], arr[right]); // Move pivot to its final position
    return i;
}

// Function to find the kth smallest element using QuickSelect
int quickSelect(vector<int>& arr, int left, int right, int k) {
    if (left == right) {
        return arr[left];
    }

    int pivotIndex = partition(arr, left, right);

    if (k == pivotIndex) {
        return arr[k];
    } else if (k < pivotIndex) {
        return quickSelect(arr, left, pivotIndex - 1, k);
    } else {
        return quickSelect(arr, pivotIndex + 1, right, k);
    }
}

int findKthSmallest(vector<int>& arr, int k) {
    if (k < 1 || k > arr.size()) {
        cerr << "Invalid value of k." << endl;
        return -1;
    }
    
    return quickSelect(arr, 0, arr.size() - 1, k - 1); 
}

int main() {
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int k = 5;

    int kthSmallest = findKthSmallest(arr, k);

    cout << "The " << k << "th smallest element is: " << kthSmallest << endl;

    return 0;
}
