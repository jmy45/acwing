#include<iostream>
using namespace std;
int dp[16][16],p[16][16],a[16];
int main(){
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++)
            cin>>a[j];
        for (int k=0;k<=m;k++){
            dp[i][k]=dp[i-1][k];
            p[i][k]=k;
            for (int j=1;j<=k;j++)
                if (dp[i-1][k-j]+a[j]>dp[i][k]){
                    dp[i][k]=dp[i-1][k-j]+a[j];
                    p[i][k]=k-j;
                }
        }
    }
    cout<<dp[n][m]<<endl;
    int i=n,j=m;
    while (i){
        cout<<i<<" "<<j-p[i][j]<<endl;
        j=p[i][j];
        i--;
    }
    return 0;
}