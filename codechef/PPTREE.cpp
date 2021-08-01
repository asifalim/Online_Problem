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
vector<pair<int,int>>adj[mxn];
int ar[mxn];
struct node
{
    node* child[2];
    node()
    {
        child[0]=child[1]=0;
    }
};
node* root=new node();
void insert(int n)
{
    node* temp=root;
    for(int i=30; i>=0; i--)
    {
        int bit=(n>>i)&1;
        if(temp->child[bit]==NULL)temp->child[bit]=new node();
        temp=temp->child[bit];
    }
}
void dfs(int n,int par=-1)
{
    for(pair<int,int>edge:adj[n])
    {
        if(edge.first==par)continue;
        ar[edge.first]=ar[n]^edge.second;
        dfs(edge.first,n);
    }
}
int search(int n)
{
    int mx=0;
    node* temp=root;
    for(int i=30; i>=0; i--)
    {
        int bit=(n>>i)&1;
        if(temp->child[!bit])mx+=1<<i,temp=temp->child[!bit];
        else temp=temp->child[bit];
    }
    return mx;
}
signed main()
{
    //fast;
    w(t)
    {
        int n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=INT_MAX;
        string s,ss,sr,sss;
        cin>>n;memset(ar,0,sizeof(ar));
        memset(adj,0,sizeof(adj));root=new node();
        for(i=0; i<n-1; i++)cin>>a>>b>>c,adj[a].push_back({b,c}),adj[b].push_back({a,c}),mx=max(c,mx);
        dfs(1);
        for(i=1; i<=n; i++)insert(ar[i]);
        for(i=1; i<=n; i++)mx=max(mx,search(ar[i]));
        cout<<mx<<endl;
    }
    return 0;
}
