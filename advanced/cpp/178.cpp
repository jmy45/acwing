//A*
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N=1010,M=200010;
int n,m;
int h[N],rh[N],e[M],w[M],ne[M],idx;
int dist[N],f[N],st[N];
int S,T,K;
void add(int *h,int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
void dijkstra(){
    priority_queue<PII,vector<PII>,greater<PII>>heap;
    memset(dist,0x3f,sizeof dist);
    dist[T]=0;
    heap.push({0,T});
    while (heap.size()){
        auto t=heap.top();
        heap.pop();
        int ver=t.second;
        if (st[ver]) continue;
        st[ver]=1;
        for (int i=rh[ver];~i;i=ne[i]){
            int j=e[i];
            if (dist[j]>dist[ver]+w[i]){
                dist[j]=dist[ver]+w[i];
                heap.push({dist[j],j});
            }
        }
    }
    memcpy(f,dist,sizeof f);
}
int a_star(){
    priority_queue<PIII,vector<PIII>,greater<PIII>>heap;
    heap.push({f[S],{0,S}});
    memset(st,0,sizeof st);
    while (heap.size()){
        auto t=heap.top();
        heap.pop();
        int ver=t.second.second,dist=t.second.first;
        if (st[ver]>=K) continue;
        st[ver]++;
        if (ver==T&&st[ver]==K) return dist;
        for (int i=h[ver];~i;i=ne[i]){
            int j=e[i];
            if (st[j]<K)
                heap.push({dist+w[i]+f[j],{dist+w[i],j}});
        }
    }
    return -1;
}
int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);
    memset(rh,-1,sizeof rh);
    while (m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(h,a,b,c),add(rh,b,a,c);
    }
    scanf("%d%d%d",&S,&T,&K);
    if (S==T) K++;
    dijkstra();
    printf("%d\n",a_star());
    return 0;
}