// author : md_nihal
// https://cses.fi/problemset/task/1639
// https://cses.fi/problemset/result/10170038/
#include<bits/stdc++.h>
using namespace std;
void __solve() {

    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();
    vector<vector<int>>dp (n + 1, vector<int> (m + 1, 5000) );
    dp[0][0] = 0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 and j == 0) continue;

            if (i) dp[i][j] = min (dp[i][j], dp[i - 1][j] + 1); //remove character from a

            if (j) dp[i][j] = min (dp[i][j], dp[i][j - 1] + 1); //add character to a

            if (i and j) dp[i][j] = min (dp[i][j], dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]) ); // replace if not equal
        }
    }

    cout << dp[n][m] << " ";
}

int main() {
    int T = 1; //cin >> T;

    while (T--) __solve();
}
