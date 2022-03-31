//环形合并石子，这题虽然标注为简单，但其实是LeetCode题扩展
#include<iostream>
using namespace std;
const int M=402;
int a[M];
int dp[M][M];
int pre[M];
int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
        pre[i+1]=pre[i]+a[i];
    }
    for (int i=n;i<2*n;i++){
        a[i]=a[i-n];
        pre[i+1]=pre[i]+a[i];
    }
    int ans=1e9;
    for (int i=2*n-1;i>=0;i--)
        for (int j=i+1;j<2*n;j++){
            dp[i][j]=1e9;
            for (int k=i;k<j;k++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+pre[j+1]-pre[i]);
        }
    for (int i=0;i<n;i++)
        ans=min(ans,dp[i][i+n-1]);
    cout<<ans<<endl;
    ans=0;
    for (int i=2*n-1;i>=0;i--)
        for (int j=i+1;j<2*n;j++){
            dp[i][j]=0;
            for (int k=i;k<j;k++)
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+pre[j+1]-pre[i]);
        }
    for (int i=0;i<n;i++)
        ans=max(ans,dp[i][i+n-1]);       
    cout<<ans<<endl;
    return 0;
}