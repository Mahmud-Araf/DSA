// implementation of activity selection 

#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int, int>p1, pair<int, int>p2)
{
    return p1.second<p2.second;
}


void selection(vector<pair<int, int> >&activities)
{
    sort(activities.begin(), activities.end(),comp);

    int n = activities.size();

    cout<<activities[0].first<<" "<<activities[0].second<<endl;

    int i=0;

    for(int j=1;j<n;j++)
    {
        if(activities[j].first>=activities[i].second)
        {
            cout<<activities[j].first<<" "<<activities[j].second<<endl;
            i=j;
        }
    }
}


int main()
{
    vector<pair<int,int> > activities={{5,9},{1,2},{3,4},{0,6},{5,7},{8,9}};
    selection(activities);
}