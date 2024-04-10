// https://cses.fi/problemset/task/1092

// https://cses.fi/problemset/result/7783867/

#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(),x.end()
using namespace std;
void ___solve()
{
    int n; cin >> n;
    int sum = n * (n + 1) / 2;
    if (sum & 1) {
        cout << "NO";
        return;
    } else cout << "YES\n";
    // if the sum of n number is odd we can't divide into two equal sets
    // we can always divide by n*(n+1)/4 , n*(n+1)/4
    int vis[n + 1] = {0}, count = 0;
    sum /= 2;
    for (int i = n; i > 0; i--) {
        if (i <= sum) {
            sum -= i;
            vis[i] = 1;
            count++;
        }
    }
    cout << count << endl;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) cout << i << " ";
    }
    cout << endl;
    cout << n - count << endl;
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) cout << i << " ";
    }
}
int32_t main()
{
    ___solve();
}
