
#include<bits/stdc++.h>
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
bool cmp(string s,string z)
{
    return s.size()<z.size();
}
int main()
{
    //Follow Excellence, Success will chase you
    int t,n,i,j;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string s,ss;
        getline(cin,s);
        vector<string>v;
        stringstream in(s);    //count string
        while(in>>s)
            v.emplace_back(s);                                 //difference between stable_sort and sort
        stable_sort(v.begin(),v.end(),cmp);//For stable_sort: ordering of equivalent elements are guaranteed to keep there same order
        for(auto i:v)cout<<" "<<i;        //For sort: ordering of equivalent elements are not guaranteed to keep there same order
        cout<<endl;
    }
    return 0;
}
