#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<double,int> PII;
const int N=2010,M=2e5+10;
int n,m,a,b,c,st,ed,e[M],w[M],ne[M],h[N],idx;
double dist[N];
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
void dijkstra(){
    dist[st]=100;
    priority_queue<PII>heap;
    heap.push(PII(100,st));
    while (!heap.empty()){
        auto [d,u]=heap.top();
        heap.pop();
        if (d>dist[u]) continue;
        for (int i=h[u];~i;i=ne[i]){
            int j=e[i];
            if (dist[j]<dist[u]*(1-(double)w[i]/100)){
                dist[j]=dist[u]*(1-(double)w[i]/100);
                heap.push(PII(dist[j],j));
            }
        }
    }
}
int main(){
    memset(h,-1,sizeof(h));
    cin>>n>>m;
    for (int i=0;i<m;i++){
        cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);
    }
    cin>>st>>ed;
    dijkstra();
    printf("%.8f\n",10000/dist[ed]);
    return 0;
}