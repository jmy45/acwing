#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int M=200020;
LL a[M],q[M];
LL dp[M];
int main(){
    int n,k;
    cin>>n>>k;
    memset(dp,-0x3f,sizeof dp);
    int hh=0,tt=-1;
    q[++tt]=k;
    dp[k]=0;
    LL sum=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    for (int i=1;i<=n+1;i++){
        LL x=dp[q[hh]]-a[i];
        dp[k+i]=x;
        if (hh<=tt&&k+i-q[hh]>k) hh++;
        while (hh<=tt&&dp[q[tt]]<=x) tt--;
        q[++tt]=k+i;
    }
    cout<<sum+dp[q[hh]]<<endl;
    return 0;
}