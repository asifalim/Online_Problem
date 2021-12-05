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

signed main()
{

    //fast;
    //w(t)
    //{
    ll n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=-1e9,mn=1e9;
    string s,ss,sr,sa;
    bool f=true;
    cin>>n;
    int dp[n+1][n+1];
    mem(dp,-1);
    char ch;
    for(i=0; i<=n; i++)dp[i][0]=dp[0][i]=0;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            cin>>ch;
            if(ch=='*')dp[i][j]=0;
        }
    }
    dp[0][1]=1;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(dp[i][j]==0)continue;
            dp[i][j]=dp[i][j-1]+dp[i-1][j];
            dp[i][j]%=mod;
        }
    }
    cout<<dp[n][n]<<endl;
    //}
}
