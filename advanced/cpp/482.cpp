#include<iostream>
using namespace std;
const int N=1010;
int a[N],dp[N],dp2[N];
int main(){
    int n,res=1;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        dp[i]=1;
        for (int j=1;j<i;j++)
            if (a[j]<a[i])
                dp[i]=max(dp[i],dp[j]+1);
    }
    for (int i=n;i;i--){
        dp2[i]=1;
        for (int j=i+1;j<=n;j++)
            if (a[j]<a[i])
                dp2[i]=max(dp2[i],dp2[j]+1);
        res=max(res,dp[i]+dp2[i]-1);
    }
    printf("%d",n-res);
    return 0;
}