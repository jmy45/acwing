#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<int,int> PII;
const int P=810,M=1450*2+10,INF=0x3f3f3f3f;
int n,p,c,idx;
int pos[P];
int e[M],w[M],ne[M],h[P];
int dist[P];
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
void dijkstra(int st){
    memset(dist,0x3f,sizeof(dist));
    dist[st]=0;
    priority_queue<PII,vector<PII>,greater<PII>>heap;
    heap.push({0,st});
    while (!heap.empty()){
        auto [d,u]=heap.top();
        heap.pop();
        if (d!=dist[u]) continue;
        for (int i=h[u];i!=-1;i=ne[i]){
            int j=e[i],v=w[i];
            if (dist[j]>dist[u]+v){
                dist[j]=dist[u]+v;
                heap.push({dist[j],j});
            }
        }
    }
}
int main(){
    memset(h,-1,sizeof h);
    scanf("%d%d%d",&n,&p,&c);
    for (int i=1;i<=n;i++) 
        scanf("%d",&pos[i]);
    for (int i=1;i<=c;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z),add(y,x,z);
    }
    int ans=INF;
    for (int i=1;i<=p;i++){
        dijkstra(i);
        int sum=0;
        for (int j=1;j<=n;j++)
            if (dist[pos[j]]==INF){
                sum=INF;
                break;
            }
            else sum+=dist[pos[j]];
        ans=min(ans,sum);
    }
    printf("%d\n",ans);
    return 0;
}