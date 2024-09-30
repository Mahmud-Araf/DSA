// implementation of kmp approach for string matching
// Time complexity: O(n+m)
// where n is the length of the text and m is the length of the pattern
// Space complexity: O(m)

#include<bits/stdc++.h>
using namespace std;


void computeLPS(string pattern, vector<int>& lps)
{
    int m = pattern.length();
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int>kmp_approach(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();
    vector<int> fndIndex;
    vector<int> lps(m);

    computeLPS(pattern, lps);

    int i = 0;
    int j = 0;

    while ((n-i)>=(m-j))
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            fndIndex.push_back(i - j);
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    return fndIndex;
}

int main()
{
    string text = "ababcababcabab";
    string pattern = "abc";
    vector<int> fndIndex = kmp_approach(text, pattern);
    if (fndIndex.size() == 0)
    {
        cout << "Pattern not found" << endl;
    }
    return 0;
}