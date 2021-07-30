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
const int mxN=1e6+3,mod=1e9+7;
void general_approach()
{
    int n,m,cn,sm;
    vector<int>v;
    cin>>n;
    while(n)
    {
        m=n;
        sm=0;
        cn=1;
        while(m)
        {
            if(m%10)sm+=cn;
            m/=10;
            cn*=10;
        }
        v.push_back(sm);
        n-=sm;
    }
    cout<<v.size()<<endl;
    for(auto i:v)cout<<i<<" ";
    cout<<endl;
}
int dp[mxN+3];
vector<int>v;
void dfs1(int n)
{
    if(n>mxN)return;
    v.push_back(n);
    dfs1(n*10);
    dfs1(n*10+1);
}
int dfs2(int n)
{
    if(n<0)return 1e9;
    if(!n)return dp[n]=0;
    if(~dp[n])return dp[n];
    int now=1e9;
    for(auto i:v)now=min(now,1+dfs2(n-i));
    return dp[n]=now;
}
void recursive_approach()
{
    int n,m,i;
    dfs1(1);
    mem(dp,-1);
    cin>>n;
    m=dfs2(n);
    cout<<m<<endl;
    while(n)
    {
        for(auto i:v)
        {
            if(n-i<0)continue;
            if(dp[n-i]==dp[n]-1)
            {
                cout<<i<<" ";
                n-=i;
                break;
            }
        }
    }
    cout<<endl;
}
signed main()
{
    //fast;
    //w(t)
    //{
    int n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=INT_MAX;
    string s,ss,sr;
    //general_approach();
    //recursive_approach();
    //}
    return 0;
}
