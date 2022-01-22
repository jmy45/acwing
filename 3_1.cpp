#include<iostream>
using namespace std;
const int N=1010;
int volume[N],price[N];
int dp[N][N];
int main(){
    int n,v;
    scanf("%d%d",&n,&v);
    for (int i=1;i<=n;i++)
        scanf("%d%d",&volume[i],&price[i]);
    for (int i=1;i<=n;i++)
        for (int j=0;j<=v;j++){
            dp[i][j]=dp[i-1][j];
            if (j>=volume[i])
                dp[i][j]=max(dp[i][j],dp[i][j-volume[i]]+price[i]);
        }
    printf("%d",dp[n][v]);
    return 0;
}