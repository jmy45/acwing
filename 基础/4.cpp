//多重背包I
#include<iostream>
using namespace std;
const int N=110;
int volume[N],price[N],count[N];
int dp[N];
int main(){
    int n,v;
    scanf("%d%d",&n,&v);
    for (int i=1;i<=n;i++)
        scanf("%d%d%d",&volume[i],&price[i],&count[i]);
    for (int i=1;i<=n;i++)
        for (int j=v;j>=volume[i];j--)
            for (int k=0;k<=count[i]&&k*volume[i]<=j;k++)
                dp[j]=max(dp[j],dp[j-k*volume[i]]+k*price[i]);
    printf("%d",dp[v]);
    return 0;
}