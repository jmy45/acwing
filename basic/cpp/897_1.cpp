//最长公共子序列
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    string a,b;
    cin>>a;
    cin>>b;
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    cout<<dp[n][m]<<endl;
    return 0;
}