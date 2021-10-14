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
vector<int>adj[mxN];int child[mxN],in[mxN],out[mxN],cnt[mxN],from[mxN],root;ll ar[mxN];
void dfs(int n,int par=-1)
{
    in[n]=out[n]=++tot;ar[n]=0;
    cnt[n]=child[n]=1;from[n]=root;
    for(auto i:adj[n])
    {
        if(i==par)continue;
        if(in[i]){out[n]=min(out[n],in[i]);continue;}
        dfs(i,n);child[n]+=child[i];
        out[n]=min(out[n],out[i]);
        if(out[i]>=in[n])ar[n]+=1LL*cnt[n]*child[i],cnt[n]+=child[i];
    }
}
signed main()
{
    //fast;
    w(t)
    {
        int n,m,a,b,c,d,i,j,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=INT_MAX,mx1;
        string s,ss,sr;
        bool f=false,ff=false;mem(adj,0);
        cin>>n>>m;tot=0;
        for(i=1;i<=m;i++)cin>>a>>b,adj[a].push_back(b),adj[b].push_back(a);
        for(i=1;i<=n;i++)if(!in[i])root=i,dfs(i);
        cout<<"Case "<<++k<<":"<<endl;
        //for(i=1;i<=n;i++)dbg(cnt[i],child[i],ar[i]);
        for(i=1;i<=n;i++)ar[i]+=1LL*cnt[i]*(child[from[i]]-cnt[i]),cout<<ar[i]<<endl,adj[i].clear(),in[i]=0;
    }
    return 0;
}
