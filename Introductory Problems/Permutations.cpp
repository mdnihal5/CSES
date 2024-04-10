https://cses.fi/problemset/task/1070

#include "bits/stdc++.h"
using namespace std;
signed main()
{
    // claim : we can't make any permuation if  n<=3 exept 1
    // you need atleast 2 even and 2 odd numbers to make such permutation
    // claim : if n>=3 we can always print even...odd or oddd...even
    // any two unique elements with same parity have the difference 2
    int n; cin >> n;
    if (n <= 3 and n != 1) {
        cout << "NO SOLUTION";
        return 0;
    }
    int odc = (n + 1) / 2, evec = n / 2, odd = 1, even = 2;
    if (n & 1) {
        while (odc--) cout << odd << " ", odd += 2;
        while (evec--) cout << even << " ", even += 2;
    } else {
        while (evec--) cout << even << " ", even += 2;
        while (odc--) cout << odd << " ", odd += 2;
    }
}
