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
vector<ll>cost1,cost2;
bool vis[mxN];
vector<pair<int,int>>adj[mxN],radj[mxN];
void dij(int x)
{
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
    pq.push({0,x});cost1[x]=0;mem(vis,false);
    while(!pq.empty())
    {
        ll node=pq.top().second,node_dis=pq.top().first;pq.pop();if(vis[node])continue;vis[node]=true;
        for(auto i:adj[node])if(i.second+node_dis<cost1[i.first])cost1[i.first]=i.second+node_dis,pq.push({cost1[i.first],i.first});
    }
}
void rdij(int x)
{
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
    pq.push({0,x});cost2[x]=0;mem(vis,false);
    while(!pq.empty())
    {
        ll node=pq.top().second,node_dis=pq.top().first;pq.pop();if(vis[node])continue;vis[node]=true;
        for(auto i:radj[node])if(i.second+node_dis<cost2[i.first])cost2[i.first]=i.second+node_dis,pq.push({cost2[i.first],i.first});
    }
}
signed main()
{
    //fast;
    w(t)
    {
        int n,m,a,b,c,d,e,i,j,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=INT_MAX,mx1;
        string s,ss,sr;
        bool f=true,ff=false;mem(adj,0);mem(radj,0);
        cin>>n>>m>>a>>b;cost1.assign(n+1,INF);cost2.assign(n+1,INF);
        for(i=1;i<=m;i++)cin>>c>>d>>e,adj[c].push_back({d,e}),radj[d].push_back({c,e});
        dij(a);rdij(a);cout<<"Case "<<++k<<":"<<endl;
        while(b--)
        {
            cin>>n>>m;
            if(cost1[m]==INF or cost2[n]==INF)kill("Be seeing ya, John");
            kill(cost1[m]+cost2[n]);
        }
    }
    return 0;
}
