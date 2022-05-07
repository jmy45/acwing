#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
const int N=510,M=10010;
int n,m;
struct Edge{
    int a,b,w;
    bool f;
    bool operator< (const Edge &t) const{
        return w<t.w;
    }
}edge[M];
int p[N];
PII dist[N][N];
int h[N],e[N*2],w[N*2],ne[N*2],idx;
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
int find(int x){
    if (p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
void dfs(int u,int fa,int maxd,int secd,PII d[]){
    d[u]={maxd,secd};
    for (int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if (j!=fa){
            if (w[i]>maxd)
                dfs(j,u,w[i],maxd,d);
            else if (w[i]==maxd)
                dfs(j,u,maxd,secd,d);
            else if (w[i]>secd)
                dfs(j,u,maxd,w[i],d);
            else
                dfs(j,u,maxd,secd,d);
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof(h));
    for (int i=0;i<m;i++){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        edge[i]={a,b,w,false};
    }
    sort(edge,edge+m);
    for (int i=1;i<=n;i++) p[i]=i;
    LL sum=0;
    for (int i=0;i<m;i++){
        int a=edge[i].a,b=edge[i].b,w=edge[i].w;
        int pa=find(a),pb=find(b);
        if (pa!=pb){
            p[pa]=pb;
            sum+=w;
            add(a,b,w),add(b,a,w);
            edge[i].f=true;
        }
    }
    for (int i=1;i<=n;i++) dfs(i,-1,0,0,dist[i]);
    LL res=1e18;
    for (int i=0;i<m;i++)
        if (!edge[i].f){
            int a=edge[i].a,b=edge[i].b,w=edge[i].w;
            auto [maxd,secd]=dist[a][b];
            if (w>maxd)
                res=min(res,sum+w-maxd);
            else if (w==maxd)
                res=min(res,sum+w-secd);
        }
    printf("%lld\n",res);
    return 0;
}