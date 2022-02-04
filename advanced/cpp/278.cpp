//类似于整数划分
#include<iostream>
using namespace std;
const int N=10010;
int dp[N];
int main(){
    int n,m,x;
    cin>>n>>m;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        cin>>x;
        for (int j=m;j>=x;j--)
            dp[j]+=dp[j-x];
    }
    cout<<dp[m]<<endl;
    return 0;
}