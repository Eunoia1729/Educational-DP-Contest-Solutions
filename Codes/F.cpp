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
    ll t, q, maxx, n, m, k, i, j, k1, k2, k3, x, flag, ans, sum, cnt, prev;
    string ss1, ss2;
    cin>>ss1>>ss2;
    n = sz(ss1);
    m = sz(ss2);
    ll dp[n+1][m+1];
    // char prev[n+1][m+1];
    memset(dp,0,sizeof(dp));
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            if( ss1[i] == ss2[j])
            {
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + 1);
            }
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
        }

    }
    maxx = 0;
    k1 = k2 = 0;
    rep(i,0,n+1)
    {
        rep(j,0,m+1)
        {
            if( dp[i][j] > maxx)
            {
                k1 = i;
                k2 = j;
                maxx = dp[i][j];
            }
        }
    }
    vector<char> v;
    i = k1;
    j = k2;
    // if( i != -1)
    // {
    //     flag = 1;
    // }
    while( i != 0 or j!= 0 and flag)
    {
        if( dp[i-1][j-1] + 1 == dp[i][j] and (ss1[i-1] == ss2[j-1]))
        {
            v.pb(ss1[i-1]);
            i--;
            j--;
        }
        else if( dp[i-1][j] == dp[i][j])
        {
            i--;
        }
        else if( dp[i][j-1] == dp[i][j])
        {
            j--;
        }
        else
        {
            break;
        }
    }
    // cout<<dp[n][m]<<endl;
    reverse(all(v));
    for(i = 0; i < sz(v);++i)
    {
        cout<<v[i];
    }
    if( sz(v) == 0)
    {
        cout<<"";
    }
    cout<<endl;

    return 0;    
}
/*
axyb
abyxb
*/