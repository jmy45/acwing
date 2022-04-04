//这题也分类为简单题？？
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=10010,M=N*2,INF=0x3f3f3f3f;
int n;
int h[N],e[M],w[M],ne[M],idx;
int d1[N],d2[N],up[N],p1[N],p2[N];
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
int dfs_d(int u,int fa){
    d1[u]=d2[u]=-INF;
    for (int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
        if (j==fa)
            continue;
        int d=dfs_d(j,u)+w[i];
        if (d>=d1[u]) {
            d2[u]=d1[u],d1[u]=d;
            p2[u]=p1[u],p1[u]=j;
        }
        else if (d>d2[u]) d2[u]=d,p2[u]=j;
    }
    if (d1[u]==-INF)
        d1[u]=d2[u]=0;
    return d1[u];
}
void dfs_u(int u,int fa){
    for (int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
        if (j==fa)
            continue;
        if (p1[u]==j)
            up[j]=max(up[u],d2[u])+w[i];
        else
            up[j]=max(up[u],d1[u])+w[i];
        dfs_u(j,u);
    }
}
int main(){
    cin>>n;
    memset(h,-1,sizeof h);
    for (int i=0;i<n-1;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);
    }
    dfs_d(1,-1);
    dfs_u(1,-1);
    int res=INF;
    for (int i=1;i<=n;i++)
        res=min(res,max(d1[i],up[i]));
    cout<<res<<endl;
    return 0;
}