#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mxN=1e6;
ll freq[mxN+2],mul[mxN+2];
ll nc3(ll n)
{   //for counting pair use n*(n-1)/2;
    if(n<3)return 0;return (n*(n-1)*(n-2))/6;
}
int main()
{
    ll n,m,i,j;
    cin>>n;
    for(i=0;i<n;i++)cin>>m,freq[m]++;
    for(i=1;i<=mxN;i++)
    {
        for(j=i;j<=mxN;j+=i)mul[i]+=freq[j];
        mul[i]=nc3(mul[i]);
    }
    for(i=mxN;i>=1;i--)
    for(j=2*i;j<=mxN;j+=i)mul[i]-=mul[j];
    cout<<mul[1]<<endl;
    return 0;
}

