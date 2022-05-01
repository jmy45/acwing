#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#define x first
#define y second
using namespace std;
typedef pair<int,int> PII;
const int N=25010,M=150010,INF=0x3f3f3f3f;
int n,mr,mp,S;
int h[N],e[M],w[M],ne[M],idx;
int id[N];
vector<int> block[N];
queue<int> q;
int dist[N],din[N];
bool st[N];
int bcnt;
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
void dfs(int u,int bid){
    id[u]=bid;
    block[bid].push_back(u);
    for (int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if (!id[j]) dfs(j,bid);
    }
}
void dijkstra(int bid){
    priority_queue<PII,vector<PII>,greater<>> heap;
    for (auto ver:block[bid]) heap.push({dist[ver],ver});
    while (heap.size()){
        auto t=heap.top();
        heap.pop();
        int ver=t.y,distance=t.x;
        if (st[ver]) continue;
        st[ver]=true;
        for (int i=h[ver];~i;i=ne[i]){
            int j=e[i];
            if (dist[j]>dist[ver]+w[i]){
                dist[j]=dist[ver]+w[i];
                if (id[j]==id[ver]) heap.push({dist[j],j});
            }
            if (id[j]!=id[ver]&&--din[id[j]]==0) q.push(id[j]);
        }
    }
}
void topsort(){
    memset(dist,0x3f,sizeof(dist));
    dist[S]=0;
    for (int i=1;i<=bcnt;i++)
        if (!din[i])
            q.push(i);
    while (q.size()){
        int t=q.front();
        q.pop();
        dijkstra(t);
    }
}
int main(){
    scanf("%d%d%d%d",&n,&mr,&mp,&S);
    memset(h,-1,sizeof h);
    while (mr--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c),add(b,a,c);
    }
    for (int i=1;i<=n;i++)
        if (!id[i])
            dfs(i,++bcnt);
    while (mp--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        din[id[b]]++;
    }
    topsort();
    for (int i=1;i<=n;i++)
        if (dist[i]>INF/2) puts("NO PATH");
        else printf("%d\n",dist[i]);
    return 0;
}