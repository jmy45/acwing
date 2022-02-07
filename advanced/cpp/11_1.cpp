#include<iostream>
#include<cstring>
using namespace std;
int dp[1010],p[1010],q[1010];
int main(){
    int n,v;
    cin>>n>>v;
    int mod=1e9+7;
    for (int i=0;i<=v;i++)
        p[i]=1;
    for (int i=1;i<=n;i++){
        int vol,wei;
        cin>>vol>>wei;
        memcpy(q,p,sizeof(p));
        for (int j=v;j>=vol;j--){
            if (dp[j-vol]+wei>dp[j]){
                dp[j]=dp[j-vol]+wei;
                p[j]=q[j-vol];
            }
            else if (dp[j-vol]+wei==dp[j]){
                p[j]+=q[j-vol];
                p[j]%=mod;
            }
        }
    }
    cout<<p[v]<<endl;
    return 0;
}