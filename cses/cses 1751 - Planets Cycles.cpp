//https://cses.fi/problemset/task/1751/
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define dbg(a,b,c) cout<<a<<"  "<<b<<"  "<<c<<endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define endl "\n"
#define INF 1e9
#define w(t) cin>>t;while(t--)
#define kill(a) {cout<<a<<endl;continue;}
#define pi  2 * acos(0.0)
int t,ans=0,tot=0,kk=0,N;
const int mxn=2e5+3,mod=1e9+7;
vector<int>adj[mxn],vis,len(mxn,INF),rec(mxn,0);
int ar[mxn];
void dfs2(int n,int dis)
{
    vis[n]=true;
    len[n]=dis;
    for(auto i:adj[n])if(len[i]==INF)dfs2(i,dis+1);
}
void dfs(int n)
{
    rec.clear();
    for(int i=n,cnt=0;;i=ar[i],cnt++)
    {
        int cyclen=cnt-rec[i];
        if(vis[i])
        {
            int v=i;
            while(len[i]==INF)len[i]=cyclen,i=ar[i];
            for(auto I:adj[v])if(len[I]==INF)dfs2(I,len[v]+1);
            break;
        }
        vis[i]=true;
        rec[i]=cnt;
    }
}
signed main()
{
    //fast;
    //w(t)
   // {
        int n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=1e9;
        string s,ss,sr;
        bool f=false,ff=true;
        cin>>n;vis.assign(n+2,false);
        for(i=1;i<=n;i++)cin>>a,adj[a].push_back(i),ar[i]=a;
        for(i=1;i<=n;i++)if(!vis[i])dfs(i);
        for(i=1;i<=n;i++)cout<<len[i]<<" ";cout<<endl;
   // }
    return 0;
}
