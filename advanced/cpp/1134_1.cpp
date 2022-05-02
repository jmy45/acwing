#include<iostream>
#include<cstring>
#include<unordered_map>
#include<queue>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
unordered_map<int,unordered_map<int,int>> g;
const int N=100010,mod=1e5+3;
int n,m,a,b;
int dist[N];
int count[N];
void dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    count[1]=1;
    priority_queue<PII,vector<PII>,greater<>> heap;
    heap.push({0,1});
    while (heap.size()){
        auto [d,u]=heap.top();
        heap.pop();
        if (dist[u]!=d) continue;
        for (auto [j,v]:g[u])
            if (dist[j]>dist[u]+1){
                dist[j]=dist[u]+1;
                count[j]=((LL)count[u]*v)%mod;
                heap.push({dist[j],j});
            }
            else if (dist[j]==dist[u]+1)
                    count[j]=(count[j]+(LL)count[u]*v)%mod;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        g[a][b]++,g[b][a]++;
    }
    dijkstra();
    for (int i=1;i<=n;i++)
        printf("%d\n",count[i]);
    return 0;
}