#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define dbg(a,b,c) cout<<a<<"  "<<b<<"  "<<c<<endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define endl "\n"
#define w(t) cin>>t;while(t--)
int t,k,ans=0,tot=0;map<ll,int>mp;
const int mxN=2e4+10,mod=1e9+7;bool found=false;
void help(int n,int m)
{
    if(n==m)found=true;
    if(n*2<=m)mp[n*2]=n,help(n*2,m);
    if(n*3<=m)mp[n*3]=n,help(n*3,m);
}
int32_t main()
{
    //fast;
    //w(t)
    //{
        int n,m,a,b,c,d,i,j,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=INT_MAX;
        string s,ss;
        bool f=true,ff=true,fff=true;
        cin>>n>>m;
        help(n,m);
        if(!found)return cout<<-1<<endl,0;
        while(m!=n)cn++,m=mp[m];
        cout<<cn<<endl;
    //}
    return 0;
}
