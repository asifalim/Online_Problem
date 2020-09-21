#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mxN=2e5+5;
vector<ll>adj[mxN];
vector<ll>vis,par,dp,v;
void dfs(ll n)
{
    vis[n]=1;
    for(auto i:adj[n])
    {
        if(!vis[i])
        {
            par[i]=n;
            dfs(i);
        }
        if(dp[i]+1>dp[n])dp[n]=dp[i]+1,par[n]=i;
    }
}
int main()
{
    int n,m,i,a,b;
    cin>>n>>m;
    vis.assign(n+1,0);
    par.assign(n+1,0);
    dp.assign(n+1,-1e9);
    dp[n]=1;
    while(m--)
    {
        cin>>a>>b;
        adj[a].push_back(b);
    }
    dfs(1);
    i=1;
    v.push_back(1);
    if(!vis[n])
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    while(i^n)
    {
        i=par[i];
        v.push_back(i);
    }
    cout<<v.size()<<endl;
    for(ll i:v)cout<<i<<" ";
    cout<<endl;
}
