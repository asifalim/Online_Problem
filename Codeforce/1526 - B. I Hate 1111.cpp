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
const int mxn=1221+10,mod=1e9+7;
bool ha[mxn];
void help()
{
   ha[0]=true;
   for(int i=11;i<=mxn;i++)
   {
       ll sub=11;
       while(i>=sub)
       {
           if(ha[i-sub]){ha[i]=true;break;}
           sub=sub*10+1;
       }
   }
}
signed main()
{
    help();
    //fast;
    w(t)
    {
        int n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=1e9+2;
        string s,ss,sr;
        bool f=false,ff=true;
        cin>>n;
        if(n<=mxn)cout<<(ha[n]?"YES":"NO")<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
