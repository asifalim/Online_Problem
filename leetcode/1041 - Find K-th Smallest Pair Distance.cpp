#include<bits/stdc++.h>
using namespace std;       //Problem->https://leetcode.com/explore/learn/card/binary-search/146/more-practices-ii/1041/
#define ll long long int  //O(nlogd+nlogn)
int smallestDistancePair(vector<int>&a,int k)
{
    sort(a.begin(),a.end());
    int low=0,high=a[a.size()-1]-a[0];  //Because every pair distance must be lies between low to high
    while(low<high)
    {
        int mid=low+(high-low)/2;
        int cnt=0;
        for(int i=0,j=0; i<a.size(); i++)
        {
            while(j<a.size() and a[j]<=a[i]+mid)j++;
            cnt+=j-i-1;       //cnt implies how many pair distance less or equal to mid(absolute difference);
        }
        if(cnt<k)low=mid+1;
        else high=mid;
    }
    return low;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,i,a,k;
        cin>>n>>k;
        vector<int>v;
        for(i=0;i<n;i++)cin>>a,v.push_back(a);
        cout<<smallestDistancePair(v,k)<<endl;
    }
    return 0;
}
