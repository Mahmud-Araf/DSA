// implementation of finite automata approach for string matching
// Time complexity: O(m*c)
// where n is the length of the text, m is the length of the pattern and c is the number of unique characters in the pattern.
// Space complexity: O(m*c)

#include<bits/stdc++.h>
using namespace std;

#define NO_OF_CHARS 256


void computeTransitionTable(string pattern, vector<vector<int> >&tf)
{
    int m = pattern.length();
    int lps = 0;
    int i, x;

    for (i = 0; i <= m; i++)
    {
        for (x = 0; x < NO_OF_CHARS; x++)
        {
            tf[i][x] = 0;
        }
    }

    tf[0][pattern[0]] = 1;

    for (i = 1; i <= m; i++)
    {
        for (x = 0; x < NO_OF_CHARS; x++)
        {
            tf[i][x] = tf[lps][x];
        }

        if (i < m)
        {
            tf[i][pattern[i]] = i + 1;
            lps = tf[lps][pattern[i]];
        }
    }
}

vector<int>finite_automata_approach(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();
    vector<int> fndIndex;
    vector<vector<int> > tf(m + 1, vector<int>(NO_OF_CHARS,0));

    computeTransitionTable(pattern, tf);

    int i = 0;
    int j = 0;

    for (i = 0; i < n; i++)
    {
        j = tf[j][text[i]];

        if (j == m)
        {
            fndIndex.push_back(i - m+1);
            cout<<"Pattern found at index "<<i-m+1<<endl;
        }
    }

    return fndIndex;
}

int main()
{
    string text = "ababcababcabab";
    string pattern = "abc";
    vector<int> fndIndex = finite_automata_approach(text, pattern);
    if (fndIndex.size() == 0)
    {
        cout << "Pattern not found" << endl;
    }
    return 0;
}

