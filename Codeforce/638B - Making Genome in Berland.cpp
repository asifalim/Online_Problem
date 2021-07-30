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
const int mxn=1e6+3,mod=1e9+7;
int mark['z'+1];
signed main()
{
    //fast;
    //w(t)
    //{
    int n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=INT_MAX;
    string s,ss,sr;
    cin>>n;mem(mark,-1);
    set<char>st;
    for(i=0; i<n; i++)
    {
        cin>>s;
        st.emplace(s[0]);
        for(j=0; j<s.size()-1; j++)mark[s[j]]=s[j+1];
    }
    for(int i='a'; i<='z'; i++)if(~mark[i] and st.count(char(mark[i])))st.erase(char(mark[i]));
    for(auto i:st)
    {
        char ch=i;
        while(~ch)cout<<ch,ch=mark[ch];
    }
    cout<<endl;
    //}
    return 0;
}
