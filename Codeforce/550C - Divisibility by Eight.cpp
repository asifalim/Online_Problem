#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define dbg(a,b,c) cout<<a<<"  "<<b<<"  "<<c<<endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define endl "\n"
#define INF 1e17
#define w(t) cin>>t;while(t--)
#define kill(a) {cout<<a<<endl;continue;}
#define pi  2 * acos(0.0)
int t,ans=0,tot=0,cnt=0,kk=0;
const int mxN=2e5+3,mod=1e9+7;
int N,dp[111][9][2];string s;
bool rec(int idx,int mod,bool f)
{
    if(idx>=N)
    {
        if(!mod and f)return 1;
        return 0;
    }
    if(~dp[idx][mod][f])return dp[idx][mod][f];
    bool r=0;
    r|=rec(idx+1,mod,f);
    r|=rec(idx+1,(mod*10+s[idx]-'0')%8,1);
    return dp[idx][mod][f]=r;
}
void path(int idx,int mod)
{
    if(idx==N)return;
    if(rec(idx+1,mod,kk))path(idx+1,mod);
    else
    {
        cout<<s[idx];
        kk=1;
        path(idx+1,(mod*10+s[idx]-'0')%8);
    }
}
signed main()
{
    //fast;
    //w(t)
    //{
        int n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=INT_MAX;
        //string s,ss,sr;;
        bool f=false,ff=false;
        cin>>s;N=s.size();mem(dp,-1);
        if(!rec(0,0,0))return cout<<"NO"<<endl,0;
        cout<<"YES"<<endl;
        path(0,0);
    //}
    return 0;
}
