// author : md_nihal
// https://cses.fi/problemset/task/1158
// https://cses.fi/problemset/result/10133202/

#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

void __solve() {
    int n, sum; cin >> n >> sum;
    vector<array<int, 2>>a (n + 1);

    for (int i = 1; i <= n; i++) cin >> a[i][0];

    for (int i = 1; i <= n; i++) cin >> a[i][1];

    sort (a.begin(), a.end() );
    vector<vector<int>>dp (n + 1, vector<int> (sum + 1) );

    // base case would be with 0 books we can't buy any pages
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {

            dp[i][j] = dp[i - 1][j]; // maximun pages we can get without considering ith book with money J

            if (j - a[i][0] >= 0) dp[i][j] = max (dp[i][j], dp[i - 1][j - a[i][0]] + a[i][1]); // consider the ith book
        }
    }

    cout << dp[n][sum];
}

int main() {
    int T = 1; //cin >> T;
    while (T--) __solve();
}
