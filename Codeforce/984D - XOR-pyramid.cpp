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
int t,ans=0,tot=0,kk=0;
const int mxn=5e3+3,mod=1e9+7;//vector<pair<int,int>>v;
ll dp[mxn][mxn],sol[mxn][mxn],ar[mxn];
bool vis[mxn][mxn],viss[mxn][mxn];
ll rec(int i,int j)
{
    if(i>j)return 0;
    if(i==j)return sol[i][j]=ar[i];
    if(vis[i][j])return sol[i][j];
    vis[i][j]=1;
    return sol[i][j]=rec(i+1,j)^rec(i,j-1);
}
ll get(int i,int j)
{
    //v.push_back({i,j});
    if(i==j)return sol[i][j];
    if(viss[i][j])return dp[i][j];
    viss[i][j]=1;
    return dp[i][j]=max(sol[i][j],max(get(i,j-1),get(i+1,j)));   //Traverse 2D sol array for a particular segment. [first execute second part of max]
}
signed main()
{
    //fast;
    //w(t)
   // {
    ll n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=INT_MAX;
    //string s,ss,sr;
    bool f=false,ff=false;
    cin>>n;
    for(i=0;i<n;i++)cin>>ar[i];
    for(i=0;i<n;i++)for(j=0;j<n;j++)sol[i][j]=rec(i,j);
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)cout<<sol[i][j]<<" ";cout<<endl;
    }*/
    cin>>m;
    while(m--)
    {
        cin>>a>>b;a--;b--;
        cout<<get(a,b)<<endl;
    }
    //}
    return 0;
}
