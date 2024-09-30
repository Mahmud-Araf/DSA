// implementation of naive approach for string matching
// Time complexity: O(n*m)
// where n is the length of the text and m is the length of the pattern
// Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;


vector<int> naive_approach(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();
    vector<int> fndIndex;

    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
            {
                break;
            }
        }

        if (j == m)
        {
            fndIndex.push_back(i);
            cout << "Pattern found at index " << i << endl;
        }
    }

    return fndIndex;
}

int main()
{
    string text = "ababcababcabab";
    string pattern = "abc";

    vector<int> fndIndex = naive_approach(text, pattern);

    if (fndIndex.size() == 0)
    {
        cout << "Pattern not found" << endl;
    }

    return 0;
}