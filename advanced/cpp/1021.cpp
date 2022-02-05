#include<iostream>
using namespace std;
const int M=3010;
typedef long long LL;
LL dp[M],a[M];
int main(){
    int n,m,x;
    cin>>n>>m;
    dp[0]=1;
    for (int i=1;i<=n;i++){
        cin>>x;
        for (int j=x;j<=m;j++)
            dp[j]+=dp[j-x];
    }
    cout<<dp[m]<<endl;
    return 0;
}