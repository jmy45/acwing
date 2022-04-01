#include<iostream>
using namespace std;
int a[202];
long long dp[202][202];
int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i=n;i<=2*n-1;i++){
        a[i]=a[i-n];
    }
    long long ans=0;
    for (int i=2*n-1;i>=0;i--)
        for (int j=i+1;j<2*n-1;j++){
            dp[i][j]=0;
            for (int k=i;k<j;k++)
                //E[i][k]=(i,k+1) E[k+1][j]=(k+1,j+1)
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1]);
        }
    for (int i=0;i<n;i++)
        ans=max(ans,dp[i][i+n-1]);       
    cout<<ans<<endl;
    return 0;
}