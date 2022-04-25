//1700ms
#include<iostream>
#include<cstring>
using namespace std;
int n,w;
const int N=18,INF=0x3f3f3f3f;
int a[N];
bool g[1<<N];
int f[1<<N];
int dfs(int st){
    if (!st) return 0;
    if (f[st]!=INF) return f[st];
    int t=0;
    for (;t<n;t++)
        if (st>>t&1) break;
    int j=1<<t,tt=st^j;
    for (int i=tt;i>0;i=(i-1)&tt)
        if (g[i|j])
            f[st]=min(f[st],dfs(st^(i|j))+1);
    if (f[st]==INF&&g[j])
        f[st]=min(f[st],dfs(st^j)+1);
    return f[st];
}
int main(){
    cin>>n>>w;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int st=1;st<1<<n;st++){
        int sum=0;
        for (int i=0;i<n;i++)
            if (st>>i&1)
                sum+=a[i];
        if (sum<=w)
            g[st]=true;
    }
    memset(f,0x3f,sizeof f);
    cout<<dfs((1<<n)-1)<<endl;
    return 0;
}