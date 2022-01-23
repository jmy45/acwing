#include<iostream>
#include<cstring>
using namespace std;
const int N=310;
int a[N],pre[N];
int dp[N][N];
int main(){
    int n;
    scanf("%d",&n);
    memset(dp,0x3f,sizeof dp);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=1;i<=n;i++)
        pre[i]=pre[i-1]+a[i];
    for (int i=n;i>=1;i--){
        dp[i][i]=0;
        for (int j=i+1;j<=n;j++){
            for (int k=i;k<j;k++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
            dp[i][j]+=pre[j]-pre[i-1];
        }
    }
    printf("%d",dp[1][n]);
    return 0;
}