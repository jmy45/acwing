#include<iostream>
#include<cstring>
using namespace std;
typedef pair<int,int> PII;
const int N=18,M=1<<N,INF=0x3f3f3f3f;
double x[N],y[N];
int n,m;
int limit;
int dp[M],mpigs[M];
PII dfs(int st){
    if (st==(1<<n)-1)
        return {0,INF};
    if (dp[st]!=INF)
        return {dp[st],mpigs[st]};
    int i=0,st2=st;
    for (;i<n;i++)
        if ((st2&(1<<i))==0) break;
    auto [rbirds,qbirds]=dfs(st|(1<<i));
    if (rbirds>dp[0]||rbirds>limit) dp[st]=INF-1;
    if (m==2&&qbirds!=INF)
        mpigs[st]=min(mpigs[st],qbirds+1);
    if (m==2&&1>=n/3)
        mpigs[st]=min(mpigs[st],rbirds+1);
    if (rbirds+1<dp[st])
        dp[st]=rbirds+1;
    for (int j=i+1;j<n;j++){
        int tt=1<<i;
        if (st2&(1<<j)) continue;
        tt|=1<<j;
        double a1=x[i]*x[i],b1=x[i],c1=y[i];
        double a2=x[j]*x[j],b2=x[j],c2=y[j];
        double d=a1*b2-a2*b1,d1=a1*c2-a2*c1,d2=-b1*c2+b2*c1;
        double a=d2/d,b=d1/d;
        if (a>=0) continue;
        int c=2;
        for (int k=j+1;k<n;k++)
            if (abs(a*x[k]*x[k]+b*x[k]-y[k])<1e-6){
                tt|=1<<k;
                c++;
            }
        auto [rbirds,qbirds]=dfs(st|tt);
        if (rbirds>dp[0]||rbirds>limit) dp[st]=INF-1;
        if (m==2&&qbirds!=INF)
            mpigs[st]=min(mpigs[st],qbirds+1);
        if (m==2&&c>=n/3)
            mpigs[st]=min(mpigs[st],rbirds+1);
        if (rbirds+1<dp[st])
            dp[st]=rbirds+1;
        st2|=tt;
    }
    return {dp[st],mpigs[st]};
}
int main(){
    int T;
    cin>>T;
    while (T--){
        cin>>n>>m;
        limit=n;
        memset(dp,0x3f,sizeof(dp));
        memset(mpigs,0x3f,sizeof(mpigs));
        if (m==1)
            limit=(n-1)/3+2;
        for (int i=0;i<n;i++)
            cin>>x[i]>>y[i];
        cout<<(m==2?dfs(0).second:dfs(0).first)<<endl;
    }
    return 0;
}