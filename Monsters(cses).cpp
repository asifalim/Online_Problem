#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int dr[]= {0,1,0,-1};
int dy[]= {1,0,-1,0};
bool check(int i,int j,int n,int m)
{
    if(i>=0 and i<n and j>=0 and j<m)return true;
    return false;
}
int main()
{
    int n,m,i,j;
    cin>>n>>m;
    string str,s;
    bool found=false;
    vector<pair<int,int>>mon;
    queue<pair<pair<int,int>,bool>>q;
    pair<int,int>x,foundpos,prev={-1,-1};
    vector<vector<bool>>issafe(n,vector<bool>(m));
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    vector<vector<pair<int,int>>>lst(n,vector<pair<int,int>>(m,make_pair(-1,-1)));
    for(i=0; i<n; i++)
    {
        cin>>str;
        for(j=0; j<m; j++)
        {
            issafe[i][j]=(str[j]!='#');
            if(str[j]=='M')mon.push_back({i,j}),issafe[i][j]=false;
            else if(str[j]=='A')x= {i,j};
        }
    }
    for(auto &i:mon)q.push({i,false});
    q.push({x,true});
    while(!q.empty())
    {
        int sz=q.size();
        while(sz--)
        {
            auto u=q.front();
            q.pop();
            if(u.second)
            {
                if(!issafe[u.first.first][u.first.second])continue;
                vis[u.first.first][u.first.second]=true;
                if(u.first.first==0 or u.first.first==n-1 or u.first.second==0 or u.first.second==m-1)
                {
                    foundpos= {u.first.first,u.first.second};
                    found=true;
                    break;
                }
            }
            else issafe[u.first.first][u.first.second]=false;
            for(i=0; i<4; i++)
            {
                int X=u.first.first+dr[i],Y=u.first.second+dy[i];
                if(check(X,Y,n,m) and issafe[X][Y])
                {
                    if(!u.second or (u.second and !vis[X][Y]))
                    {
                        q.push({{X,Y},u.second});
                        if(u.second)
                            lst[X][Y]= {u.first.first,u.first.second};
                    }
                }
            }

        }
        if(found)break;
    }
    if(!found)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(i=foundpos.first,j=foundpos.second; i!=-1 or j!=-1; tie(i,j)=lst[i][j])
    {
        if(prev.first==-1 and prev.second==-1)
        {
            prev= {i,j};
            continue;
        }
        if(i==prev.first and j+1==prev.second)     s+='R';
        else if(i==prev.first and j-1==prev.second)s+='L';
        else if(i+1==prev.first and j==prev.second)s+='D';
        else if(i-1==prev.first and j==prev.second)s+='U';
        prev= {i,j};
    }
    reverse(s.begin(),s.end());
    cout<<s.size()<<endl<<s<<endl;
    return 0;
}
