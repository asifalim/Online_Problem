#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define dbg(a,b,c) cerr<<a<<"  "<<b<<"  "<<c<<endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define endl "\n"
#define INF 1e18
#define w(t) cin>>t;while(t--)
#define kill(a) {cout<<a<<endl;continue;}
#define pi  2 * acos(0.0)
int t,ans=0,tot=0,kk=0;
const int mxn=1e6+27,mod=1e9+7;

signed main()
{

    //fast;
    // w(t)
    //{
    int n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=-1e9,mn=1e9;
    string s,ss,sr,sa,sss;
    bool f=false,ff=false;
    cin>>n;
    int ar[]= {4,8,15,16,23,42};
    set<int>st[50];
    for(i=0; i<n; i++)cin>>a,st[a].insert(i);
    while(true)
    {
        int last=-1;
        for(i=0; i<6; i++)
        {
            a=ar[i];
            auto it=st[a].upper_bound(last);
            if(it==st[a].end())break;          //if subsequence isn't correct order
            last=*it;                          //try to catch leftmost seq. num to get many subsequence
            st[a].erase(it);
        }
        if(i!=6)break;
        cn++;
    }
    cout<<n-cn*6<<endl;

            //*---->DP Process----->*//

    /*for (int i = 0; i < n; i++)
    {
        if (a[i] == 4) dp[0]++;
        else if (a[i] == 8) dp[1] = min(dp[0],dp[1]+1);
        else if (a[i] == 15) dp[2] = min(dp[1],dp[2]+1);
        else if (a[i] == 16) dp[3] = min(dp[2],dp[3]+1);
        else if (a[i] == 23) dp[4] = min(dp[3],dp[4]+1);
        else dp[5] = min(dp[4],dp[5]+1);
    }
    cout<<n-dp[5]*6<<endl;*/
    //}
}
