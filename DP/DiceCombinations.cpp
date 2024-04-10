// Author : md_nihal
// https://cses.fi/problemset/result/8649405/

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int mod=1e9+7;
int main()
{
    int n; cin>>n;
    ll dp[n+1]{}; dp[0]=1;
    for(int i=0;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(i-j>=0) dp[i]=(dp[i]+dp[i-j])%mod;
        }
    }
    cout<<dp[n]<<endl;
}

