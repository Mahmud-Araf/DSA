#include<bits/stdc++.h>
using namespace std;

int lcs_three_strings(const string& a, const string& b, const string& c, int i, int j, int k) {
    if (i == 0 || j == 0 || k == 0) {
        return 0;
    } else if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1]) {
        return 1 + lcs_three_strings(a, b, c, i - 1, j - 1, k - 1);
    } else {
        return max(
            lcs_three_strings(a, b, c, i - 1, j, k),
            max(lcs_three_strings(a, b, c, i, j - 1, k), lcs_three_strings(a, b, c, i, j, k - 1))
        );
    }
}

int main() {
   
    string str1 = "ABC";
    string str2 = "BCA";
    string str3 = "ABC";

    int result = lcs_three_strings(str1, str2, str3, str1.size(), str2.size(), str3.size());

    cout << "Size of the Longest Common Subsequence: " << result << endl;

    return 0;
}
