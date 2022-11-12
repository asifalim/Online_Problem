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
const int mxn=1e5+2,mod=1e9+7;
int dp[101][mxn],ar[101];
set<int>st;
int run(int i,int sum)
{
    if(sum)st.insert(sum);
    if(i<0)return sum;
    if(~dp[i][sum])return dp[i][sum];
    int not_taken=run(i-1,sum),taken;
    if(ar[i]<=sum)run(i-1,sum-ar[i]);
    return dp[i][sum]=not_taken;
}

/*
int sm=0;dp[0]=true;
    for(int i=0;i<n;i++)
    {
      sm+=ar[i];
      for(int j=sm;j>=ar[i];j--)dp[j]=(dp[j-ar[i]]?1:dp[j]);
    }
    for(int i=1;i<=sm;i++)if(dp[i])ans.push_back(i);
*/
signed main()
{
    //fast;
    //w(t)
    // {
         int n;
         cin>>n;int sm=0;mem(dp,-1);
         for(int i=0;i<n;i++)cin>>ar[i],sm+=ar[i];
         run(n-1,sm);
         cout<<(int)st.size()<<endl;
         for(auto i:st)cout<<i<<" ";cout<<endl;
    //}
}
