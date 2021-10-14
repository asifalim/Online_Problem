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
const int mxN=1e5+8,mod=1e9+7;
vector<int>adj[mxN];bool vis[mxN];
unordered_map<string,int>mp;
int dis[mxN];
int dfs(int n,int par=-1)
{
    if(vis[n])return dis[n];
    dis[n]=0;vis[n]=true;
    for(auto i:adj[n])dis[n]=max(dis[n],1+dfs(i));
    return dis[n];
}
signed main()
{
    fast;
    w(t)
    {
        int n,m,a,b,c,d,i,j,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=INT_MAX,mx1;
        string s,ss,sr;
        bool f=false,ff=false;
        mem(adj,0);mem(vis,false);
        cin>>n;
        tot=0;mp.clear();
        for(i=1; i<=n; i++)
        {
            cin>>s>>b;
            if(!mp[s])mp[s]=++tot;
            for(j=1; j<=b; j++)
            {
                cin>>ss;
                if(!mp[ss])mp[ss]=++tot;
                adj[mp[s]].push_back(mp[ss]);
            }
        }
        cin>>m;
        cout<<"Case "<<++k<<":"<<endl;
        while(m--)cin>>s,cout<<dfs(mp[s])<<endl,vis[mp[s]]=true;
    }
    return 0;
}
