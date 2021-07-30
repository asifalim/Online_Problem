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
const int mxN=1e5+3,mod=1e9+7;
map<string,string>mp;
vector<string>v;
int rec(string s,int idx)
{
    if(!idx)
    {
        string temp=s,temp1;
        while(true)
        {
            temp1=temp;
            temp1=temp1.substr(0,2);
            if(mp.find(temp1)!=mp.end())
            {
                if(temp.size()==2)
                {
                    if(mp[temp]=="a")return 1;
                    else return 0;
                }
                temp=mp[temp1]+temp.substr(2);
            }
            else return 0;
        }
    }
    return rec(s+'a',idx-1)+rec(s+'b',idx-1)+rec(s+'c',idx-1)+rec(s+'d',idx-1)+rec(s+'e',idx-1)+rec(s+'f',idx-1);
}
signed main()
{
    //fast;
    //w(t)
    //{
    int n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=INT_MAX;
    string s,ss,sr;
    cin>>n>>m;
    for(i=0; i<m; i++)cin>>s>>ss,mp[s]=ss;
    cout<<rec("",n)<<endl;
    //}
    return 0;
}
