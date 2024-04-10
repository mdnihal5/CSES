// https://cses.fi/problemset/task/1617
// https://cses.fi/problemset/result/7788367/

#include<bits/stdc++.h>
#define int long long
typedef unsigned long long ull;
#define all(x) x.begin(),x.end()
using namespace std;
const int mod = 1e9 + 7;
ull power(int a, int b) {
    ull ans = 1;
    a %= mod;
    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
int32_t main()
{
    // for every n there are 2^n binary strings possible [ nC0+3C1+3C2+3C3+...+nCn ]
    int n; cin >> n;
    cout << power(2, n);
}
