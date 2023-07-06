//implementation of bucket sort algorithm for floating point number (with integer part)

/* Bucket sort is a  sorting algorithm which sorts an array by dividing the values 
over a number of ranges/buckets and then sorting all the buckets using other sorting techniques.
It is mainly used to sort floating point numbers.


Time Complexity: O(n+k)
Space Complexity:O(n+k)

n=total number of elements of array
k=number of buckets
*/

#include<bits/stdc++.h>
using namespace std;

void bucket_sort(int n,double arr[],int k) //k=bucket number
{
    double mx=*max_element(arr,arr+n);
    double min=*min_element(arr,arr+n);

    double range=(mx-min)/k;

    vector<double>v[k];

    for(int i=0;i<n;i++)
    {
        double diff=((arr[i]-min)/range)-(int)((arr[i]-min)/range);

        if(diff==0 && arr[i]==mx)
        {
            v[(int)((arr[i]-min)/range)-1].push_back(arr[i]);
            continue;
        }

        v[(int)((arr[i]-min)/range)].push_back(arr[i]);
    }

    for(int i=0;i<k;i++)
    {
        stable_sort(v[i].begin(),v[i].end());
    }
    int indx=0;
    for(auto i:v)
    {
        for(auto j:i)
        {
            arr[indx++]=j;
        }
    }
}

int main()
{
    double arr[]={8.54,3.99,2,-2.76,-1};

    bucket_sort(5,arr,3);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}




