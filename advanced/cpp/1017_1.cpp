#include<iostream>
using namespace std;
const int N=110;
int a[N],dp[N];
int main(){
    int k,n,ans;
    cin>>k;
    while (k--){
        cin>>n;
        ans=1;
        for (int i=0;i<n;i++){
            cin>>a[i];
            dp[i]=1;
            for (int j=0;j<i;j++)
                if (a[i]<a[j])
                    dp[i]=max(dp[i],dp[j]+1);
            ans=max(ans,dp[i]);
        }
        for (int i=n-1;i>=0;i--){
            dp[i]=1;
            for (int j=i+1;j<n;j++)
                if (a[j]>a[i])
                    dp[i]=max(dp[i],dp[j]+1);
            ans=max(ans,dp[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}