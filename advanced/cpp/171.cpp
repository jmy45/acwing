#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=45;
int n,m,k;
int g[N];
int weights[1<<24],cnt;
int ans;
void dfs_1(int u,int s){
    if (u==k){
        weights[cnt++]=s;
        return;
    }
    if ((LL)s+g[u]<=m) dfs_1(u+1,s+g[u]);
    dfs_1(u+1,s);
}
void dfs_2(int u,int s){
    if (u==n){
        int l=0,r=cnt-1;
        while (l<r){
            int md=l+r+1>>1;
            if ((LL)weights[md]+s<=m) l=md;
            else r=md-1;
        }
        if ((LL)weights[r]+s<=m) ans=max(ans,weights[r]+s);
        return;
    }
    if ((LL)s+g[u]<=m) dfs_2(u+1,s+g[u]);
    dfs_2(u+1,s);
}
int main(){
    cin>>m>>n;
    for (int i=0;i<n;i++) cin>>g[i];
    sort(g,g+n);
    reverse(g,g+n);
    if (n/2+2<n) k=n/2+2;
    dfs_1(0,0);
    sort(weights,weights+cnt);
    cnt=unique(weights,weights+cnt)-weights;
    dfs_2(k,0);
    cout<<ans<<endl;
    return 0;
}