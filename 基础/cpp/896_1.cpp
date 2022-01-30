#include<iostream>
using namespace std;
const int N=100010;
int a[N],dp[N],idx;
int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    dp[idx]=a[0];
    for (int i=1;i<n;i++)
        if (a[i]>dp[idx]){
            dp[++idx]=a[i];
        }
        else{
        int p=lower_bound(dp,dp+idx+1,a[i])-dp;
        dp[p]=a[i];
        }
    cout<<idx+1<<endl;
    return 0;
}