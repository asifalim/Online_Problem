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
const int mxn=2e5+4,mod=1e9+7;
vector<int>adj[mxn];
void bfs(int n)
{
    int dis[mxn];
    mem(dis,-1);
    queue<int>q;
    q.push(n);dis[n]=0;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto i:adj[node])
        {
            if(dis[i]==-1)q.push(i),dis[i]=dis[node]+1;
            else if(dis[i]>=dis[node])tot=min(tot,dis[i]+dis[node]+1);
        }
    }
}
signed main()
{

    //fast;
    //w(t)
    // {
    int n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=-1e9,mn=1e9;
    string s,ss,sr,sa;
    bool f=true;
    cin>>n>>m;tot=1e9;
    for(i=0;i<m;i++)cin>>a>>b,adj[a].push_back(b),adj[b].push_back(a);
    for(i=1;i<=n;i++)bfs(i);
    cout<<(tot==1e9?-1:tot)<<endl;
    // }
}
