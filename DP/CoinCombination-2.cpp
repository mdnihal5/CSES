// Author : md_nihal
// https://cses.fi/problemset/result/8649864/
// https://cses.fi/problemset/result/10132717/

#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void __solve() {
    int n, sum; cin >> n >> sum;

    vector<int>a (n + 1);
    vector<vector<int>>dp (n + 1, vector<int> (sum + 1) );

    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 0; i <= n; i++) dp[i][0] = 1; // no of ways to make target 0 is 1 for all i

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            dp[i][j] = dp[i - 1][j]; // no of ways to make target J using i-1 coins

            if (j - a[i] >= 0) dp[i][j] += dp[i][j - a[i]]; // no of ways to make target J including ith coin

            dp[i][j] %= mod;
        }
    }

    cout << dp[n][sum];
}

int main() {
    int T = 1; //cin >> T;

    while (T--) __solve();
}
