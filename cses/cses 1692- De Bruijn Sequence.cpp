//https://cses.fi/problemset/task/1692/
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
const int mxn=2e5+3,mod=1e9+7;
map<string,int>mp1;
map<int,string>mp2;
void rec(string s)
{
    if(s.size()==N-1)
    {
        mp1[s]=++kk;
        mp2[kk]=s;
        return;
    }
    rec(s+'0');
    rec(s+'1');
}
signed main()
{
    //fast;
    //w(t)
    //{
    int n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=1e9+1;
    string s,ss,sr;
    bool f=false,ff=false;
    cin>>N;
    if(N==1)return cout<<"01"<<endl,0;
    rec("");
    n=1<<(N-1);
    vector<pair<int,char>>adj[n+1];
    stack<pair<int,char>>st;
    for(i=1; i<=n; i++)
    {
        s=mp2[i].substr(1,N-2);
        adj[i].push_back({mp1[s+"0"],'0'});
        adj[i].push_back({mp1[s+"1"],'1'});
    }
    st.push({1,'#'});
    while(st.size())
    {
        auto [i,c]=st.top();
        if(!adj[i].size())
        {
            if(c!='#')ss+=c;
            st.pop();
        }
        else
        {
            auto [j,c]=adj[i].back();
            adj[i].pop_back();
            st.push({j,c});
        }
    }
    ss+=mp2[1];
    cout<<ss<<endl;
    //}
    return 0;
}
