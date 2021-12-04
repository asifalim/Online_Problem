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
vector<int>adj[mxn],v;
void dfs(int n,int par=-1)
{
    for(auto i:adj[n])if(i!=par)dfs(i,n);
    if(adj[n].size()==1)v.push_back(n);
}
signed main()
{

    //fast;
    //w(t)
    // {
    int n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=-1e9,mn=1e9;
    string s,ss,sr,sa;
    bool f=true;
    cin>>n;
    for(i=1;i<n;i++)cin>>a>>b,adj[a].push_back(b),adj[b].push_back(a);
    dfs(1);
    m=v.size();m++;
    cout<<m/2<<endl;
    if(m%2==0)v.push_back(v[0]);
    for(i=0;i<m/2;i++)cout<<v[i]<<" "<<v[i+m/2]<<endl;
    // }
}
