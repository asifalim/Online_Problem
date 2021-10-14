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
int t,ans=0,tot=0,k=0;map<pair<int,int>,int>mp;
const int mxN=2e5+8,mod=1e9+7;
vector<int>adj[mxN];vector<pair<int,int>>bridge;
int in[mxN],out[mxN],rnk[mxN],dis[mxN],lca[mxN][23],root[mxN];
void freecall(int n)
{
    for(int i=1;i<=n;i++)root[i]=i,rnk[i]=1,adj[i].clear(),in[i]=out[i]=dis[i]=0;mem(lca,0);bridge.clear();
}
int find(int n)
{
    return root[n]=root[n]==n?n:find(root[n]);
}
void Union(int a,int b)
{
    a=find(a);b=find(b);
    if(a==b)return;
    if(rnk[a]<rnk[b])swap(a,b);
    root[b]=a;
    rnk[a]+=rnk[b];
}
void dfs(int n,int par=-1)
{
    in[n]=out[n]=++tot;
    for(auto i:adj[n])
    {
       if(i==par)continue;
       if(in[i]){out[n]=min(out[n],in[i]);continue;}
       dfs(i,n);
       out[n]=min(out[n],out[i]);
       if(out[i]>in[n])bridge.push_back({n,i});
       else Union(n,i);
    }
}
void dfs1(int n,int pa=0)
{
    lca[n][0]=pa;
    for(int i=1;i<20;i++)lca[n][i]=~lca[n][i-1]?lca[lca[n][i-1]][i-1]:-1;
    for(auto i:adj[n])if(i!=pa)dis[i]=dis[n]+1,dfs1(i,n);
}
int help(int n,int m)
{
    if(dis[n]<=dis[m])swap(n,m);
    for(int i=18;~i;i--)if(dis[n]-(1<<i)>=dis[m])n=lca[n][i];
    if(n==m)return n;
    for(int i=18;~i;i--)if(lca[n][i]!=lca[m][i])n=lca[n][i],m=lca[m][i];
    return lca[n][0];
}
int dist(int n,int m)
{
    return dis[n]+dis[m]-2*dis[help(n,m)];
}
signed main()
{
    fast;
    w(t)
    {
        int n,m,a,b,c,d,i,j,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=INT_MAX,mx1;
        string s,ss,sr;map<int,int>mp,mp1;
        bool f=false,ff=false;
        cin>>n>>m;tot=0;freecall(n);
        for(i=1;i<=m;i++)cin>>a>>b,adj[a].push_back(b),adj[b].push_back(a);
        dfs(1);mem(adj,0);tot=0;
        for(i=1;i<=n;i++)
        {
            mp[i]=find(i);
            if(!mp1[mp[i]])mp1[mp[i]]=++tot;
        }
        for(auto i:bridge)adj[mp1[mp[i.first]]].push_back(mp1[mp[i.second]]),adj[mp1[mp[i.second]]].push_back(mp1[mp[i.first]]);
        dfs1(1);cin>>m;cout<<"Case "<<++k<<":"<<endl;
        while(m--)
        {
            cin>>a>>b;cn=0;if(mp1[mp[a]]!=mp1[mp[b]]);cn=dist(mp1[mp[a]],mp1[mp[b]]);
            cout<<cn<<endl;
        }
    }
    return 0;
}
