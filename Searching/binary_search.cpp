// implementation of binary search in c++

/* Binary search is the most common and also efficient searching algorithm that is used to find a target value in any sorted 
order data structure

Time Complexity: O(log2(n))
Space Complexity:O(k)

n=difference between lower limit and upper limit
k=constant space
*/

bool BinarySearch(int l,int r,int t,int arr[])       //l=lower limit, r=upper limit t=target value
{
    while(l<=r)
    {
         int mid=l+(r-l)/2; // it is safer to use l+(r-l)/2 rater than (l+r)/2 as overflow may occur during summation of l+r
         if(arr[mid]==t)
         {
             return true;
         }
         else if(arr[mid]>t)
         {
            r=mid-1;
         }
         else
         {
            l=mid+1;
         }
    }
    return false;
}                                    