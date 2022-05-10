#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=10010,M=20010;
int n,m,a,b,c;
int e[M],w[M],ne[M],h[N],idx;
int depth[N],fa[N][15];
int q[N];
int dist[N];
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
void bfs(int root){
    memset(depth,0x3f,sizeof depth);
    memset(dist,0x3f,sizeof dist);
    depth[root]=1;
    depth[0]=0;
    dist[root]=0;
    int hh=0,tt=0;
    q[0]=root;
    while (hh<=tt){
        int t=q[hh++];
        for (int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if (depth[j]>depth[t]+1){
                depth[j]=depth[t]+1;
                dist[j]=dist[t]+w[i];
                q[++tt]=j;
                fa[j][0]=t;
                for (int k=1;k<=14;k++)
                    fa[j][k]=fa[fa[j][k-1]][k-1];
            }
        }
    }
}
int lca(int a,int b){
    if (depth[a]<depth[b]) swap(a,b);
    for (int k=14;k>=0;k--)
        if (depth[fa[a][k]]>=depth[b])
            a=fa[a][k];
    if (a==b) return a;
    for (int k=14;k>=0;k--)
        if (fa[a][k]!=fa[b][k])
        {
            a=fa[a][k];
            b=fa[b][k];
        }
    return fa[a][0];
}
int main(){
    memset(h,-1,sizeof h);
    scanf("%d%d",&n,&m);
    for (int i=0;i<n-1;i++){
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c),add(b,a,c);
    }
    bfs(1);
    while (m--){
        scanf("%d%d",&a,&b);
        int anc=lca(a,b);
        int ans=dist[a]-dist[anc]+dist[b]-dist[anc];
        printf("%d\n",ans);
    }
    return 0;
}