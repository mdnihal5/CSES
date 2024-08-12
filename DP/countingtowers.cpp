// author : md_niha
// https://cses.fi/problemset/task/2413
// https://cses.fi/problemset/result/10170381/
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
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
int N = 1e6 + 1;
vector<vector<Mint>>dp (2, vector<Mint> (N) );
void __solve() {
    int n; cin >> n;
    cout << dp[0][n] + dp[1][n] << endl;
}
 
int main() {
    dp[0][1] = dp[1][1] = 1;
 
    // 0 is 2 towers of 1*1 and 1 is 2*1
    // for height i and now want to choose 1*1 there are 5 choice 1.don't pick any , 2.pick a left and right from previous 1*1
    // 3.pick from left 1*1 or 4.pick right 1*1 or 5.pick a 2*1
    // for height i there and want to pick 2*1 then 3 choice 1.pick from last 2 1*1's
    // 2.pick a 2*1 from below and continue 3.don't pick
    for (int i = 2; i < N; i++) {
        dp[0][i] = 4 * dp[0][i - 1] + dp[1][i - 1];
        dp[1][i] = 2 * dp[1][i - 1] + dp[0][i - 1];
    }
 
    int T = 1; cin >> T;
 
    while (T--) __solve();
}
