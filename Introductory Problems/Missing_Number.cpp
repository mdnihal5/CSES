//https://cses.fi/problemset/task/1083

#include "bits/stdc++.h"
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,mmx,abm,avx,avx2,fma")
#define Md_Nihal ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef unsigned long long ull;
#define endl "\n"
#define int long long
#define sz(a) (int)a.size()
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vs vector<string>
#define all(x) x.begin(),x.end()
#define rept(i,a,n) for (int i = a; i < (n); i++)
#define print(x) (x)?cout<<"YES":cout<<"NO";
const int mod = 1e9 + 7, inf = LONG_LONG_MAX, N = 1e6;

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



void __solve() {

    int n; cin >> n;

    // 1+2+3+4......+n = n*(n+1)/2 which sum of n natural numbers
    // we can remove the elements from the the sum and we can get the missing number

    vi v(n); cin >> v;
    cout << n*(n + 1) / 2 - accumulate(all(v), 0LL);

}



/*============================================= MAIN =============================================*/

signed  main()
{
    Md_Nihal;
    int testcases = 1;    //cin >> testcases;
    for (int i = 1; i <= testcases; ++i, cout << endl) __solve();
}
