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
int t,ans=0,tot=0,kk=0;
const int mxn=1e6+3,mod=1e9+7;
vector<int>adj[mxn+2],dis;
void dfs(int n=1,int par=-1)
{
    for(auto i:adj[n])if(i!=par)dis[i]=dis[n]+1,dfs(i,n);
}
void dfs1(int n,int par,int m)
{
    ans=max(ans,dis[n]*2);
    for(auto i:adj[n])
    {
        if(i!=1 and i!=par and abs(dis[m]-dis[i])<dis[i])dfs1(i,n,m);
    }
}
signed main()
{
    //fast;
    //w(t)
    //{
    int n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=INT_MAX;
    string s,ss,sr;
    cin>>n>>m;dis.assign(n+2,0);
    for(i=1;i<n;i++)cin>>a>>b,adj[a].push_back(b),adj[b].push_back(a);
    dfs();dfs1(m,-1,m);
    cout<<ans<<endl;
    //}
    return 0;
}
