// https://cses.fi/problemset/result/9130142/
// Tree Rerooting
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

vector<int>cnt,ans;
vector<vector<int>>graph;
int n;
void dfs(int node,int par,int type){
    for(auto &child:graph[node]){
        if(child==par) continue;
        if(type==0){
            dfs(child,node,type);
            cnt[node]+=cnt[child];
            ans[node]+=ans[child]+cnt[child];
           // calculating paths from leafs to 0 (root)
        }else{
            ans[child]=ans[node]+n-2*cnt[child];
           // contribution of parent - contreebution of current node + remainging nodes
           // ans[child]=ans[i]-ans[child]+(n-ans[child])
            dfs(child,node,type);
 
        }
    }
}
void __solve() {
 
    cin>>n;
    cnt.assign(n,1); ans.assign(n,0);
    graph.resize(n,vector<int>());
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v; u--,v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(0,0,0);
    dfs(0,0,1);
    graph.clear();
    for(auto &i:ans) cout<<i<<" ";
}
int32_t main(){
    int T=1;  // cin>>T;
    for(int i=0;i<T;i++,__solve(),cout<<endl);
}
