// implementation of linear search in c++

/*
Time Complexity: O(n)
Space Complexity:O(k)

n=number of elements
k=constant space
*/

bool LinearSearch(int t,int arr[])      
{
    int n=sizeof(arr)/sizeof(int);
    for(int i=0;i<n;i++)
    {
        if(arr[i]==t)
        {
            return true;
        }
    }

    return false;
    
}                                    