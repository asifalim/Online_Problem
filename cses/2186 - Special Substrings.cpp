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
const int mxn=2e5+4,mod=1e9+7;
signed main()
{

    //fast;
    //w(t)
    // {
    ll n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=-1e9,mn=1e9;
    string s,ss,sr,sa;
    bool f=true;
    cin>>s;n=s.size();int cnt[27]={0};
    for(auto i:s)cnt[i-'a']++;
    vector<int>v;
    for(i=0;i<26;i++)if(cnt[i])v.push_back(i),cnt[i]=0;
    m=v.size();
    vector<int>ar(m-1,0);
    map<vector<int>,int>mp;
    mp[ar]++;
    for(auto I:s)
    {
        cnt[I-'a']++;
        for(i=1;i<m;i++)
        {
            ar[i-1]=cnt[v[i]]-cnt[v[i-1]];
        }
        sm+=mp[ar];
        mp[ar]++;
    }
    cout<<sm<<endl;
    // }
}
