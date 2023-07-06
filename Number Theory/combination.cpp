//algorithm to find combinations of an array

#include<bits/stdc++.h>

using namespace std;

void combination(vector<int>&v,vector<int>&c,int start,int end,int indx,int r)
{
    if(indx==r)
    {
        for(auto i:c)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    else
    {
        for(int i=start;i<=end && end-i+1>=r-indx;i++)
        {
            c[indx]=v[i];
            combination(v,c,i+1,end,indx+1,r);
        }
    }
    
}