// https://cses.fi/problemset/task/1145
// https://cses.fi/problemset/result/10240321/

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
    vector<int>dp, a (n + 1);

    for (int i = 1; i <= n; i++) cin >> a[i];

    // maintain a max length if the element is a[i] at i
    // here i represents a[i] and a[i] represents the length of lis ending at i
    for (int i = 1; i <= n; i++) {
        auto it = lower_bound (all (dp), a[i]); // get the position of this element

        if (it == dp.end() ) {
            dp.push_back (a[i]);

        } else *it = a[i];
    }

    cout << dp.size();

}

/*============================================= MAIN =============================================*/

int32_t main() {
    int Test = 1;  //cin >> Test;

    for (int i = 0; i < Test; i++, ____solve(), cout << endl);
}

