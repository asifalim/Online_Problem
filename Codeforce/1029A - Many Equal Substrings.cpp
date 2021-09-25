#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define dbg(a,b,c) cout<<a<<"  "<<b<<"  "<<c<<endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define endl "\n"
#define INF 1e9
#define w(t) cin>>t;while(t--)
#define kill(a) {cout<<a<<endl;continue;}
#define pi  2 * acos(0.0)
int t,ans=0,tot=0,kk=0;
const int mxn=2e5+10,mod=1e9+7;
signed main()
{
    //fast;
    //w(t)
    //{
    int n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=-1e9,mn=1e9;
    string s,ss,sr,sa;
    bool f=false,ff=true;
    cin>>n>>m>>s;int len=0;
    for(k=1;k<n;k++)
    {
        i=0,j=n-k;
        while(j<n and s[i]==s[j])i++,j++;
        if(j==n)len=k;
    }
    cout<<s.substr(0,len);
    while(m--)cout<<s.substr(len);cout<<endl;
    // }
}
