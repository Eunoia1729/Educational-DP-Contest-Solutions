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
#define eb emplace_back
#define pg priority_queue<ll, vector<ll>, greater<ll>>
#define sz(a) a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define cset(a) __builtin_popcountll(a)
#define FILL(a, b, T) fill_n((T *)a, sizeof(a) / sizeof(T), b)
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
// #define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define pis pair<ll,pll>
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
const auto start_time = std::chrono::high_resolution_clock::now();
void timecalculater(){
    #ifndef ONLINE_JUDGE
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end_time-start_time;
    cerr<<"Time Taken : "<<diff.count()<<" s\n";
    #endif
}
template <typename A, typename B>
string to_string(pair<A, B> p);
 
string to_string(const string& s) {
        return '"' + s + '"';
}
 
string to_string(const char* s) {
        return to_string((string) s);
}
 
string to_string(bool b) {
        return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
        bool first = true;
        string res = "{";
        for (int i = 0; i < static_cast<int>(v.size()); i++) {
                if (!first) {
                        res += ", ";
                }
                first = false;
                res += to_string(v[i]); 
        }
        res += "}";
        return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
        string res = "";
        for (size_t i = 0; i < N; i++) {
                res += static_cast<char>('0' + v[i]);
        }
        return res;
}
 
template <typename A>
string to_string(A v) {
        bool first = true;
        string res = "{";
        for (const auto &x : v) {
                if (!first) {
                        res += ", ";
                }
                first = false;
                res += to_string(x);
        }
        res += "}";
        return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
        return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
void debug_out() { 
        cerr << endl; 
}
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
        cerr << " " << to_string(H);
        debug_out(T...);
}
 
#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif
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
// FOR VIEWERS, CODE STARTS HERE
ll N = 2e5 + 5;
ll n;
vll dp(N);
vll seg(2*N, 0);
void update(ll x, ll val) {
    x += (n + 1);
    seg[x] = val;    
    while( x > 1){
        x >>= 1;
        seg[x] = max(seg[2*x], seg[2*x + 1]);
    }
}
ll query(ll l, ll r) {
    ll ans = 0;
    l += (n + 1);
    r += (n + 1);
    while( l < r) {
        if( (l&1)) {
            ans = max(ans, seg[l]);
            l ++;
        }
        if( (r&1)) {
            r--;
            ans = max(ans, seg[r]);
        }
        l >>= 1;
        r >>= 1;
    }
    return ans;
}
ll lis(vll &h, vll &a) {
    ll i, prev, res = 0;
    rep(i,0,n) {
        prev = query(0 , h[i]);
        update(h[i], a[i] + prev);
        res = max(res, a[i] + prev);
    }   
    return res;
}   
int main()
{
    // get the logic, then code !
    // if code is long, dry run on samples
    // think in a generalised waya
    FIO;
    ll m, t, q, maxx,  i, j, k1, k2, k3, k, x, y, flag, sum, cnt, ans, minn, cur;
    cin >> n;
    vll h(n), a(n);
    rep(i,0,n) {
        cin >> h[i];
    }
    rep(i,0,n) {
        cin >> a[i];
    }
    ans = lis(h, a);
    cout << ans << endl;
    return 0;    
}