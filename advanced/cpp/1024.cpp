#include<iostream>
using namespace std;
const int N=31,M=20010;
int vol[N],dp[M];
int main(){
    int v,n;
    cin>>v>>n;
    for (int i=1;i<=n;i++)
        cin>>vol[i];
    for (int i=1;i<=n;i++)
        for (int j=v;j>=vol[i];j--)
            dp[j]=max(dp[j],dp[j-vol[i]]+vol[i]);
    cout<<v-dp[v]<<endl;
    return 0;
}