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
const int mxN=1e5+3,mod=1e9+7;
vector<pair<int,int>>adj[mxN];
ll parent[mxN],lca[mxN][20],dis[mxN],distt[mxN];
void dfs(int n,int par=-1,int dist=0,ll di=0)
{
    parent[n]=par;
    distt[n]=di;
    dis[n]=dist;
    lca[n][0]=par;
    for(int i=1;i<20;i++)lca[n][i]=~lca[n][i-1]?lca[lca[n][i-1]][i-1]:-1;
    for(auto i:adj[n])if(i.first!=par)dfs(i.first,n,dist+1,i.second+di);
}
int help(int n,int m)
{
    if(dis[n]<=dis[m])swap(n,m);
    for(int i=18;~i;i--)if(dis[n]-(1<<i)>=dis[m])n=lca[n][i];
    if(n==m)return n;
    for(int i=18;~i;i--)if(lca[n][i]!=lca[m][i])n=lca[n][i],m=lca[m][i];
    return parent[n];
}
signed main()
{
    //fast;
    //w(t)
    //{
        ll n,m,a,b,c,d,i,j,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=INT_MAX,mx1;
        string s,ss,sr;
        bool f=false,ff=false;
        cin>>n>>m;
        for(i=1;i<n;i++)cin>>a>>b>>c,adj[a].push_back({b,c}),adj[b].push_back({a,c});
        dfs(1);
        while(m--)
        {
            cin>>a;int ar[a+2];cn=cn1=0;
            for(i=1;i<=a;i++)cin>>ar[i];
            for(i=2;i<=a;i++)if(distt[ar[1]]+distt[ar[i]]-2*distt[help(ar[1],ar[i])]>cn)cn=distt[ar[1]]+distt[ar[i]]-2*distt[help(ar[1],ar[i])],sm=ar[i];
            for(i=1;i<=a;i++)if(distt[sm]+distt[ar[i]]-2*distt[help(sm,ar[i])]>cn1)cn1=distt[sm]+distt[ar[i]]-2*distt[help(sm,ar[i])];
            cout<<cn1<<endl;
        }
    //}
    return 0;
}
