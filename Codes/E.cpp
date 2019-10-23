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
ll a[100001][3], dp[100001][3];
int main()
{
    FIO;
    ll t, q, maxx, n, k, i, j, k1, k2, k3, x, flag, ans, sum, cnt, prev;
    cin>>n>>k;
    vll v(n), w(n);
    rep(i,0,n)
    {
        cin>>w[i]>>v[i];
    }
    k1 = 0;
    rep(i,0,n)
    {
        k1+=v[i];
    }
    ll dp[k1+1];
    FILL(dp,INF*n,ll);
    dp[0] = 0;
    rep(i,0,n)
    {
        rep2(j,k1,v[i])
        {
            dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
            // dp[j] = max(dp[j], dp[j-1]);
        }
    }
    // cout<<k1<<endl;
    // rep(i,0,k1+1)
    // {
    //     cout<<dp[i]<<" ";
    // }
    // cout<<k1<<endl;
    rep(i,0,k1+1)
    {
        if( dp[i] <= k)
        {
            ans = i;
            // cout<<i<<" "; 
        }
    }
    // cout<<dp[90]<<endl;
    cout<<ans<<endl;
    return 0;    
}
