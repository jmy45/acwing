//newhar
#include<iostream>
#include<cstring>
#define INT_MIN -2e9
using namespace std;
const int N=15;
int n;
int w[N][N];
int dp[N][N];
int main(){
    scanf("%d",&n);
    int a,b,c;
    while (cin>>a>>b>>c,a||b||c)
        w[a][b]=c;
    memset(dp, 0x80, sizeof(dp)); 
    dp[n][n] = w[n][n]; 
    for(int sum = 2*n - 1; sum >= 2; --sum)
        for(int i1 = max(1, sum - n); i1 <= min(n,sum); ++i1)
            for(int i2 = i1; i2 <= min(n,sum); ++i2)
            {
                int j1 = sum - i1, j2 = sum - i2;
                /*
                if (w[i1][j1] == -1 || w[i2][j2] == -1) 
                    dp[i1][i2] = INT_MIN;
                else*/
                dp[i1][i2] = w[i1][j1] + (i1 != i2 || j1 != j2)*w[i2][j2] + max(
                max(dp[i1][i2+1], dp[i1+1][i2]), max(dp[i1+1][i2+1], dp[i1][i2]));
            }
    int ans=max(0, dp[1][1]);
    printf("%d",ans); 
    return 0;
}