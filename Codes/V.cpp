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
// #define mod 1000000007
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
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
// unordered_map<long long, int, custom_hash> safe_map;

vll e[100005];
vll c[100005];
ll a[100005];
ll n, mod; 
ll dfs1(ll u, ll par)
{ 
  ll ans = 1, i;
  i = 0;
  for(auto p: e[u])
  {
    if( p != par)
    {
      c[u][i] = dfs1(p,u);
      ans*=c[u][i];
      ans%=mod;
    }
    i++;
  }
  ans+=1;
  ans%=mod;
  return ans;
}
ll dfs2(ll u, ll par, ll pre)
{ 
  ll ans = 1, i;
  i = 0;
  for(auto p: e[u])
  {
    if( p == par)
    {
      c[u][i] = pre;
    }
    ans*=c[u][i];
    ans%=mod; 
    i++;
  }
  a[u] = ans;
  ll L[sz(e[u]) + 1], R[sz(e[u]) + 1];
  L[0] = 1;
  R[sz(e[u])] = 1;
  // prefix. for before i use L[i]
  rep(i,1,sz(e[u]))
  {
    L[i] = (L[i-1]*c[u][i-1])%mod;
  }
  // suffix. for after i use R[i+1]
  rep2(i,sz(e[u]) - 1, 0)
  {
    R[i] = (R[i+1]*c[u][i])%mod;
  }
  ll p;
  rep(i,0,sz(e[u]))
  {
    p = e[u][i]; 
    if( p != par)
    {
      dfs2(p, u, ( (L[i]*R[i+1])%mod + 1)%mod );
    }
  }
}
int main()
{
    
    FIO;
    ll t, q, prev, maxx, m, i, j, k1, k2, k3, k, x, y, flag, sum, cnt, ans;
    cin>>n>>mod;
    rep(i,0,n-1)
    {
      cin>>x>>y;
      e[x].pb(y);
      e[y].pb(x);
      c[x].pb(0);
      c[y].pb(0);
    }
    dfs1(1,-1);
    dfs2(1,-1,1);
    rep(i,0,n)
    {
      cout<<a[i+1]<<endl;
    }
    return 0;    
}
