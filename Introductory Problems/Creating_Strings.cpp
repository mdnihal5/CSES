// https://cses.fi/problemset/task/1622
// https://cses.fi/problemset/result/8796041/

// check all permutations of the string and pick unique ones
#include "bits/stdc++.h"
using namespace std;
#define all(x) x.begin(),x.end()
#define ALL(x) x.rbegin(),x.rend()
#define int long long
const int mod=1e9+7,MAX=1e7+7,N=1e5+5;
 
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(x...);
#endif
void __solve(){
 
    string s; cin>>s;
    sort(all(s));
    set<string>ans;
    do{
        ans.insert(s);
    }while(next_permutation(all(s)));
    cout<<ans.size()<<endl;
    for(auto &i:ans) cout<<i<<endl;
}
 
int32_t main(){
    int T=1; // cin>>T;
    for(int i=0;i<T;i++,__solve(),cout<<endl);
}
 
