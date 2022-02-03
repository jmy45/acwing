#include<iostream>
#include<algorithm>
using namespace std;
const int N=5010;
typedef pair<int,int> PII;
PII c[N];
int dp[N];
int main(){
    int n,a,b;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a>>b;
        c[i]={a,b};
    }
    sort(c,c+n);
    int ans=0;
    for (int i=0;i<n;i++){
        dp[i]=1;
        for (int j=0;j<i;j++)
            if (c[i].second>c[j].second)
                dp[i]=max(dp[i],dp[j]+1);
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}