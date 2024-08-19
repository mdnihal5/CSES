// https://cses.fi/problemset/task/1745
// https://cses.fi/problemset/result/10240142/
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
    vector<int>a (n + 1);

    for (int i = 1; i <= n; i++) cin >> a[i];

    int make = n * 1000;
    vector<vector<int>>dp (n + 1, vector<int> (make + 1) );
    dp[0][0] = 1;

    // we can make sum 0
    for (int w = 0; w <= make; w++) {
        for (int i = 1; i <= n; i++) {
            dp[i][w] = dp[i - 1][w]; // don't pick this coin

            if (w - a[i] >= 0) dp[i][w] |= dp[i - 1][w - a[i]]; // pick this coin
        }
    }

    vector<int>ans;

    for (int i = 1; i <= make; i++) {
        if (dp[n][i]) ans.push_back (i);
    }

    cout << ans.size() << endl;

    for (auto &i : ans) cout << i << " ";
}

/*============================================= MAIN =============================================*/

int32_t main() {
    int Test = 1;  //cin >> Test;

    for (int i = 0; i < Test; i++, ____solve(), cout << endl);
}

