#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
int relative[5];
const int N=510,M=2e5+10,INF=0x3f3f3f3f;
int e[M],w[M],ne[M],h[N],idx;
int n,m,a,b,c;
int dist[6][N];
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
void dijkstra(int dist[],int start){
    dist[start]=0;
    priority_queue<PII,vector<PII>,greater<>> heap;
    heap.push({0,start});
    while (heap.size()){
        auto [d,u]=heap.top();
        heap.pop();
        if (d!=dist[u]) continue;
        for (int i=h[u];i!=-1;i=ne[i]){
            int j=e[i];
            if (dist[j]>dist[u]+w[i]){
                dist[j]=dist[u]+w[i];
                heap.push({dist[j],j});
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    memset(dist,0x3f,sizeof dist);
    memset(h,-1,sizeof h);
    for (int i=0;i<5;i++)
        scanf("%d",&relative[i]);
    for (int i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c),add(b,a,c);
    }
    for (int i=0;i<5;i++)
        dijkstra(dist[i],relative[i]);
    dijkstra(dist[5],1);
    int res=INF;
    vector<int> v={0,1,2,3,4};
    do{
        int t=dist[5][relative[v[0]]];
        for (int i=0;i<4;i++){
            t+=dist[v[i]][relative[v[i+1]]];
            if (t>res) break;
        }
        res=min(res,t);
    }
    while (next_permutation(v.begin(),v.end()));
    printf("%d\n",res);
    return 0;
}