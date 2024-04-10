// Author : md_nihal
// https://cses.fi/problemset/result/8649864/

#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
int main()
{
    int n,x; cin>>n>>x;
    int arr[n+1];
    for(int i=1;i<=n;i++) cin>>arr[i];
    vector dp(n+1,vector(x+1,0));
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            if(j==0) {
                dp[i][j]=1;
            }else if(j-arr[i]>=0){
                dp[i][j]=(dp[i-1][j]+dp[i][j-arr[i]])%mod;
            }else dp[i][j]=dp[i-1][j];
        }
    }

    cout<<dp[n][x]<<endl;
}
