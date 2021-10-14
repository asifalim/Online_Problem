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
ll t,ans=0,tot=0,k=0;bool fr=false;
const int mxN=5e5+3,mod=1e9+7;
vector<int>adj[mxN];int ar[mxN];
int node[30*mxN][3],cnt[30*mxN];
void insert(int n)
{
    int now=0;
    for(int i=30;~i;i--)
    {
        bool bit=(n>>i)&1;
        node[now][bit]=(!node[now][bit]?++k:node[now][bit]);
        now=node[now][bit];
        cnt[now]++;
    }
}
ll search(int n)
{
    ll now=0,res=0;
    for(int i=30;~i;i--)
    {
        bool bit=(n>>i)&1;
        if(node[now][!bit])res+=(1<<i),now=node[now][!bit];
        else now=node[now][bit];
    }
    return res;
}
void clear(int n)
{
    int now=0,prev=0;
    for(int i=30;~i;i--)
    {
        bool bit=(n>>i)&1;
        now=node[now][bit];
        cnt[now]--;
        if(!cnt[now])node[prev][bit]=0;
        prev=now;
    }
}
void dfs(int n,int par)
{
    if(n>1)tot=max(tot,search(ar[n]));
    insert(ar[n]);
    for(auto i:adj[n])if(i!=par)dfs(i,n);
    clear(ar[n]);
}
signed main()
{
    //fast;
    //w(t)
   // {
        int n,m,a,b,c,d,i,j,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=INT_MAX,mx1;
        string s,ss,sr;
        bool f=false,ff=false;
        cin>>n;tot=INT_MIN;
        for(i=1;i<=n;i++)cin>>ar[i];
        for(i=1;i<n;i++)cin>>a>>b,adj[a].push_back(b),adj[b].push_back(a);
        dfs(1,-1);
        cout<<tot<<endl;
   // }
    return 0;
}
