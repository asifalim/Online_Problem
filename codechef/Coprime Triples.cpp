//link-->https://www.codechef.com/problems/COPRIME3
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
ll freq[mxn+2],mul[mxn+2];
ll nc3(ll n)
{
    //for counting pair use n*(n-1)/2;
    if(n<3)return 0;
    return (n*(n-1)*(n-2))/6;
}
int main()
{
    ll n,m,i,j;
    cin>>n;
    for(i=0; i<n; i++)cin>>m,freq[m]++;
    for(i=1; i<=mxn; i++)
    {
        for(j=i; j<=mxn; j+=i)mul[i]+=freq[j];
        mul[i]=nc3(mul[i]);
    }
    for(i=mxn; i>=1; i--)
    for(j=2*i; j<=mxn; j+=i)mul[i]-=mul[j];
    cout<<mul[1]<<endl;
    return 0;
}
