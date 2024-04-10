// https://cses.fi/problemset/task/1754
// https://cses.fi/problemset/result/7788478/
#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(),x.end()
using namespace std;

int32_t main()
{
    int T = 1; cin >> T;
    while (T--) {

        int a, b; cin >> a >> b;
        int mx = max(a, b), mn = min(a, b);

        // we can make only two operations i.e ( 2,1 ) or ( 1,2 )
        // so if sum is not divisible by 3 we can't make them empty using above operations
        // we can subtract 2 from the max value max/2 times
        // so we need to max/2 min values to subtract one
        // if we have sufficent one or not

        int sum = (a + b);
        if (sum % 3) {
            cout << "NO";
        } else if (mn < mx / 2) {
            cout << "NO";
        } else cout << "YES";

        cout << endl;

    }
}
