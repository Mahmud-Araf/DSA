// implementation of longest commone subsequence using bottom-up dynamic programming

#include<bits/stdc++.h>
using namespace std;

int lcs(string s1,string s2,int m, int n)
{
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    string ans;

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)
            {
                dp[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];        
            }
            else 
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]); 
            }
        }
    }
    int i=m-1,j=n-1;
    while(i>=0 and j>=0){
        if(s1[i]==s2[j]){
            ans.push_back(s1[i]);
            i--;
            j--;
        }
        else{
            if(dp[i][j+1]>dp[i+1][j]){
                // ans.push_back(s1[i-1]);
                i--;
            }
            else{
            //    ans.push_back(s2[j-1]);
                j--; 
            }
        }
    }

    reverse(ans.begin(),ans.end());

    cout<<ans<<endl;
    return dp[m][n];
}

int main()
{
    string s1 = "AGGTAB";
    string s2="GXTXAYB";

    int m =s1.size();
    int n = s2.size();

    vector<vector<int> > dp(m+1,vector<int>(n+1,-1));

    cout<<lcs(s1,s2,m,n)<<endl;
}