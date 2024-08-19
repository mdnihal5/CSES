// https://cses.fi/problemset/task/1644
// https://cses.fi/problemset/result/10240470/

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
    int n, a, b; cin >> n >> a >> b;
    vector<int>A (n + 1);

    for (int i = 1; i <= n; i++) cin >> A[i];

    vector<int>pre = A;
    partial_sum (all (pre), pre.begin() );
    int ans = -inf;
    multiset<int>ms;

    // we want to maximize the sum of window i-j+1
    // i.e pre[i]-pre[j] so maintain a window of b-a+1
    // such that i-b<=j<=i and j will be from window and iterate on i
    for (int i = a; i <= n; i++) {
        if (i > b) ms.extract (pre[i - b - 1]);

        ms.insert (pre[i - a]);
        ans = max (ans, pre[i] - *ms.begin() );
    }

    cout << ans;
}

/*============================================= MAIN =============================================*/

int32_t main() {
    int Test = 1;  //cin >> Test;

    for (int i = 0; i < Test; i++, ____solve(), cout << endl);
}

