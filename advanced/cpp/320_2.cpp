#include<iostream>
#include<cstring>
using namespace std;
int a[202];
int dp[202][202];
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=n+1;i<=2*n;i++){
        a[i]=a[i-n];
    }
    memset(dp,-0x3f,sizeof(dp));
    int ans=0;
    for (int len=1;len<=n;len++)
        for (int i=1;i+len-1<2*n;i++){
            int j=i+len-1;
            if (len==1)
                dp[i][j]=0;
            else
                for (int k=i;k<j;k++)
                    dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1]);
        }
    for (int i=1;i<=n;i++)
        ans=max(ans,dp[i][i+n-1]);       
    cout<<ans<<endl;
    return 0;
}