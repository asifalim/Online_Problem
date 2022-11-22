#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define dbg(a,b,c,d) cerr<<a<<"  "<<b<<"  "<<c<<"  "<<d<<endl;
#define kill(a) {cout<<a<<endl;continue;}
#define KILL(a) {cout<<a<<endl;return 0;}
#define debug cerr<<"Error Found"<<endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define lcm(a, b) (a/__gcd(a,b))*b
#define w(t) cin>>t;while(t--)
#define pi  2 * acos(0.0)
#define ll long long int
#define endl "\n"
#define INF (1LL<<61)
int t,cs=1;
const int mxn=1e2+3,mod=1e9+7;
int n,ar[mxn];
int dp[mxn][mxn][2];
int run(int st,int ed,bool chance)
{
    if(st>ed)return 0;
    if(~dp[st][ed][chance])return dp[st][ed][chance];
    if(chance==0)
    {
        int sm=0,ans=-1e9;
        for(int i=st;i<=ed;i++)sm+=ar[i],ans=max(ans,sm+run(i+1,ed,1));
        sm=0;
        for(int i=ed;i>=st;i--)sm+=ar[i],ans=max(ans,sm+run(st,i-1,1));
        return dp[st][ed][chance]=ans;
    }
    else
    {
        int sm=0,ans=1e9;
        for(int i=st;i<=ed;i++)sm-=ar[i],ans=min(ans,sm+run(i+1,ed,0));
        sm=0;
        for(int i=ed;i>=st;i--)sm-=ar[i],ans=min(ans,sm+run(st,i-1,0));
        return dp[st][ed][chance]=ans;
    }

}
signed main()
{
    //fast;
    w(t)
    {
        cin>>n;
        mem(dp,-1);
        for(int i=0;i<n;i++)cin>>ar[i];
        cout<<"Case "<<cs++<<": "<<run(0,n-1,0)<<endl;
    }
}
