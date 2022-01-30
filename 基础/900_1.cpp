#include<iostream>
using namespace std;
const int N=1010,mod=1e9+7;
int dp[N][N];
int main(){
    int n;
    scanf("%d",&n);
    dp[0][0]=1;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=n;j++){
            dp[i][j]=dp[i-1][j];
            if (j>=i)
                dp[i][j]=(dp[i][j]+dp[i][j-i])%mod;
        }
    printf("%d",dp[n][n]);
    return 0;
}