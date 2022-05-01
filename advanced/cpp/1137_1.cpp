#include<iostream>
#include<cstring>
#include<queue>
#include<unordered_map>
using namespace std;
typedef pair<int,int> PII;
const int N=1010,INF=0x3f3f3f3f;
int n,m,s,a,b,c,w2;
int dist[N];
unordered_map<int,unordered_map<int,int>> g;
void dijkstra(int start){
    memset(dist,0x3f,sizeof dist);
    dist[start]=0;
    priority_queue<PII,vector<PII>,greater<>> heap;
    heap.push({0,start});
    while (heap.size()){
        auto [d,u]=heap.top();
        heap.pop();
        if (dist[u]!=d) continue;
        for (auto [j,v]:g[u]){
            if (dist[j]>dist[u]+v){
                dist[j]=dist[u]+v;
                heap.push({dist[j],j});
            }
        }
    }
}
int main(){
    while (cin>>n>>m>>s){
        g.clear();
        for (int i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            if (g[a].count(b))
                g[a][b]=min(g[a][b],c);
            else
                g[a][b]=c;
        }
        scanf("%d",&w2);
        for (int i=0;i<w2;i++){
            scanf("%d",&a);
            g[n+1][a]=0;
        }
        dijkstra(n+1);
        if (dist[s]>INF/2) puts("-1");
        else printf("%d\n",dist[s]);
    }
    return 0;
}