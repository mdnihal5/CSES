// https://cses.fi/problemset/task/1638
// https://cses.fi/problemset/result/8813277/
// Base Case : if i==n-1 and j==n-1 => 1
//             else if i==n or j==n or a[i][s]=='*' => 0
// dp[i]=will be dp[i+1][j] + dp[i][j+1] (moving down or moving right)

#include "bits/stdc++.h"
using namespace std;
#define all(x) x.begin(),x.end()
#define ALL(x) x.rbegin(),x.rend()
#define int long long
const int mod=1e9+7,MAX=1e7+7,N=1e5+5;
 
#ifndef ONLINE_JUDGE
#include "/home/anonymous/Templates/debug.hpp"
#else
#define debug(x...);
#endif
int dp[1005][1005],n;
int helper(vector<string>&a,int i,int j){
    if(i==n-1 and j==n-1 and a[i][j]!='*') return 1;
    else if(i==n or j==n) return 0;
    else if(a[i][j]=='*') return 0;
    if(dp[i][j]!=-1) {
        return dp[i][j];
    }
    int ans=0;
    ans=(ans+helper(a,i+1,j))%mod;
    ans=(ans+helper(a,i,j+1))%mod;
    return dp[i][j]=ans;
}
void __solve(){
    cin>>n;
    memset(dp,-1,sizeof dp);
    vector<string>a(n);
    for(auto &s:a) cin>>s;
    cout<<helper(a,0,0);
}
 
int32_t main(){
    int T=1;  //cin>>T;
    for(int i=0;i<T;i++,__solve(),cout<<endl);
}
