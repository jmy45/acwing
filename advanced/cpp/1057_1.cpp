//Leetcode 股票买卖 IV
//最多k次交易
#include<iostream>
#include<cstring>
using namespace std;
const int INF=-2e9;
int dp[110][2],p[110][2];
int main(){
    int N,k,x;
    cin>>N>>k;
    dp[0][0]=0;dp[0][1]=INF;
    for (int i=1;i<=k;i++)
        dp[i][0]=dp[i][1]=INF;
    for (int i=1;i<=N;i++){
        cin>>x;
        memcpy(p,dp,sizeof(dp));
        dp[0][1]=max(dp[0][1],p[0][0]-x);
        for (int j=1;j<=k;j++){
            dp[j][0]=max(dp[j][0],p[j-1][1]+x);
            dp[j][1]=max(dp[j][1],p[j][0]-x);
        }
    }
    int ans=0;
    for (int i=0;i<=k;i++)
        ans=max(ans,dp[i][0]);
    cout<<ans<<endl;
    return 0;
}