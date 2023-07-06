// implementation of josephus problem using recursion

#include<bits/stdc++.h>
using namespace std;

void josephus_problem(vector<int>&v,int k,int indx)
{
    if(v.size()==1)
    {
        cout<<v[0]<<endl;
        return;
    }

    indx=(indx+k-1)%v.size();

    v.erase(v.begin()+indx);

    josephus_problem(v,k,indx);
}