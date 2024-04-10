// https://cses.fi/problemset/task/1618
// https://cses.fi/problemset/result/7788435/

#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(),x.end()
using namespace std;

int32_t main()
{
    // We can only produce traling zeros if a number is multiplied by 10
    // we can multiply the number using it's prime factors i.e 2,5 => 2*5=20
    // We need to find the number of pairs of 2,5
    // no of 2's will be always greater than 2  so just find no 5 in it's factorization
    int n; cin >> n;
    int ans = 0, facotr5 = 5;
    while (n / facotr5 > 0) {
        ans += (n / facotr5);
        facotr5 *= 5;
    }
    cout << ans;
}
