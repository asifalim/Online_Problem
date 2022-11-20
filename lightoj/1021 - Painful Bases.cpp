#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define dbg(a,b,c,d) cerr<<a<<"  "<<b<<"  "<<c<<"  "<<d<<endl;
#define kill(a) {cout<<a<<endl;continue;}
#define KILL(a) {cout<<a<<endl;return 0;}
#define debug cerr<<"Error Found"<<endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define lcm(a, b) (a/__gcd(a,b))*b
#define w(t) cin>>t;while(t--)
#define pi  2 * acos(0.0)
#define ll long long int
#define endl "\n"
#define INF (1LL<<61)
int t,cs=1;
const int mxn=5e5+3,mod=1e9+7;
int m,base;
int64_t n;
string s;
int64_t dp[1<<12][21];
int get(char ch)
{
    if(ch>='A')return ch-'A'+10;
    return ch-'0';
}
int64_t run(int mask,int rem)
{
    if(__builtin_popcount(mask)==n)return rem==0;

    if(~dp[mask][rem])return dp[mask][rem];
    int64_t ans=0;
    bool ck[19];// it indicate after storing some elements the possible answer for remaining elements
    mem(ck,false);  // e.g: 12345-->Let current elements 125 so we should search for remaining by positioned them after current elements
    for(int i=0;i<n;i++)
    {
        if(!((1LL<<i)&mask) and !ck[get(s[i])]){
        ans+=run(mask|(1LL<<i),(get(s[i])+rem*base)%m);
        ck[get(s[i])]=true;}
    }
    return dp[mask][rem]=ans;
}
signed main()
{
    //fast;
    w(t)
    {
        cin>>base>>m;
        cin>>s;
        n=s.size();
        mem(dp,-1);
        cout<<"Case "<<cs++<<": "<<run(0,0)<<endl;

    }
}
