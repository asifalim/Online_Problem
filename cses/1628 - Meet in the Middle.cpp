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
const int mxn=2e7+10,mod=1e9+7;
signed main()
{
    //fast;
   // w(t)
   //{
        ll n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=-1e9,mn=1e9;
        string s,ss,sr,sa;
        bool f=false,ff=true;int target;
        cin>>n>>target;m=n-n/2;n/=2;
        vector<ll>left,right,ar(n+m);
        for(i=0;i<n+m;i++)cin>>ar[i];
        for(i=0;i<1<<n;i++)
        {
             sm=0;
             for(j=0;j<n;j++)if(i>>j&1)sm+=ar[j];
             left.push_back(sm);
        }
        for(i=0;i<1<<m;i++)
        {
            sm=0;
            for(j=0;j<m;j++)if(i>>j&1)sm+=ar[n+j];
            right.push_back(sm);
        }
        sort(right.begin(),right.end());
        for(auto i:left)cn+=upper_bound(right.begin(),right.end(),target-i)-lower_bound(right.begin(),right.end(),target-i);
        cout<<cn<<endl;
    //}
}
