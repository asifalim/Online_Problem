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
ll t,ans=0,tot=0,kk=0;
const int mxn=2e5+4,mod=1e9+7;
bool check(ll mid,ll k)
{
    ll sm=0;
    for(ll i=1;i<=mid;i*=10)
    {
        ll temp=i*10;
        sm+=(mid/temp)*i+min(max(mid%temp-i+1,0LL),i);
    }
    return sm<=k;
}
signed main()
{
    //fast;
    // w(t)
    // {
    ll n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=-1e9,mn=1e9;
    string s,ss,sr,sa;
    bool f=true;
    cin>>n;
    ll low=1,high=1e18;
    while(low<=high)
    {
        ll mid=(low+high)/2;
        if(check(mid,n))low=mid+1;
        else high=mid-1;
    }
    cout<<low-1<<endl;
    // }
}
