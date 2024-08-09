// https://cses.fi/problemset/task/1637
// https://cses.fi/problemset/result/10132807/

#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void __solve() {
    int n; cin >> n;
    vector<int>dp (n + 1, n + 1);
    dp[0] = 0; // minimum no of steps to make n 0 is 0

    for (int i = 1; i <= n; i++) {
        int num = i;

        while (num) {
            int D = num % 10;
            dp[i] = min (dp[i], dp[i - D] + 1); // minimum no of steps to make i -> 0 using D digit
            num /= 10;
        }
    }

    cout << dp[n];
}

int main() {
    int T = 1; //cin >> T;

    while (T--) __solve();
}
