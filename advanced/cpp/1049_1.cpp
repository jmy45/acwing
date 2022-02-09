#include<iostream>
using namespace std;
int a[100010],dp[100010];
int main(){
    int T;
    cin>>T;
    while (T--){
        int N;
        cin>>N;
        for (int i=1;i<=N;i++)
            cin>>a[i];
        dp[1]=a[1];
        dp[2]=max(a[1],a[2]);
        for (int i=3;i<=N;i++)
            dp[i]=max(dp[i-1],dp[i-2]+a[i]);
        cout<<dp[N]<<endl;
    }
    return 0;
}