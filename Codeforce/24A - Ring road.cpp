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
vector<int>adj[112];
int vis[112][112],cost1[112][112];
void dfs(int n,int par)
{
    for(auto i:adj[n])
    {
        if(vis[n][i])continue;
        vis[n][i]=vis[i][n]=true;
        if(!cost1[n][i])tot+=cost1[i][n];
        else ans+=cost1[n][i];//dbg(i,ans,tot);
        dfs(i,n);
    }
}
signed main()
{
    //fast;
    //w(t)
    //{
    int n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=INT_MAX;
    string s,ss,sr;
    cin>>n;
    for(i=0;i<n;i++)cin>>a>>b>>c,adj[a].push_back(b),adj[b].push_back(a),cost1[a][b]=c;
    dfs(1,-1);
    cout<<min(ans,tot)<<endl;
    //}
    return 0;
}
