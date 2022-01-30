#include<iostream>
using namespace std;
const int N=1010;
int a[N],dp[N];
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    dp[1]=1;
    for (int i=2;i<=n;i++){
        dp[i]=1;
        for (int j=1;j<i;j++)
            if (a[j]<a[i])
                dp[i]=max(dp[i],dp[j]+1);
    }
    int ans=0;
    for (int i=1;i<=n;i++)
        ans=max(ans,dp[i]);
    cout<<ans<<endl;
    return 0;
}