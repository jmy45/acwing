#include<iostream>
using namespace std;
int dp[30010];
int main(){
    int n,m,price,value;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        cin>>price>>value;
        value*=price;
        for (int j=n;j>=price;j--)
            dp[j]=max(dp[j],dp[j-price]+value);
    }
    cout<<dp[n]<<endl;
    return 0;
}