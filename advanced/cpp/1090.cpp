//连续m+1个题必选1题的最少耗费时间<t
#include<iostream>
using namespace std;
const int N=50010;
int a[N],q[N],dp[N];
int t,n;
int check(int m){
    int hh=0,tt=0;
    for (int i=1;i<=n;i++){
        if (hh<=tt&&i-q[hh]>m+1) hh++;
        dp[i]=a[i]+dp[q[hh]];
        while (hh<=tt&&dp[i]<=dp[q[tt]]) tt--;
        q[++tt]=i;
    }
    int res=0x3f3f3f3f;
    for (int i=n-m;i<=n;i++)
        res=min(res,dp[i]);
    return res;
}
int main(){
    cin>>n>>t;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    int l=0,r=n;
    while (l<r){
        int mid=(l+r)>>1;
        if (check(mid)>t)
            l=mid+1;
        else
            r=mid;
    }
    cout<<r<<endl;
    return 0;
}