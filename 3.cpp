//完全背包
#include<iostream>
using namespace std;
const int N=1010;
int volume[N],price[N];
int dp[N];
int main(){
    int n,v;
    scanf("%d%d",&n,&v);
    for (int i=1;i<=n;i++)
        scanf("%d%d",&volume[i],&price[i]);
    for (int i=1;i<=n;i++)
        for (int j=volume[i];j<=v;j++)
            dp[j]=max(dp[j],dp[j-volume[i]]+price[i]);
    printf("%d",dp[v]);
    return 0;
}