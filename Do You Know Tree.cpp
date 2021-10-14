#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define dbg(a,b,c) cout<<a<<"  "<<b<<"  "<<c<<endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define endl "\n"
#define INF 1e18
#define w(t) cin>>t;while(t--)
#define kill(a) {cout<<a<<endl;continue;}
#define pi  2 * acos(0.0)
int t,ans=0,tot=0,k=0;
const int mxN=1e6+3,mod=1e9+7;
vector<pair<int,int>>adj[mxN];
pair<ll,int>ma(-1,-1);vector<int>long_dis_path;
int parent[mxN],root[mxN],flag[mxN];
ll dist[mxN],vis[mxN];
void dfs(int n,int par=-1,ll dis=0)
{
    parent[n]=par;
    dist[n]=dis;
    ma=max(ma,{dis,n});
    for(auto i:adj[n])if(i.first!=par)dfs(i.first,n,i.second+dis);
}
void dfs1(int n,int par,int _root)
{
    root[n]=_root;
    vis[n]=0;
    for(auto i:adj[n])
    {
        if(flag[i.first] or i.first==par)continue;
        dfs1(i.first,n,_root);vis[n]=max(vis[n],vis[i.first]+i.second);//trying to store max distance from node n to it's child node
    }
}
signed main()
{
    fast;
    //w(t)
    //{
        ll n,m,a,b,c,d,i,j,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=INT_MAX;
        string s,ss,sr;
        bool f=false,ff=false;
        cin>>n;
        for(i=1;i<n;i++)cin>>a>>b>>c,adj[a].push_back({b,c}),adj[b].push_back({a,c});
        dfs(1);
        int u=ma.second;//max distance from node 1 to node ma.first
        ma.first=-1;
        dfs(u);//is it ok max distance = from ma.first to 1 or another node
        u=ma.second;//if there exist actual max distance path which may be from ma.first to 1 or another node
        int x=u;
        while(x!=-1)long_dis_path.push_back(x),flag[x]=1,x=parent[x];//max distance path based on weight
        for(auto i:long_dis_path)dfs1(i,-1,i);
        cin>>m;
        while(m--)
        {
            cin>>a;
            b=root[a];
            if(b==a)kill(dist[u]);//if node a on max distance path then max distance answer
            d=dist[a]-dist[b]+max(dist[b],dist[u]-dist[b])+vis[a];//from node a to max distance path point which point lead node a + that point's max distance + max distance from node a to it's child node
            kill(d);
        }
    //}
    return 0;
}
