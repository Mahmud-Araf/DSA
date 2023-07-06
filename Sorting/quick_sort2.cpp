//implementation of quick sort using hoare's partition

/* Quick sort is fast in-place sorting algorithm but it is not stable.

Time Complexity: O(nlogn)(on average)
Space Complexity:O(log(n))

n=total number of elements of array
*/

#include<bits/stdc++.h>

using namespace std;

int partition(vector<int>&v,int low,int high) //Hoare's partition
{
  int pivot=v[low];

  int i=low-1;
  int j=high+1;
  
  while(true)
  {

    do
    {
      i++;
    } while(v[i]<pivot);

    do
    {
      j--;
    } while (v[j]>pivot);
    
    if(i>=j)
    {
      return j;
    }
    
    swap(v[i],v[j]);

  }

}

void quick_sort(vector<int>&v,int begin,int end)
{
       if(begin>=end)
       {
          return;
       }
       
       int p=partition(v,begin,end);

       quick_sort(v,begin,p);

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


