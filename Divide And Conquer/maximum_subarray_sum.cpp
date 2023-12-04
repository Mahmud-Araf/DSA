#include<bits/stdc++.h>
using namespace std;

// Function to find the maximum of three integers
int max(int a, int b, int c) {
    return max(max(a, b), c);
}

// Function to find the maximum subarray sum that crosses the midpoint
int maxCrossingSum(int arr[], int low, int mid, int high) {
    int leftSum = INT_MIN;
    int sum = 0;

    for (int i = mid; i >= low; --i) {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    int rightSum = INT_MIN;
    sum = 0;

    for (int i = mid + 1; i <= high; ++i) {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

// Function to find the maximum subarray sum using divide and conquer
int maxSubarraySum(int arr[], int low, int high) {
    if (low == high) {
        return arr[low];
    }

    int mid = (low + high) / 2;

    return max(maxSubarraySum(arr, low, mid),
               maxSubarraySum(arr, mid + 1, high),
               maxCrossingSum(arr, low, mid, high));
}

int main() {
    int arr[] = {2,-4, 1, 9, -6, 7, -3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxSum = maxSubarraySum(arr, 0, n - 1);

    cout << "Maximum subarray sum is: " << maxSum << endl;

    return 0;
}
