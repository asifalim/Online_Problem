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
#define case(k) cout<<"Case "<<++kk<<": ";
int t,kk=0,ans=0,tot=0,k;
const int mxN=1e3+3,mod=1e9+7;
vector<pair<int,int>>v;
char ch[mxN][mxN];
int dp[mxN][mxN],dp1[mxN][mxN],N,M,X,Y,dx[]= {-1,1,0,0},dy[]= {0,0,-1,1};
bool check(int i,int j)
{
    return (~i and ~j and i<N and j<M and dp[i][j]<0 and (ch[i][j]=='.' or ch[i][j]=='A'));
}
bool chk(int i,int j)
{
    return (~i and ~j and i<N and j<M and dp1[i][j]<0 and ch[i][j]=='.');
}
bool ck(int i,int j,int cn)
{
    return (~i and ~j and i<N and j<M and dp1[i][j]==cn-1);
}
void bfs1()
{
    queue<pair<int,int>>q;mem(dp,-1);
    for(auto i:v)q.push({i.first,i.second}),dp[i.first][i.second]=0;
    while(!q.empty())
    {
        int x=q.front().first,y=q.front().second;
        q.pop();
        for(int i=0; i<4; i++)
        {
           int X=x+dx[i],Y=y+dy[i];
            if(check(X,Y))dp[X][Y]=dp[x][y]+1,q.push({X,Y});
        }
    }
    /*for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)cout<<dp[i][j]<<" ";cout<<endl;
    }*/
}
void bfs2(int n,int m)
{
    queue<pair<int,int>>q;
    q.push({n,m});bool f=false;int x,y;
    mem(dp1,-1);
    dp1[n][m]=0;
    while(!q.empty())
    {
        x=q.front().first,y=q.front().second;
        q.pop();
        for(int i=0; i<4; i++)
        {
           int X=x+dx[i],Y=y+dy[i];
            if(X<0 or Y<0 or X>=N or Y>=M){f=true;break;}
            if(!chk(X,Y))continue;
            dp1[X][Y]=dp1[x][y]+1;
            if(dp1[X][Y]<dp[X][Y] or dp[x][y]<0)q.push({X,Y});
        }
        if(f)break;
    }
    /*for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)cout<<dp1[i][j]<<" ";cout<<endl;
    }*/
   if(!f){cout<<"NO"<<endl;return;}
   cout<<"YES"<<endl<<dp1[x][y]<<endl;int cn=dp1[x][y];string s;
   while(cn)
   {
       if(ck(x-1,y,cn))x--,s+='D';
       if(ck(x+1,y,cn))x++,s+='U';
       if(ck(x,y-1,cn))y--,s+='R';
       if(ck(x,y+1,cn))y++,s+='L';
       cn--;
   }
   reverse(s.begin(),s.end());
   cout<<s<<endl;
}
signed main()
{
    //fast;
    //w(t)
    //{
        int n,m,a,b,c,d,e,i,j=0,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=INT_MAX,mx1;
        string s,ss,sr;
        bool f=true,ff=false;
        cin>>N>>M;
        for(i=0; i<N; i++)
        {
            for(j=0; j<M; j++)
            {
                cin>>ch[i][j];
                if(ch[i][j]=='A')cn=i,cn1=j;
                if(ch[i][j]=='M')v.push_back({i,j});
            }
        }
        bfs1();
        bfs2(cn,cn1);
    //}
    return 0;
}
