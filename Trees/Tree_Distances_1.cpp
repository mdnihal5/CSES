// https://cses.fi/problemset/result/9130230/
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
vector<vector<int>>graph;
void dfs(int node,int par,vector<int>&dist){
    for(auto &child:graph[node]){
        if(child==par) continue;
        dist[child]=max(dist[node]+1,dist[child]);
        dfs(child,node,dist);
    }
}
void __solve(){
    int n; cin>>n;
    graph.resize(n,vector<int>());
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    vector<int>dist1(n),dist2(n),dist3(n);
    dfs(0,0,dist1);
    int mx_node=max_element(all(dist1))-dist1.begin();
    dfs(mx_node,mx_node,dist2);
    mx_node=max_element(all(dist2))-dist2.begin();
    dfs(mx_node,mx_node,dist3);
    for(int i=0;i<n;i++) cout<<max(dist3[i],dist2[i])<<" ";
}
 
int32_t main(){
    int T=1; //  cin>>T;
    for(int i=0;i<T;i++,__solve(),cout<<endl);
}
