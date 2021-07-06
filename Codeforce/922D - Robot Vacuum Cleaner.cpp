#include<bits/stdc++.h>
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
const int mxn=2e5+3,mod=1e9+7;
signed main()
{
    //fast;
    //w(t)
    //{
    ll n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=1e9;
    string s,ss,sr;
    //bool f=true,ff=false;
    cin>>n;
    vector<string>ar(n);
    for(auto &i:ar)cin>>i;
    auto f=[](string s)
    {
        ll cn1=0,sm=0;
        for(auto i:s)if(i=='s')cn1++;else sm+=cn1;
        return sm;
    };
    sort(ar.begin(),ar.end(),[&](string &x,string &y)
    {
        return f(x+y)>f(y+x);
    });
    for(auto i:ar)s+=i;
    cout<<f(s)<<endl;
    //}
    return 0;
}
