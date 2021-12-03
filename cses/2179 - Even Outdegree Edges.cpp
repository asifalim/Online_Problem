#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define dbg(a,b,c) cerr<<a<<"  "<<b<<"  "<<c<<endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define endl "\n"
#define INF 1e18
#define w(t) cin>>t;while(t--)
#define kill(a) {cout<<a<<endl;continue;}
#define pi  2 * acos(0.0)
int t,ans=0,tot=0,kk=0;
const ll mxn=2e5+4,mod=1e9+7;
vector<int>adj[mxn];
set<pair<int,int>>pr;
bool odd[mxn];
int vis[mxn];
void dfs(int n,int par=-1)
{
    vis[n]=++tot;
    for(auto i:adj[n])
    {
        if(i==par)continue;
        if(!vis[i])
        {
            dfs(i,n);
            if(odd[i])pr.insert({i,n}),odd[i]=0;
            else pr.insert({n,i}),odd[n]^=1;
        }
       else if(vis[n]>vis[i])pr.insert({n,i}),odd[n]^=1;
    }
}
signed main()
{

    //fast;
    //w(t)
    // {
    ll n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=-1e9,mn=1e9;
    //string s,ss,sr,sa;
    bool f=true;
    cin>>n>>m;
    for(i=0; i<m; i++)cin>>a>>b,adj[a].push_back(b),adj[b].push_back(a);
    for(i=1; i<=n; i++)if(!vis[i])dfs(i);
    if(accumulate(odd+1,odd+n+1,0))return cout<<"IMPOSSIBLE"<<endl,0;
    for(auto i:pr)cout<<i.first<<" "<<i.second<<endl;
    // }
}
