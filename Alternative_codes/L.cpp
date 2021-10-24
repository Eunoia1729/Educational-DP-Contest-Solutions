#include <iostream>
#include <set> 
#include <iterator>
#include <bitset> 
#include <bits/stdc++.h> 
using namespace std;
typedef  long long int ll;
ll mod=1000000007;
int n;
ll a[3005];
ll dp[3005][3005];
ll f(int l,int r)
{
    if(l>r || l>n ||r<=0)
        return 0;
    if(dp[l][r]!=-1)
        return dp[l][r];
    return dp[l][r]=max(a[l]+min(f(l+2,r),f(l+1,r-1)),a[r]+min(f(l+1,r-1),f(l,r-2)));
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        cin>>n;
        ll sum=0;
        for(int i=1;i<=n;i++)
        {    cin>>a[i];
            sum+=a[i];
        }
        memset(dp,-1,sizeof(dp));
       // cout<<f(1,n)<<endl;
       f(1,n);
        cout<<dp[1][n]-(sum-dp[1][n]);







    }
    return 0;
}
