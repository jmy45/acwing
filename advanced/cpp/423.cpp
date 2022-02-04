//knapsack problem
#include<iostream>
using namespace std;
const int N=1010;
int tm[N],value[N];
int dp[N];
int main(){
    int t,m;
    cin>>t>>m;
    for(int i=1;i<=m;i++)
        cin>>tm[i]>>value[i];
    for(int i=1;i<=m;i++){
        for (int j=t;j>=tm[i];j--)
            dp[j]=max(dp[j],dp[j-tm[i]]+value[i]);
    }
    cout<<dp[t]<<endl;
    return 0;
}