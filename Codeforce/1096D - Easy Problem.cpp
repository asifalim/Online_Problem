#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define dbg(a,b,c) cout<<a<<"  "<<b<<"  "<<c<<endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define endl "\n"
#define INF 1e16
#define w(t) cin>>t;while(t--)
#define kill(a) {cout<<a<<endl;continue;}
#define pi  2 * acos(0.0)
int t,ans=0,tot=0,kk=0,N;
const int mxn=2e6+3,mod=1e9+7;
signed main()
{
    //fast;
    //w(t)
    //{
        int n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=1e9;
        string s,ss,sr;
        cin>>n>>s;ss="hard";
        int ar[n+1];
        for(i=1;i<=n;i++)cin>>ar[i];
        ll dp[n+1][5];mem(dp,62);
        for(i=1;i<=4;i++)dp[0][i]=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=4;j++)
            {
                if(s[i-1]==ss[j-1])dp[i][j]=min({dp[i-1][j-1],dp[i-1][j]+ar[i]});
                else dp[i][j]=dp[i-1][j];
            }
        }
        cout<<dp[n][4]<<endl;
    //}
    return 0;
}
