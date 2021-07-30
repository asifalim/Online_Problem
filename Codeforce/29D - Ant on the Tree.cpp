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
const int mxN=1e6+3,mod=1e9+7;
vector<int>adj[mxN],v;
bool dfs(int n,int m,int par)
{
    if(n==m)return true;
    for(auto i:adj[n])
    {
        if(i==par)continue;
        if(dfs(i,m,n))
        {
            v.push_back(n);
            return true;
        }
    }
    return false;
}
signed main()
{
    //fast;
    //w(t)
    //{
    int n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=INT_MAX;
    string s,ss,sr;
    cin>>n;
    for(i=1; i<n; i++)cin>>a>>b,adj[a].push_back(b),adj[b].push_back(a);
    d=1;
    v.push_back(1);
    while(~scanf("%d",&m))dfs(m,d,-1),d=m;
    dfs(1,d,-1);
    if(v.size()!=2*n-1)return cout<<-1<<endl,0;
    for(auto i:v)cout<<i<<" ";
    cout<<endl;
    //}
    return 0;
}
