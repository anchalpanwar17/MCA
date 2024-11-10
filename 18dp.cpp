#include <bits/stdc++.h>
using namespace std;

int func(int i, int j, string &s, string &t, int **dp) {
    if (i < 0 || j < 0) {   // Base case
        return 0;
    }

    if (dp[i][j] != -1) {   // Check if already computed
        return dp[i][j];
    }

    if (s[i] == t[j]) {
        return dp[i][j] = 1 + func(i - 1, j - 1, s, t, dp);
    }
    
    return dp[i][j] = max(func(i - 1, j, s, t, dp), func(i, j - 1, s, t, dp));
}

int lcs(string s, string t) {
    int n = s.size();
    int m = t.size();
    
    // Dynamically allocate memory for dp array
    int **dp = new int*[n];
    for (int i = 0; i < n; i++) {
        dp[i] = new int[m];
        for (int j = 0; j < m; j++) {
            dp[i][j] = -1;  
        }
    }

    int result = func(n - 1, m - 1, s, t, dp);

    // Free the dynamically allocated memory
//    for (int i = 0; i < n; i++) {
//        delete[] dp[i];
//    }
//    delete[] dp;

    return result;
}

int main() {
    string s, t;
    cout << "Enter first string: ";
    cin >> s;
    cout << "Enter second string: ";
    cin >> t;

    int result = lcs(s, t);
    cout << "Length of Longest Common Subsequence: " << result << endl;

    return 0;
}