#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
