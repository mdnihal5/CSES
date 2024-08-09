// author : md_nihal
// https://cses.fi/problemset/task/1638
https://cses.fi/problemset/result/10132938/

#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void __solve() {

    int n; cin >> n;
    vector<string>a (n);

    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>>dp (n, vector<int> (n) );

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '*') continue;

            if (i == 0 and j == 0) dp[i][j] = 1; // standing point there is only one way to reach here

            if (i) dp[i][j] = dp[i - 1][j]; // no of ways to reach (i,j) from (i-1,j)

            if (j) dp[i][j] += dp[i][j - 1]; // no of ways to reach (i,j) from (i,j-1)

            dp[i][j] %= mod;
        }
    }

    cout << dp[n - 1][n - 1];
}

int main() {
    int T = 1; //cin >> T;

    while (T--) __solve();
}

