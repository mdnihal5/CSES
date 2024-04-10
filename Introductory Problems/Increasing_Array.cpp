https://cses.fi/problemset/task/1094

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
#define rep(i,n) for (int i = 0; i < (n); i++)
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
    vi arr(n); cin >> arr;
    int ans(0);

    // we can make any element greater than previous element
    // a[i-1]-a[i]+x  only if a[i]  is smaller than a[i-1]
    // x = 0,1,2,3.... but minimum number can be a[i-1]-a[i] which is optimal


    for (int i = 1; i < n; ++i) {
        ans += max(arr[i - 1] - arr[i], 0ll);
        arr[i] = max(arr[i], arr[i - 1]);
    }
    cout << ans;
}



/*============================================= MAIN =============================================*/

signed  main()
{
    Md_Nihal;
    int testcases = 1;    //cin >> testcases;
    for (int i = 1; i <= testcases; ++i, cout << endl) __solve();
}
