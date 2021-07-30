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
int t,ans=0,tot=0,kk=0,n,m,k;
const int mxn=1e6+3,mod=1e9+7;
char ch[12][12][12];
bool vis[12][12][12];
void dfs(int z,int x,int y)
{
    if(ch[z][x][y]=='#' or z<0 or x<0 or y<0 or z==k or x==n or y==m or vis[z][x][y])return;
    vis[z][x][y]=true;
    ans++;
    dfs(z,x+1,y);
    dfs(z,x-1,y);
    dfs(z,x,y-1);
    dfs(z,x,y+1);
    dfs(z-1,x,y);
    dfs(z+1,x,y);
}
signed main()
{
    //fast;
    //w(t)
    //{
    int a,b,c,d,e,i,j,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=INT_MAX;
    string s,ss,sr;
    cin>>k>>n>>m;
    for(i=0; i<k; i++)
    for(j=0; j<n; j++)cin>>ch[i][j];
    cin>>a>>b;
    dfs(0,a-1,b-1);
    cout<<ans<<endl;
    //}
    return 0;
}
