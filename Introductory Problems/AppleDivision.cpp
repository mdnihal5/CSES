// Author : md_nihal
// https://cses.fi/problemset/result/8648917/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n; cin>>n;
    int arr[n]; 
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // put in first group or second group explore all possible solutions
    
    function<ll(int,ll,ll)>helper=[&](int i,ll sum1,ll sum2){
        if(i==n){
            return abs(sum1-sum2);
        }
        return min(helper(i+1,sum1+arr[i],sum2),helper(i+1,sum1,sum2+arr[i]));
    };
    cout<<helper(0,0,0);
}

