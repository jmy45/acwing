//LeetCode 股票买卖 V
#include<iostream>
using namespace std;
int dp[100010][2];
const int INF=-2e9;
int main(){
    int N,x;
    cin>>N;
    dp[0][1]=INF;
    for (int i=1;i<=N;i++){
        cin>>x;
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]+x);
        dp[i][1]=max(dp[i-1][1],i<=2?-x:dp[i-2][0]-x);
    }
    cout<<dp[N][0]<<endl;
    return 0;
}