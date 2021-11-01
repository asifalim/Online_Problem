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
const int mxn=1e6+27,mod=1e9+7;

signed main()
{

    //fast;
    //w(t)
    //{
        ll n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=-1e9,mn=1e9;
        string s,ss,sr,sa,sss;
        bool f=false,ff=false;
        cin>>n>>m;set<pair<int,int>>st;
        for(i=1;i<=n;i++)st.insert({0,i});
        int cnt[n+1]={0};
        for(i=0;i<m;i++)
        {
            cin>>a;
            st.erase({cnt[a],a});
            st.insert({++cnt[a],a});
            mn=(*st.begin()).first;
            if(mn>cn)cout<<1,cn++;
            else cout<<0;
        }
        cout<<endl;
   // }
}
