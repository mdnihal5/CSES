// author :md_nihal
// https://cses.fi/problemset/task/1746
// https://cses.fi/problemset/result/10133442/
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

void __solve() {
    int n, m; cin >> n >> m;
    vector<int>a (n);

    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>>dp (n, vector<int> (m + 1) );

    for (int i = 1; i <= m; i++) {
        if (a[0] == i or a[0] == 0) dp[0][i] = 1; // no of ways to place i at 0th position
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            if (a[i] != 0 and a[i] != j) {
                dp[i][j] = 0; continue; // if current element is not 0 and not a[i] then we don't have any options
            }

            for (int k = -1; k <= 1; k++) {
                if (j + k >= 1 and j + k <= m ) dp[i][j] = (dp[i - 1][j + k] + dp[i][j]) % mod; // there are three options let (a[i-1]-1,a[i-1],a[i]+1])
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= m; i++) ans = (ans + dp[n - 1][i]) % mod;

    cout << ans;
}

int main() {
    int T = 1; //cin >> T;

    while (T--) __solve();
}
