// implementation of fractional_knapsack

#include<bits/stdc++.h>
using namespace std;


struct item
{
    int weight;
    int profit;

    item(int profit, int weight)
    {
        this->weight = weight;
        this->profit = profit;
    }
};


bool comp(item item1, item item2)
{
    double r1 =(double)item1.profit/(double)item1.weight;

    double r2 =(double)item2.profit/(double)item2.weight;

    return r1>r2;
}

double fractional_knapsack(int W, item arr[],int N)
{
    sort(arr,arr+N,comp);

    double finalValue = 0.0;

    for(int i=0;i<N;i++)
    {
        if(arr[i].weight<=W)
        {
            W-=arr[i].weight;
            finalValue+=arr[i].profit;
        }
        else
        {
            finalValue+=arr[i].profit*((W*1.0)/arr[i].weight);

            break;
        }
        
    }

    return finalValue;
}

int main()
{
    int W=50;

    item arr[]={{60,10},{120,30},{100,20}};

    cout<<fractional_knapsack(W,arr,3)<<endl;
}