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
const int mxN=1e5+3,mod=1e9+7;
char ch[10][10];
int ar[12];
signed main()
{
    //fast;
    //w(t)
    //{
    int n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=INT_MAX;
    string s,ss,sr;
    cin>>n>>m;ans=INT_MAX;
    for(i=0; i<m; i++)ar[i]=i;
    for(i=0; i<n; i++)cin>>ch[i];
    do
    {
        mn=INT_MAX,mx=0;
        for(i=0; i<n; i++)
        {
            cn=0;
            for(j=0; j<m; j++)
                cn=cn*10+(ch[i][ar[j]]-'0');
            mn=min(mn,cn);
            mx=max(cn,mx);
        }
        ans=min(ans,mx-mn);
    }
    while(next_permutation(ar,ar+m));
    cout<<ans<<endl;
    //}
    return 0;
}
