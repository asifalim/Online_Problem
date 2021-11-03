#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define dbg(a,b,c) cout<<a<<"  "<<b<<"  "<<c<<endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define endl "\n"
#define INF 1e16
#define w(t) cin>>t;while(t--)
#define kill(a) {cout<<a<<endl;continue;}
#define pi  2 * acos(0.0)
int t,ans=0,tot=0,kk=0,N;
const int mxn=5e3+3,mod=1e9+7;
int path[mxn],cnt[mxn];
signed main()
{
    //fast;
    //w(t)
    //{
        int n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=1e9;
        string s,ss,sr;vector<int>v;
        cin>>n>>a>>b;cnt[0]=1;path[0]=-1;
        pair<pair<int,int>,int>ar[n+1];
        path[1]=-1;
        for(i=1;i<=n;i++)
        {
            cin>>c>>d;cnt[i]=1;
            if(c<=a or d<=b)continue;
            ar[cn++]={{c,d},i};
        }
        sort(ar,ar+cn);
        if(cn==1)return cout<<1<<endl<<ar[0].second<<endl,0;
        mx=0;int last=0;
        for(i=1;i<cn;i++)
        {
            for(j=0;j<i;j++)
            {
                if(ar[i].first.first>ar[j].first.first and ar[i].first.second>ar[j].first.second and cnt[j]+1>cnt[i])
                {
                    cnt[i]=cnt[j]+1;
                    path[ar[i].second]=ar[j].second;
                    //dbg(ar[i].second,cnt[i],last);
                }
            }
            if(cnt[i]>mx)mx=cnt[i],last=ar[i].second;
        }
        cout<<mx<<endl;
        while(last>0)v.push_back(last),last=path[last];
        reverse(v.begin(),v.end());
        for(auto i:v)cout<<i<<" ";cout<<endl;
    //}
    return 0;
}
