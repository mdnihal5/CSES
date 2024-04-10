// Quetion : https://cses.fi/problemset/task/1071
// Solution : https://cses.fi/problemset/result/7778060/
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



void __solve() {

    int x, y; cin >> x >> y;
    int sum = max(x, y) - 1;
    sum = sum * (sum + 1) + 1;

    // You can get the x,y term using the x cordinates
    // it's basically the sum of maximum of (x,y) -1 even terms
    // after getting the x,y term move accordingly
    if (x > y) {
        if (x & 1) {
            // if x>y and x is odd then you go left in x row and sum is decreasing by x-y
            sum -= x - y;
        } else {
            // if x>y and x is even then you go left in x row and is incresing by x-y
            sum += x - y;
        }
    } else {
        if (y & 1) {
            // if y>x and y is odd then you are going up in y column and its y-x increasing
            sum += y - x;
        } else {
            // if y>x and y is odd then you are going up in y column and its y-x drecreasing
            sum -= y - x;;
        }
    }
    cout << sum;

}



/*============================================= MAIN =============================================*/

int32_t  main()
{
    Md_Nihal;
    int testcases = 1;    cin >> testcases;
    for (int i = 1; i <= testcases; ++i, cout << endl) __solve();
}
