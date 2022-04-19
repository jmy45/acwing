#include<iostream>
using namespace std;
const int N=200010;
int a[N],dp[N],q[N];
int main(){
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    int hh=0,tt=0;
    dp[1]=a[1];
    for (int i=2;i<=n;i++){
        if (hh<=tt&&i-q[hh]>m) hh++;
        while (hh<=tt&&dp[i-1]<=dp[q[tt]]) tt--;
        q[++tt]=i-1;
        dp[i]=a[i]+dp[q[hh]];
    }
    int ans=0x3f3f3f3f;
    for (int i=n;i>n-m;i--)
        ans=min(ans,dp[i]);
    cout<<ans<<endl;
    return 0;
}