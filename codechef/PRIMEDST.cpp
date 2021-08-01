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
const int mxn=1e5+3,mod=1e9+7;
bool prime[mxn];
int sub[mxn],par[mxn],cnt[mxn],nn,mx=0;
set<int>adj[mxn];vector<int>st;
void dfs1(int n,int p)
{
    sub[n]=1;nn++;
    for(auto i:adj[n])if(i!=p)dfs1(i,n),sub[n]+=sub[i];
}
int dfs2(int n,int p)
{
    for(auto i:adj[n])if(i!=p and sub[i]>nn/2)return dfs2(i,n);
    return n;
}
void add(int n,int p,int kc)
{
    for(auto i:st)if(i-kc>=0)ans+=(cnt[i-kc]);
    for(auto i:adj[n])if(i!=p)add(i,n,kc+1);
}
void suub(int n,int p,int kc)
{
    cnt[kc]++;mx=max(mx,kc);
    for(auto i:adj[n])if(i!=p)suub(i,n,kc+1);
}
void cen(int n,int p)
{
    nn=0;
    dfs1(n,n);
    int centre=dfs2(n,p);
    if(p==-1)p=centre;
    par[centre]=p;
    mx=0;cnt[0]=1;
    for(auto i:adj[centre])
    {
        add(i,centre,1);
        suub(i,centre,1);
    }
    for(int i=0;i<=mx;i++)cnt[i]=0;
    for(auto i:adj[centre])adj[i].erase(centre),cen(i,centre);
    adj[centre].clear();
}
signed main()
{
    //fast;
    //w(t)
    //{
        int n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0;
        string s,ss,sr,sss;
        cin>>n;
        for(i=2; i<=n; i++)
        {
            if(prime[i])continue;
            st.push_back(i);
            for(j=2*i; j<=n; j+=i)prime[j]=true;
        }
        for(i=1; i<n; i++)cin>>a>>b,adj[a].insert(b),adj[b].insert(a);
        cen(1,-1);
        double probability=double(ans)/double((1LL*n*(n-1))/2);
        cout<<setprecision(10)<<fixed<<probability<<endl;
    //}
    return 0;
}
