#include<bits/stdc++.h>      //O(log(min(n,m)))
using namespace std;        //Reference-> https://www.youtube.com/watch?v=LPFhl65R7ww&t=1051s
#define ll long long int   //Problem-> https://leetcode.com/explore/learn/card/binary-search/146/more-practices-ii/1040/
double findmedian(vector<int>&ar,vector<int>&arr)
{
    int n=ar.size(),m=arr.size();
    if(n>m)return findmedian(arr,ar);
    int low=0,high=n;
    while(low<=high)
    {
        int partitionx=low+(high-low)/2;
        int partitiony=(n+m+1)/2-partitionx;
        int maxleftx=(partitionx==0?INT_MIN:ar[partitionx-1]);
        int minrightx=(partitionx==n?INT_MAX:ar[partitionx]);
        int maxlefty=(partitiony==0?INT_MIN:arr[partitiony-1]);
        int minrighty=(partitiony==m?INT_MAX:arr[partitiony]);
        if(maxleftx<=minrighty and maxlefty<=minrightx)
        {
            if((n+m)&1)return max(maxleftx,maxlefty);
            else return (max(maxleftx,maxlefty)+min(minrightx,minrighty))/2.0;
            break;
        }
        else if(maxleftx>minrighty)high=partitionx-1;
        else low=partitionx+1;
    }
    return -1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,i,a;
        cin>>n>>m;
        vector<int>v,vv;
        for(i=0; i<n; i++)cin>>a,v.push_back(a);
        for(i=0; i<m; i++)cin>>a,vv.push_back(a);
        cout<<findmedian(v,vv)<<endl;
    }
    return 0;
}
