#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    string a,b;
    cin>>n;
    cin>>a;
    cin>>m;
    cin>>b;
    vector<vector<int>> dp(n+1,vector<int>(m+1,2e9));
    for (int i=0;i<=n;i++)
        dp[i][0]=i;
    for (int j=1;j<=m;j++)
        dp[0][j]=j;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1];
            else{
                dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
                dp[i][j]+=1;
            }
    cout<<dp[n][m]<<endl;
    return 0;
}   