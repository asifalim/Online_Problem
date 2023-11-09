#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define dbg(a,b,c,d) cerr<<a<<"  "<<b<<"  "<<c<<"  "<<d<<endl;
#define kill(a) {cout<<a<<endl;continue;}
#define KILL(a) {cout<<a<<endl;return 0;}
#define debug cerr<<"Error Found"<<endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define lcm(a, b) (a/__gcd(a,b))*b
#define w(t) cin>>t;while(t--)
#define pi  2 * acos(0.0)
#define ll long long int
#define endl "\n"
#define INF (1LL<<61)
int t, cs = 0;
const int mxn = 1e3 + 4, mod = 2e9 + 7;
int dp[mxn][mxn];
int n, k;
array<int,2>table[mxn];
array<int,3>ar[mxn];
int par[mxn];
int rec(int i, int j)
{
    if(j == k + 1)return 0;
    if(i == n + 1)return 0;
    if(~dp[i][j])return dp[i][j];
    int ans = 0;
    ans = max(ans, max(rec(i, j + 1), rec(i + 1, j)));
    if(ar[i][0] <= table[j][0])ans = max(ans, ar[i][1] + rec(i + 1, j + 1));
    return dp[i][j] = ans;
}
vector<pair<int,int>>ans;
void trace(int i, int j)
{
   if(i == n + 1 or j == k + 1)return;
   if(ar[i][0] <= table[j][0] and dp[i][j] == rec(i + 1, j + 1) + ar[i][1])ans.push_back({ar[i][0], ar[i][2]}), trace(i + 1, j + 1);
   else if(dp[i][j] == rec(i + 1, j))trace(i + 1, j);
   else trace(i, j + 1);
}
int32_t main()
{
    fast;
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> ar[i][0] >> ar[i][1], ar[i][2] = i;
    sort(ar + 1, ar + n + 1);
    cin >> k;
    for(int i = 1; i <= k; i++)cin >> table[i][0], table[i][1] = i;
    sort(table + 1, table + k + 1);
    mem(dp, -1);
    int total_money = rec(1, 1);
    trace(1, 1);
    sort(ans.rbegin(), ans.rend());
    cout << ans.size() <<" "<< total_money << endl;
    for(int i = 0, j = k; i < ans.size(); i++, j--)cout << ans[i].second << " " << table[j][1] << endl;

}
