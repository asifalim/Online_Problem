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
const int mxn=1e6+3,mod=1e9+7;

signed main()
{
    //fast;
    //w(t)
    //{
    int n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=INT_MAX;
    string s,ss,sr;
    cin>>s>>n;
    while(n--)
    {
        cin>>a>>b>>c;
        a--;
        b--;
        m=b-a+1;
        c%=m;
        ss="";
        for(i=b-c+1; i<=b; i++)ss+=s[i];
        for(i=a; i<=b-c; i++)ss+=s[i];
        for(i=a; i<=b; i++)s[i]=ss[i-a];
    }
    cout<<s<<endl;
    //}
    return 0;
}
