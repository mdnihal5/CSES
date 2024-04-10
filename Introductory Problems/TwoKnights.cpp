https://cses.fi/problemset/task/1072

https://cses.fi/problemset/result/7783494/

#include "bits/stdc++.h"
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,mmx,abm,avx,avx2,fma")
#define Md_Nihal ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef unsigned long long ull;
#define endl "\n"
#define int long long
#define Lint int64_t
#define sz(a) (int)a.size()
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vs vector<string>
#define all(x) x.begin(),x.end()
#define rep(i,n) for (int i = 0; i < (n); i++)
#define print(x) (x)?cout<<"YES":cout<<"NO";
const int mod = 1e9 + 7, inf = LONG_LONG_MAX, N = 1e6 + 7;

template<class T, class V>istream& operator>>(istream &in, pair<T, V> &a) {in >> a.first >> a.second; return in;}
template<class T>istream& operator>>(istream &in, vector<T> &a) {for (auto &i : a) {in >> i;} return in;}
template<class T, class V>ostream& operator<<(ostream &os, pair<T, V> &a) {os << a.first << " " << a.second; return os;}
template<class T>ostream& operator<<(ostream &os, vector<T> &a) {for (auto &i : a) {os << i << " ";} return os;}


#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(x...);
#endif

/*=========================================== SOLUTION ===========================================*/

Lint square(int a) {
    return a * a;
}

void __solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int x = square(i);
        // The number of ways that two knights threaten each other form 2*3 or 3*2 matrix
        // The number of ways to make 2*3 or 3*2 boards are (n-1)*(n-2)+(n-2)*(n-1)
        // we have  two choice that is 4*(n-1)*(n-2)

        // Total number of ways we can play a knight in a n*n board is n*n(n*n-1)/2
        // Number of ways to place two queen such that they do not attack is
        // n*n(n*n-1)/2-4*(n-1)*(n-2)
        int y = 4 * (i - 1) * (i - 2);
        cout << x*(x - 1) / 2 - y   << endl;
    }

}



/*============================================= MAIN =============================================*/

int32_t  main()
{
    Md_Nihal;
    int testcases = 1;    //cin >> testcases;
    for (int i = 1; i <= testcases; ++i, cout << endl) __solve();
}
