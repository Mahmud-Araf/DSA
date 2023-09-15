// implementation of minimum coin change using dp

#include<bits/stdc++.h>
using namespace std;


int min_change(vector<int>&coins, int amount)
{
    vector<int>table(amount+1,INT_MAX);

    table[0]=0;

    for(int i=1; i<=amount; i++)
    {
        for(int j=0; j<coins.size(); j++)
        {
            if(coins[j]<=i)
            {
                int sub_res=table[i-coins[j]];

                if(sub_res!=INT_MAX && sub_res+1<table[i])
                {
                    table[i]=sub_res+1;
                }
            }
        }
    }

    return table[amount]==INT_MAX ? -1:table[amount];
}

int main()
{
     vector<int>coins ={9,6,5,1};

     int amount =11;

     cout<<min_change(coins,amount)<<endl;
}