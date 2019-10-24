//  .:::.   .:::.
// :::::::.:::::::
// :::::::::::::::
// ':::::::::::::'
//   ':::::::::'
//     ':::::'
//       ':'
#include <bits/stdc++.h>
#define rep(i,a,b) for (i=a;i<b;i++)
#define rep2(i,a,b) for (i=a;i>=b;i--)
#define mod 1000000007
#define mod2 998244353
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define INF  1e9+5
#define f first
#define s second
#define endl '\n'
#define ll long long
#define ii pair <int,int>
#define pll pair <ll,ll>
#define vi vector <int>
#define vl vector <ll>
#define vvi vector < vi >
#define vii vector < ii >
#define vpl vector < pll >
#define vvii vector < vii >
#define vll vector < ll >
#define vb  vector <bool>
#define pb push_back
#define mk make_pair
#define pg priority_queue<ll, vector<ll>, greater<ll>>
#define pq priority_queue<ll>
#define sz(a) a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define cset(a) __builtin_popcountll(a)
#define FILL(a, b, T) fill_n((T *)a, sizeof(a) / sizeof(T), b)
using namespace std;
ll n, m;
unordered_map<ll,vll> e;
vll indeg(100001);
vll outdeg(100001);
vll maxpath(100001);
vll vis(100001);
void dfs(ll x)
{
	vis[x] = 1;
    for(auto p1: e[x])
    {
        indeg[p1]--;
        maxpath[p1] = max(maxpath[p1],maxpath[x] + 1);
        if( indeg[p1] == 0)
        {
            dfs(p1);
        }
    }
}
int main()
{
    FIO;
    ll t, q, maxx, k, i, j, k1, k2, k3, x, flag, ans, sum, cnt, prev, y;
    cin>>n>>m;
    rep(i,0,m)
    {
        cin>>x>>y;
        e[x].pb(y);
        indeg[y]++;
        outdeg[x]++;
    }
    ans = 0;
    rep(i,1,n+1)
    {
        if( indeg[i] == 0 and vis[i] == 0)
        {
            dfs(i);
        }
    }
    rep(i,1,n+1)
    {
        ans = max(ans, maxpath[i]);
    }
    cout<<ans<<endl;
    return 0;    
}
/*
axyb
abyxb
*/