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
const int mxn=2e5+4,mod=1e9+7;

signed main()
{

    //fast;
    // w(t)
    // {
    int n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=-1e9,mn=1e9;
    string s,ss,sr,sa;
    bool f=true;
    cin>>n>>m;
    int ar[m+1]= {0};
    ar[m]=0;
    auto run=[](int m,int ar[])
    {
        stack<int>st;
        int area=0;
        for(int i=0; i<=m; i++)
        {
            while(!st.empty() and ar[i]<ar[st.top()])
            {
                int height=ar[st.top()];
                st.pop();
                int width=i-(st.empty()?-1:st.top())-1;
                area=max(area,height*width);
            }
            st.push(i);
        }
        return area;
    };
    char ch;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cin>>ch;
            if(ch=='.')ar[j]++;
            else ar[j]=0;
        }
        mx=max(mx,run(m,ar));
    }
    cout<<mx<<endl;
    // }
}
