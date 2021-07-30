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
const int mxN=1e5+3,mod=1e9+7,N=31;
int basis[N+1],sz=0,ar[mxN];
void insertVector(int mask)
{
    for(int i=0;i<N;i++)
    {
        if((mask&1<<i)==0)continue;
        if(!basis[i]){basis[i]=mask;sz++;return;}
        mask^=basis[i];
    }
}
signed main()
{
    //fast;
    //w(t)
    //{
    int n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=INT_MAX;
    string s,ss,sr;
    cin>>n;
    for(i=1; i<=n; i++)cin>>m,a^=m,insertVector(m);
    if(a==0)cout<<-1<<endl;
    else cout<<sz<<endl;
    //}
    return 0;
}
