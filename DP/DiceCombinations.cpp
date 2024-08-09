// Author : md_nihal
// https://cses.fi/problemset/result/8649405/
https://cses.fi/problemset/task/1633
#include "bits/stdc++.h"
using namespace std;
#define endl "\n"
#define all(x) x.begin(),x.end()
#define ALL(x) x.rbegin(),x.rend()
#define int long long
using i_64 = int64_t;
const int mod = 1e9 + 7, MAX = 1e7 + 7, N = 1e5 + 5, inf = 1e18 ;

#ifndef ONLINE_JUDGE
    #include "/home/anonymous/Templates/debug.hpp"
#else
    #define debug(x...);
#endif

/*=========================================== SOLUTION ===========================================*/
template<int MOD = 1000000007>
struct ModInt {
    long long v;
    ModInt (long long _v = 0) {v = (-MOD < _v && _v < MOD) ? _v : _v % MOD; if (v < 0) v += MOD;}
    ModInt &operator += (const ModInt &other) {v += other.v; if (v >= MOD) v -= MOD; return *this;}
    ModInt &operator -= (const ModInt &other) {v -= other.v; if (v < 0) v += MOD; return *this;}
    ModInt &operator *= (const ModInt &other) {v = v * other.v % MOD; return *this;}
    ModInt &operator /= (const ModInt &other) {return *this *= inverse (other);}
    bool operator == (const ModInt &other) const {return v == other.v;}
    bool operator != (const ModInt &other) const {return v != other.v;}
    bool operator < (const ModInt &other) const {return v < other.v;}
    bool operator > (const ModInt &other) const {return v > other.v;}
    friend ModInt operator + (ModInt a, const ModInt &b) {return a += b;}
    friend ModInt operator - (ModInt a, const ModInt &b) {return a -= b;}
    friend ModInt operator * (ModInt a, const ModInt &b) {return a *= b;}
    friend ModInt operator / (ModInt a, const ModInt &b) {return a /= b;}
    friend ModInt operator - (const ModInt &a) {return 0 - a;}
    friend ModInt power (ModInt a, long long b) {ModInt ret (1); while (b > 0) {if (b & 1) ret *= a; a *= a; b >>= 1;} return ret;}
    friend ModInt inverse (ModInt a) {return power (a, MOD - 2);}
    friend istream &operator >> (istream &is, ModInt &m) {is >> m.v; m.v = (-MOD < m.v && m.v < MOD) ? m.v : m.v % MOD; if (m.v < 0) m.v += MOD; return is;}
    friend ostream &operator << (ostream &os, const ModInt &m) {return os << m.v;}
};
using Mint = ModInt<mod>;
/*Mint a=2;
 * cout<<power(a,3);
 * assert(a*inverse(a)==1)
 */

void ____solve() {

    int n; cin >> n;
    vector<Mint>dp (n + 1);
    dp[0] = 1; // no of ways to make 0 sum is 1 base

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) dp[i] += dp[i - j]; // no of ways to make sum I using the current die J
        }
    }

    cout << dp[n]; // no of ways to make sum n

}

/*============================================= MAIN =============================================*/

int32_t main() {
    int Test = 1;  //cin >> Test;

    for (int i = 0; i < Test; i++, ____solve(), cout << endl);
}

