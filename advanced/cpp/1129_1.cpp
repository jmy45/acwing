#include<iostream>
#include<cstring>
#include<queue>
#include<unordered_map>
using namespace std;
typedef pair<int,int> PII;
const int N=2501,INF=0x3f3f3f3f;
int t,c,st,ed;
int dist[N];
unordered_map<int,unordered_map<int,int>> g;
void dijkstra(){
    memset(dist,0x3f,sizeof(dist));
    dist[st]=0;
    priority_queue<PII,vector<PII>,greater<>> heap;
    heap.emplace(0,st);
    while (!heap.empty()){
        auto [d,u]=heap.top();
        heap.pop();
        if (d!=dist[u]) continue;
        for (auto &[k,v]:g[u]){
            if (dist[k]>dist[u]+v){
                dist[k]=dist[u]+v;
                heap.emplace(dist[k],k);
            }
        }
    }
}
int main(){
    scanf("%d%d%d%d",&t,&c,&st,&ed);
    for (int i=0;i<c;i++){
        int s,e,cost;
        scanf("%d%d%d",&s,&e,&cost);
        g[s][e]=cost;
        g[e][s]=cost;
    }
    dijkstra();
    printf("%d\n",dist[ed]);
    return 0;
}