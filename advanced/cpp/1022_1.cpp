#include<iostream>
#include<cstring>
using namespace std;
const int K=110,M=510;
int nums[K],damage[K];
int dp[1010][510];
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    /*
    n个精灵球
    m为初始体力值
    k个小精灵
    */
    for (int i=1;i<=k;i++)
        cin>>nums[i]>>damage[i];

    for (int i=1;i<=k;i++)
        for (int j=n;j>=nums[i];j--)
            for (int l=m;l>damage[i];l--)
                    dp[j][l]=max(dp[j][l],dp[j-nums[i]][l-damage[i]]+1);
    int t=m-1;
    while (t&&dp[n][t]==dp[n][t+1])
        t--;
    cout<<dp[n][m]<<" "<<m-t<<endl;
    return 0;
}