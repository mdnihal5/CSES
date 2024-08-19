// https://cses.fi/problemset/task/1744
// https://cses.fi/problemset/result/10239998
#include "bits/stdc++.h"
using namespace std;

#define endl "\n"
#define all(x) x.begin(),x.end()
#define ALL(x) x.rbegin(),x.rend()
#define int long long
using i_64 = int64_t;
const int mod = 1E9 + 7, inf = 1E18, N = 2e5 + 7, MAX = 2e7 + 7;

#ifndef ONLINE_JUDGE
    #include "/home/anonymous/Templates/debug.hpp"
#else
    #define debug(x...);
#endif

/*=========================================== SOLUTION ===========================================*/

void ____solve() {

    int n, m; cin >> n >> m;
    vector<vector<int>>dp (n + 1, vector<int> (m + 1, N) );

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == j) {
                dp[i][j] = 0; // base  case for n*n square
                continue;
            }

            // make a vertical cut it will make i*k and i*(j-k) rectangle
            for (int k = 1; k <= j; k++) {
                dp[i][j] = min (dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }

            // make a horizonton cut it will make k*j and (i-k)*j rectangle
            for (int k = 1; k <= i; k++) {
                dp[i][j] = min (dp[i][j], dp[k][j] + dp[i - k][j] + 1);
            }
        }
    }

    cout << dp[n][m];

}

/*============================================= MAIN =============================================*/

int32_t main() {
    int Test = 1;  //cin >> Test;

    for (int i = 0; i < Test; i++, ____solve(), cout << endl);
}

