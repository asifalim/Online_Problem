#include<bits/stdc++.h>
using namespace std;  //Problem-> https://www.spoj.com/problems/ADAFIELD/
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,i,q;
        cin>>n>>m>>q;
        set<int>xc,yc;
        multiset<ll>xd,yd;
        xc.emplace(0);
        xc.emplace(n);
        yc.emplace(0);
        yc.emplace(m);
        xd.emplace(n);
        yd.emplace(m);
        while(q--)
        {
            ll a,x;
            cin>>a>>x;
            if(!a)
            {
                if(xc.find(x)==xc.end())
                {
                    xc.emplace(x);
                   auto it1=xc.lower_bound(x);
                   auto it2=it1;it2++;it1--;
                   xd.erase(xd.find(*it2-*it1));
                   xd.emplace(x-*it1);
                   xd.emplace(*it2-x);
                }
            }
            else
            {
               if(yc.find(x)==yc.end())
                {
                    yc.emplace(x);
                    auto it1=yc.lower_bound(x);
                    auto it2=it1;it2++;it1--;
                    yd.erase(yd.find(*it2-*it1));
                    yd.emplace(x-*it1);
                    yd.emplace(*it2-x);
                }
            }
             cout<<((*xd.rbegin())*(*yd.rbegin()))<<"\n";
        }
    }
    return 0;
}
