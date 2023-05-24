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
int t,cs=0;
const int mxn=1e6+2,mod=1e9+7;
bool vis[mxn];
int prime[mxn];
void sieve()
{
    for(int i=2; i*i<mxn; i++)if(!vis[i])for(int j=i*i; j<mxn; j+=i)vis[j]=true;
    for(int i=2; i<mxn; i++)if(!vis[i])prime[cs++]=i;
}
int inverse(int64_t a,int64_t b)
{
    int64_t x=1,y=0,md=b,prev;
    while(b)
    {
        prev=y;
        y=x-(a/b)*y;
        x=prev;
        a=a%b;
        swap(a,b);
    }
    if(x<0)x+=md;
    return x;
}
int fact[mxn];
void pre(int n,int md)
{
    fact[0]=fact[1]=1;
    for(int i=2; i<=n; i++)fact[i]=1LL*fact[i-1]*i%md;
}
int power(int64_t base,int po,int md)
{
    int64_t res=1;
    while(po)
    {
        if(po&1)res=1LL*res*base%md;
        base*=base,base%=md,po/=2;
    }
    return res;
}
int ncr(int n,int r,int md)
{
    if(n<r)return 0;
    int64_t ans=fact[n];
    ans=1LL*ans*power(fact[n-r],md-2,md)%md;
    ans=1LL*ans*power(fact[r],md-2,md)%md;
    return ans;
}
vector<int>baseconvert(int n,int md)
{
    vector<int>ans;
    while(n)
    {
        ans.push_back(n%md);
        n/=md;
    }
    return ans;
}
int lucus(int n,int r,int md)
{
    if(r>n)return 0;
    vector<int>N=baseconvert(n,md),R=baseconvert(r,md);
    int mx=*max_element(N.begin(),N.end());
    pre(mx,md);
    //for(int i=0;i<10;i++)cout<<fact[i]<<" ";cout<<endl;
    int64_t ans=1;
    for(int i=0; i<R.size(); i++)ans=1LL*ans*ncr(N[i],R[i],md)%md;
    return ans;
}
int32_t main()
{
    sieve();
    //fast;
    w(t)
    {
        int n,r,m;
        cin>>n>>r>>m;
        vector<int>factor;
        for(int i=0; i<cs and prime[i]*prime[i]<=m; i++)
        {
            if(m%prime[i]==0)
            {
                while(m%prime[i]==0)m/=prime[i];
                factor.push_back(prime[i]);
            }
        }
        if(m>1)factor.push_back(m);
        vector<int>rem;
        int64_t MUL=1;
        for(auto i:factor)rem.push_back(lucus(n,r,i)),MUL=1LL*MUL*i;
        int64_t ans=0;
        //for(auto i:rem)cout<<i<<" ";cout<<endl;
        for(int i=0; i<factor.size(); i++)
        {
            int remm=rem[i];
            int64_t mul=MUL/factor[i];
            int inv=inverse(mul,factor[i]);
            //dbg(remm,mul,inv,ans);
            ans+=1LL*remm*mul*inv,ans%=MUL;
        }
        cout<<ans<<endl;
    }
}
