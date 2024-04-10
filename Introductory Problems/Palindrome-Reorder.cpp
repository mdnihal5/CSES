// https://cses.fi/problemset/task/1755

// https://cses.fi/problemset/result/7893751/

#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(),x.end()
using namespace std;

int32_t main()
{
    string s; cin >> s;
    int n = s.size();
    int freq[27] = {0};
    for (int i = 0; i < n; i++) {
        freq[s[i] - 'A']++;
    }


    int odd = 0;
    char middle ;
    string res;
    for (int i = 0; i < 26; i++) {
        if (freq[i] & 1) odd++, middle = ('A' + i);
        freq[i] /= 2;
        while (freq[i] > 0) {
            res += ('A' + i);
            freq[i]--;
        }
    }

    // if n is even and there are odd occurance then we can't make palindrome
    // if n is odd and if we have more than 1 odd occurance then we can't make
    // else we can divide every character n/2 n/2 and the odd character in middle

    if (odd > (n & 1)) {
        cout << "NO SOLUTION";
    } else {
        string s = res; reverse(all(s));
        if (odd) res += middle;
        res += s;
        cout << res;
    }
}
