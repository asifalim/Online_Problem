#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define dbg(a,b,c) cout<<a<<"  "<<b<<"  "<<c<<endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define endl "\n"
#define INF 5e18
#define w(t) cin>>t;while(t--)
#define kill(a) {cout<<a<<endl;continue;}
#define pi  2 * acos(0.0)
int t,ans=0,tot=0,kk=0;
const int mxN=1e5+3,mod=1988;
vector<int>adj[mxN],cnt(mxN);
signed main()
{
    //fast;
    //w(t)
    //{
        int n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=INT_MAX;
        string s,ss,sr;
        cin>>n>>m;
        for(i=0; i<=10000; i++)
        for(j=i; j<=10000; j++)
        {
            if(__builtin_popcount(i^j)==m)
            {
                adj[i].push_back(j);
                if(i!=j)adj[j].push_back(i);
            }
        }
        for(i=0;i<n;i++)cin>>a,cnt[a]++;
        for(i=0;i<=10000;i++)
        {
            for(auto j:adj[i])sm+=(ll)cnt[i]*cnt[j];
        }
        if(!m)sm-=n;
        cout<<sm/2<<endl;
    //}
    return 0;
}
