#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s,s1;
        cin>>s;
        sort(s.begin(),s.end());
        int n=s.length();
        int j,f;
        cout<<"{ ";
        while(next_permutation(s.begin(),s.end()))
        {

            s1=s;
            j=n-1,f=0;
            for(int i=0; i<n; i++)
            {
                if(s1[j--]!=s[i])
                {
                    f=1;
                    break;
                }
            }
            s1.clear();
            if(f==0)
                cout<<s<<" ";
        }
        cout<<"}"<<endl;
    }
    return 0;
}
