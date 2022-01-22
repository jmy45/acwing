#include<iostream>
using namespace std;
const int N=110;
int volume[N],price[N],count[N];
int dp[N][N];
int main(){
    int n,v;
    scanf("%d%d",&n,&v);
    for (int i=1;i<=n;i++)
        scanf("%d%d%d",&volume[i],&price[i],&count[i]);
    for (int i=1;i<=n;i++)
        for (int j=0;j<=v;j++)
            for (int k=0;k<=count[i]&&volume[i]*k<=j;k++)
                dp[i][j]=max(dp[i][j],dp[i-1][j-k*volume[i]]+k*price[i]);
    printf("%d",dp[n][v]);
    return 0;
}