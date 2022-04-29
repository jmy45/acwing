#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<int,int> PII;
const int N=101,M=402,INF=0x3f3f3f3f;
int e[M],w[M],ne[M],h[N],idx;
int n,m,a,b,c;
int dist[N];
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
void dijkstra(int st){
    memset(dist,0x3f,sizeof(dist));
    dist[st]=0;
    priority_queue<PII,vector<PII>,greater<PII> >heap;
    heap.emplace(0,st);
    while (!heap.empty()){
        auto [d,u]=heap.top();
        heap.pop();
        if (d!=dist[u]) continue;
        for (int i=h[u];~i;i=ne[i]){
            int j=e[i],v=w[i];
            if (dist[u]+v<dist[j]){
                dist[j]=dist[u]+v;
                heap.emplace(dist[j],j);
            }
        }
    }
}
int main(){
    memset(h,-1,sizeof h);
    cin>>n>>m;
    for (int i=0;i<m;i++){
        cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);
    }
    dijkstra(1);
    int ans=0;
    for (int i=1;i<=n;i++)
        ans=max(ans,dist[i]);
    cout<<(ans==INF?-1:ans)<<endl;
    return 0;
}