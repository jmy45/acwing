#include<iostream>
using namespace std;
const int N=1010;
int dp[N];
int main(){
    int n;
    cin>>n;
    int a[]={0,10,20,50,100};
    dp[0]=1;
    for (int i=1;i<=4;i++)
        for (int j=a[i];j<=n;j++)
            dp[j]+=dp[j-a[i]];
    cout<<dp[n]<<endl;
    return 0;
}