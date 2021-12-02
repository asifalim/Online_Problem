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
const ll mxn=2e5+4,mod=1e9+7;


signed main()
{

    //fast;
    //w(t)
   // {
        ll n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=-1e9,mn=1e9;
        string s,ss,sr,sa;
        bool f=false;
        ll dp[52];
        dp[0]=1;
        for(i=1;i<51;i++)dp[i]=2*dp[i-1]+((1LL<<(i-1))-1);
        //for(i=0;i<51;i++)cout<<dp[i]<<" ";cout<<endl;
        cin>>n;
        while(n)
        {
            m=log2(n);
            sm+=dp[m];
            m=1LL<<m;
            sm+=n-m;
            n=n-m;
        }
        cout<<sm<<endl;
   // }
}
