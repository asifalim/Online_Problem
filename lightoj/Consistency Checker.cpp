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
bool f=true;
struct node
{
    int child[11],cnt=0;
    bool end=false;
}nxt[mxn];
void insert(string s)
{
    int now=0;
    for(auto i:s)
    {
        nxt[now].child[i-'0']=(!nxt[now].child[i-'0']?++tot:nxt[now].child[i-'0']);
        now=nxt[now].child[i-'0'];
        nxt[now].cnt++;
    }
    nxt[now].end=true;
}
void search(int now=0)
{
    if(nxt[now].end and nxt[now].cnt>1){f=false;return;}
    for(int i=0;i<=9;i++)if(nxt[now].child[i])search(nxt[now].child[i]);
}
signed main()
{
    //fast;
    w(t)
    {
        int n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0;
        string s,ss,sr,sss;
        cin>>n;f=true;mem(nxt,0);
        for(i=1;i<=n;i++)cin>>s,insert(s);
        search();cout<<"Case "<<++kk<<": ";
        if(f)kill("YES");
        kill("NO");
    }
    return 0;
}
