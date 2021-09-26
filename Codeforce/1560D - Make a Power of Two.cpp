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
const int mxn=2e5+10,mod=1e9+7;
vector<string>powof2;
int run(string s,string t)
{
    int taken=0,sp=0,tp=0;
    while(sp<s.size() and tp<s.size())
    {
        if(s[sp]==t[tp])taken++,tp++;
        sp++;
    }
    return (int)s.size()-taken+(int)t.size()-taken;
}
signed main()
{
    for(ll p=1;p<=INF;p*=2)powof2.push_back(to_string(p));
    //fast;
    w(t)
    {
        int n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=-1e9,mn=1e9;
        string s,ss,sr,sa;
        bool f=false,ff=true;
        cin>>s;
        mn=s.size()+1;
        for(auto i:powof2)mn=min(mn,run(s,i));
        cout<<mn<<endl;
    }
}
