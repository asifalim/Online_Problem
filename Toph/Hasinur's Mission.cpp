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
int t,ans=0,tot=0,k=0;
const int mxN=1e6+3,mod=1e9+7;
vector<pair<int,int>>adj[mxN];
bool vis[mxN];
int sz[mxN],sub[mxN],up[mxN];
void prime()
{
    vis[1]=1;
    for(int i=2; i*i<mxN; i++)if(!vis[i])for(int j=i*i; j<mxN; j+=i)vis[j]=1;
}
void dfs1(int n=1,int par=-1)
{
    sz[n]=1;
    for(auto i:adj[n])
    {
        if(i.first==par)continue;
        dfs1(i.first,n);
        sz[n]+=sz[i.first];
        if(i.second)sub[n]+=sz[i.first];
        else sub[n]+=sub[i.first];
    }
}
void dfs2(int n,int par,int u)
{
    for(auto i:adj[n])
    {
        if(i.first==par)continue;
        if(i.second)up[i.first]+=u-sz[i.first];
        else up[i.first]+=up[n]+sub[n]-sub[i.first];
        dfs2(i.first,n,u);
    }
}
int32_t main()
{
    //fast;
    //w(t)
    //{
        ll n,m,a,b,c,d,i,j,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=INT_MAX;
        string s,ss;
        prime();cin>>n;
        for(i=1;i<n;i++)
        cin>>a>>b>>c,adj[a].push_back({b,!vis[c]}),adj[b].push_back({a,!vis[c]});
        dfs1();
        dfs2(1,-1,n);
        //for(i=1;i<=n;i++)cout<<sub[i]<<" "<<up[i]<<endl;
        for(i=1; i<=n; i++)
        {
            ll cur=sub[i]+up[i];
            cn+=cur*(cur-1);
        }
    //}
    cout<<cn<<endl;
    return 0;
}
