// Author : md_nihal
// https://cses.fi/problemset/result/8649488/

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int mod=1e9+7;
int main()
{
    int n,x; cin>>n>>x;
    vector arr(n,0),dp(1e6+6,mod);

    for(int i=0;i<n;i++) {
        cin>>arr[i];
        dp[arr[i]]=1;
    }
    for(int i=0;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i-arr[j]>=0) dp[i]=min(dp[i],dp[i-arr[j]]+1);
        }
    }

    cout<<(dp[x]==mod?-1:dp[x])<<endl;
}
