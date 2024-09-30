// implementation of robin karp approach for string matching
// Time complexity: O(n+m)
// where n is the length of the text and m is the length of the pattern
// Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

#define d 256
#define q INT_MAX

vector<int> robin_karp(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();
    vector<int> fndIndex;

    int h = 1;
    for (int i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }

    int p = 0;
    int t = 0;

    for (int i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (int i = 0; i <= n - m; i++)
    {
        if (p == t)
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

        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
            {
                t += q;
            }
        }
    }

    return fndIndex;
}

int main()
{
    string text = "ababcababcabab";
    string pattern = "abc";

    vector<int> fndIndex = robin_karp(text, pattern);

    if (fndIndex.size() == 0)
    {
        cout << "Pattern not found" << endl;
    }

    return 0;
}