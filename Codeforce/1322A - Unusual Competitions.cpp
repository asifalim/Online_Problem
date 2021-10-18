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
const int mxn=2e5+10,mod=1e9+7;

signed main()
{
    //fast;
   // w(t)
    //{
        int n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=-1e9,mn=1e9;
        string s,ss,sr,sa;
        bool f=false,ff=true;
        cin>>n>>s;int order[n],cost=0;
        order[0]=0;
        for(i=1;i<=n;i++)if(s[i-1]=='(')order[i]=order[i-1]+1;else order[i]=order[i-1]-1; //encountered opening & closing brakets
        for(i=1;i<=n;i++)
        {
            if(order[i]==-1 and order[i-1]==0)cn=i;       //transition of 0 to -1 means we have encountered an unbalanced closing bracket
            else if(order[i]==0 and order[i-1]==-1)cost+=i-cn+1;     //transition from -1 to 0 means we have encountered the end of a substring where all the unbalanced closing brackets  before it will be balanced
        }                                                            //And we compute the length of the substring and add it to the cost
        cout<<(order[n]!=0?-1:cost)<<endl;
   // }
}
