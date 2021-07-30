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
const int mxn=5e3+3,mod=1e9+7;
signed main()
{
    //fast;
    //w(t)
    // {
    ll n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=INT_MAX;
    //string s,ss,sr;
    bool f=false,ff=false;
    cin>>n>>m;
    if(m+1>n*2/m)return cout<<-1<<endl,0;
    a=m*(m+1)/2;
    for(i=1; i*i<=n; i++)
    {
        if(n%i==0)
        {
            if(i<=n/a)mx=max(mx,i);
            if(n/i<=n/a)mx=max(mx,n/i);
        }
    }
    assert(mx>0);
    b=n/mx;
    for(i=1; i<m; i++)c=i*mx,cout<<c<<" ";
    cout<<(b-m*(m-1)/2)*mx<<endl;
    //}
    return 0;
}
