#include<iostream>
#include<cstring>
using namespace std;
const int N=51;
int w[N][N];
int dp[N][N];
int main(){
    int m,n;
    cin>>m>>n;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            cin>>w[i][j];
    memset(dp, 0x80, sizeof(dp));
    dp[m][m]=0;
    for(int sum = m+n - 1; sum >= 3; --sum)
        for(int i1 = max(1, sum - n); i1 <= min(m,sum); ++i1)
            for(int i2 = i1+1; i2 <= min(m,sum); ++i2)
            {
                int j1 = sum - i1, j2 = sum - i2;
                    dp[i1][i2] = w[i1][j1] + w[i2][j2] + max(
                max(dp[i1][i2+1], dp[i1+1][i2]), max(dp[i1+1][i2+1], dp[i1][i2]));
            }
    printf("%d",max(dp[1][2],dp[2][1]));   
    return 0;
}