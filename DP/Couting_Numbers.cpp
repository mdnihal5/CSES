// https://cses.fi/problemset/task/2220
// https://cses.fi/problemset/result/10281682/
#include "bits/stdc++.h"
using namespace std;
#define all(x) x.begin(),x.end()
#define ALL(x) x.rbegin(),x.rend()
#define int long long
const int mod = 1E9 + 7, MAX = 1E7 + 7, N = 1E5 + 5, inf = 1E18 ;

#ifndef ONLINE_JUDGE
    #include "/home/anonymous/Templates/debug.hpp"
#else
    #define debug(x...);
#endif

/*=========================================== SOLUTION ===========================================*/
int dp[20][10][2][2];
int solve (string &num, int n, int last, int leading, int tight) {
    if (n == 0) return 1; // for empty digit there is one such one

    if (dp[n][last][leading][tight] != -1) return dp[n][last][leading][tight];

    int ub = (tight ? num[num.size() - n] - '0' : 9); // upper bound for digit
    int ans = 0;

    for (int dig = 0; dig <= ub; dig++) {
        if (dig == last and !leading) continue; //skip the last picked value but allow leading zeros

        ans += solve (num, n - 1, dig, (leading & (dig == 0) ), tight & (dig == ub) );
    }

    return dp[n][last][leading][tight] = ans;
}
void ____solve() {

    int l, r; cin >> l >> r;
    auto L = to_string (l - 1);
    auto R = to_string (r);
    memset (dp, -1, sizeof dp);
    int Rans = solve (R, R.length(), 0, 1, 1);
    memset (dp, -1, sizeof dp);
    int Lans = solve (L, L.length(), 0, 1, 1);
    cout << Rans - Lans;
}

/*============================================= MAIN =============================================*/

int32_t main() {
    int Test = 1;  //cin >> Test;

    for (int i = 0; i < Test; i++, ____solve(), cout << endl);
}

