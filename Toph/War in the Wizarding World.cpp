#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define dbg(a,b,c) cout<<a<<"  "<<b<<"  "<<c<<endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define endl "\n"
#define INF 1e5
#define w(t) cin>>t;while(t--)
#define kill(a) {cout<<a<<endl;continue;}
#define pi  2 * acos(0.0)
int t,ans=0,tot=0,k=0;
const int mxN=1e5,MX=305,mod=1e9+7;
ll cap[MX][MX];int par[MX],cost1[MX],cost2[MX];
vector<pair<int,int>>adj[MX];
vector<ll>dis,vis;
int bfs(int s,int t)
{
    mem(par,-1);
   queue<pair<int,int>>q;
   q.push({s,INF});
   while(!q.empty())
   {
       int node=q.front().first,flow=q.front().second;q.pop();
       for(auto edge:adj[node])if(par[edge.first]==-1 and cap[node][edge.first])
       {
           par[edge.first]=node;
           flow=min(1LL*flow,cap[node][edge.first]);
           if(edge.first==t)return flow;
           q.push({edge.first,flow});
       }
   }
   return false;
}
ll ed(int s,int t)
{
    ll flow=0,new_flow;
    while(new_flow=bfs(s,t))
    {
        flow+=new_flow;
       int cur=t,prev;
       while(cur!=s)
       {
           prev=par[cur];
           cap[prev][cur]-=new_flow;
           cap[cur][prev]+=new_flow;
           cur=prev;
       }
    }
    return flow;
}
int dij(int n,int f,int m)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,n});dis.assign(m+1,INF);vis.assign(m+1,0);
    dis[n]=0;
    while(!pq.empty())
    {
        int node=pq.top().second,node_dis=pq.top().first;pq.pop();if(vis[node])continue;vis[node]=true;if(f)cost1[node]=node_dis;else cost2[node]=node_dis;
        for(auto edge:adj[node])if(node_dis+edge.second<dis[edge.first])dis[edge.first]=node_dis+edge.second,pq.push({dis[edge.first],edge.first});
    }
    if(f)return cost1[m];return cost2[1];
}
signed main()
{
    fast;
    w(t)
    {
        int n,m,a,b,c,d,i,j,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=INT_MAX,mx1;
        string s,ss,sr;mem(cap,0);
        bool f=false,ff=false;
        cin>>n>>m;mem(adj,0);
        pair<pair<int,int>,int>take[mxN];
        for(i=0; i<m; i++)cin>>a>>b>>c,take[i].first.first=a,take[i].first.second=b,take[i].second=c,adj[a].push_back({b,c}),adj[b].push_back({a,c});
        mem(cost1,0);
        mem(cost2,0);
        cn=dij(1,1,n);
        cn1=dij(n,0,n);
        for(i=1;i<=n;i++)adj[i].clear();
        for(i=0;i<m;i++)
        {
           int u=take[i].first.first,v=take[i].first.second,w=take[i].second;
           if((cost1[u]+cost2[v]+w)==cn or (cost1[v]+cost2[u]+w)==cn);
           else
           {
               cap[u][v]+=w;cap[v][u]+=w;
               adj[u].push_back({v,w});
               adj[v].push_back({u,w});
           }
        }
        mem(cost1,-1);
        sm=dij(1,1,n);
        cout<<"Case "<<++k<<": ";
        if(sm==-1)kill("-1 -1");
        cout<<sm<<" "<<ed(1,n)<<endl;
    }
    return 0;
}
