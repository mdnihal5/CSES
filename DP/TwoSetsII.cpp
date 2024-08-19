// https://cses.fi/problemset/task/1093
// https://cses.fi/problemset/result/10240273/

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
    int n; cin >> n;

    int total = n * (n + 1) / 2;

    if (total & 1) {
        cout << 0; return;
    }

    int sum = total / 2;
    vector<vector<int>>dp (n, vector<int> (sum + 1) );
    dp[0][0] = 1; // no of ways to make 0

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] = dp[i - 1][j]; // no of ways to make sum j without using i

            if (j - i >= 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % mod; // no ways to make sum j using i
        }
    }

    cout << dp[n - 1][sum];
}

/*============================================= MAIN =============================================*/

int32_t main() {
    int Test = 1;  //cin >> Test;

    for (int i = 0; i < Test; i++, ____solve(), cout << endl);
}

