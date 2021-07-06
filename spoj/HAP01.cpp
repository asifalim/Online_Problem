#include<bits/stdc++.h>
using namespace std;  //problem-> https://www.spoj.com/problems/HAP01/
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define endl "\n"
int ar(ll x)
{
    int cn=0;
    for(int i=0; i<64; i++)
    if(i&1 and x>>i&1)cn++;   //(x>>i&1) means-> (x/2^i)&1 setbit_position like: 100101-> 1,3,6
    return cn;
}
int br(ll x)
{
    int cn=0;
    for(int i=0; i<64; i++)
    if(!(i&1) and x>>i&1)cn++;
    return cn;
}
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        ll n,a,b,m,i,j,cn=0,sm=0,k;
        string s;
        cin>>n>>m>>k;
        for(i=n; i<=m; i++)
        if(abs(ar(i)-br(i))==k)sm++;
        cout<<sm<<endl;
    }
    return 0;
}
