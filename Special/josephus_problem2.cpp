// implementation of josephus problem using queue

#include<bits/stdc++.h>
using namespace std;

void josephus_problem(vector<int>v,int k)
{
    queue<int>q;

    for(auto i:v)
    {
        q.push(i);
    }

    while(q.size()!=1)
    {
        for(int i=1;i<k;i++)
        {
            int val=q.front();
            q.pop();
            q.push(val);
        }
        q.pop();
    }

    cout<<q.front()<<endl;
}