#include<iostream>
using namespace std;
const int N=1010;
int a[N];
//最大上升子序列和
int dp[N];
int main(){
    int n;
    cin>>n;
    int ans=0;
    for (int i=0;i<n;i++){
        cin>>a[i];
        for (int j=0;j<i;j++)
            if (a[j]<a[i])
                dp[i]=max(dp[i],dp[j]);
        dp[i]+=a[i];
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}