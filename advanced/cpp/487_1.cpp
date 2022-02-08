#include<iostream>
#include<cstring>
using namespace std;
int v[61],p[61],q[61];
int h[61],e[61],ne[61],idx;
int dp[32010];
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int main(){
    int N,m;
    cin>>N>>m;
    memset(h,0xff,sizeof h);
    for (int i=1;i<=m;i++){
        cin>>v[i]>>p[i]>>q[i];
        if (q[i]){
            add(q[i],i);
        }
    }
    for (int i=1;i<=m;i++){
        if (q[i]) continue;
        for (int j=N;j>=0;j--){
            //i
            if (j>=v[i])
                dp[j]=max(dp[j],dp[j-v[i]]+v[i]*p[i]);
            if (h[i]==-1) continue;
            int a=e[h[i]];
            //i+a
            if (j>=v[i]+v[a])
                dp[j]=max(dp[j],dp[j-v[i]-v[a]]+v[i]*p[i]+v[a]*p[a]);
            if (ne[h[i]]==-1) continue;
            int b=e[ne[h[i]]];
            //i+b,i+a+b
            if (j>=v[i]+v[b])
                dp[j]=max(dp[j],dp[j-v[i]-v[b]]+v[i]*p[i]+v[b]*p[b]);
            if (j>=v[i]+v[a]+v[b])
                dp[j]=max(dp[j],dp[j-v[i]-v[a]-v[b]]+v[i]*p[i]+v[a]*p[a]+v[b]*p[b]); 
        }
    }
    cout<<dp[N]<<endl;
    return 0;
}