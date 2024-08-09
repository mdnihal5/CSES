// Author : md_nihal
// https://cses.fi/problemset/result/8649516/
// https://cses.fi/problemset/result/10132363/
#include<bits/stdc++.h>
using namespace std;
int MAX = 1e6 + 2;
vector<int>dp (MAX, MAX);
void __solve() {

    int n, sum; cin >> n >> sum;
    vector<long long>a (n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i]; dp[a[i]] = 1; // miniimum no of coins to make sum a[i] is 1
    }

    for (int w = 1; w <= sum; w++) {
        for (int i = 1; i <= n; i++) {
            if (w - a[i] >= 0) {
                dp[w] = min (dp[w], dp[w - a[i]] + 1); // min no of coins to make target w using a[i]
            }
        }
    }

    cout << (dp[sum] >= MAX ? -1 : dp[sum]);
}

int main() {
    int T = 1; //cin >> T;

    while (T--) __solve();
}

