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
bool found=false;
map<ll,ll>mp;
void dfs(ll st,ll en)
{
    if(st==en)found=true;
    if(st*2<=en)mp[st*2]=st,dfs(st*2,en);
    if(st*10+1<=en)mp[st*10+1]=st,dfs(st*10+1,en);
}
signed main()
{
    //fast;
    //w(t)
    //{
    int n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=INT_MAX;
    string s,ss,sr;
    cin>>n>>m;
    dfs(n,m);
    vector<ll>v;
    v.push_back(m);
    if(!found)return cout<<"NO"<<endl,0;
    while(m!=n)m=mp[m],v.push_back(m);
    cout<<"YES"<<endl<<v.size()<<endl;
    reverse(v.begin(),v.end());
    for(auto i:v)cout<<i<<" ";
    cout<<endl;
    //}
    return 0;
}
