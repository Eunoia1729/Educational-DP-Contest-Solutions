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
const ll k_lim = 1e4; 
ll k;
string ss;
ll dp[100001];
int main()
{
    FIO;
    ll t, q, maxx, n, i, j, k1, k2, k3, x, flag, ans, sum, cnt, prev;
    cin>>n;
    vll v(n);
    
    rep(i,0,n)
    {
        cin>>v[i];    
    }
    FILL(dp, INF, ll);
    dp[0] = 0;
    rep(i,0,n)
    {
        rep(j,1,3)
        {
            if( i - j >= 0)
                dp[i] = min(dp[i],dp[i-j] + abs(v[i] - v[i-j]) );
        }
    }
    cout<<dp[n-1]<<endl;
    return 0;    
}
