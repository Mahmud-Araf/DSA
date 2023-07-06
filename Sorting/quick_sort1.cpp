//implementation of quick sort using lomuto's partition

/* Quick sort is fast in-place sorting algorithm but it is not stable.

Time Complexity: O(nlogn)(on average)
Space Complexity:O(log(n))

n=total number of elements of array
*/

#include<bits/stdc++.h>

using namespace std;

int partition(vector<int>&v,int low,int high) //Lomuto's partition
{
  int pivot=v[high];

  int i=low-1;

  for(int j=low;j<=high-1;j++)
  {
    if(v[j]<=pivot)
    {
      i++;
      swap(v[i],v[j]);
    }
  }

  swap(v[++i],v[high]);

  return i;

}

void quick_sort(vector<int>&v,int begin,int end)
{
       if(begin>=end)
       {
          return;
       }
       
       int p=partition(v,begin,end);

       quick_sort(v,begin,p-1);

       quick_sort(v,p+1,end);
}

int main()
{
  vector<int>v={10,3,9,2,1,7};

  quick_sort(v,0,5);

  for(auto i:v)
  {
    cout<<i<<" ";
  }
  cout<<endl;
}

