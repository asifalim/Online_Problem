//link-->https://lightoj.com/problem/making-huge-palindromes
#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> prefix_function (string Z)
{
    ll n = (ll) Z.length();
    vector<ll> F(n);
    F[0]=0;
    for (ll i=1; i<n; ++i)
    {
        ll j = F[i-1];
        while (j > 0 && Z[i] != Z[j])
            j = F[j-1];
        if (Z[i] == Z[j])  ++j;
        F[i] = j;
    }
    return F;
}
string s;
int main()
{
    ll t,n,i,j,k=1;
    cin>>t;
    while(t--)
    {
        string ss="",sss="";
        cin>>s;
        n=s.size()*2;
        ss=s;
        reverse(ss.begin(),ss.end());
        ll cn=0;
        sss+=(ss+"$"+s);
        ll mx=0;
        vector<ll>v;
        v=prefix_function(sss);
        mx=v[v.size()-1];
        ll p=n-mx;
        cout<<"Case "<<k++<<": "<<p<<endl;
    }
    return 0;
}
