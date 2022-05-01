#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1010,M=21010,INF=0x3f3f3f3f;
int n,m,T;
int h[N],e[M],w[M],ne[M],idx;
int dist[N],q[N];
bool st[N];
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
int spfa(){
    memset(dist,0x3f,sizeof dist);
    dist[0]=0;
    int hh=0,tt=1;
    q[0]=0;
    while (hh!=tt){
        int t=q[hh++];
        if (hh==N) hh=0;
        st[t]=false;
        for (int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if (dist[j]>dist[t]+w[i]){
                dist[j]=dist[t]+w[i];
                if (!st[j]){
                    q[tt++]=j;
                    if (tt==N) tt=0;
                    st[j]=true;
                }
            }
        }
    }
    if (dist[T]==INF) return -1;
    return dist[T];
}
int main(){
    while (scanf("%d%d%d",&n,&m,&T)!=-1){
        memset(h,-1,sizeof h);
        idx=0;
        while (m--){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
        }
        int s;
        scanf("%d",&s);
        while (s--){
            int ver;
            scanf("%d",&ver);
            add(0,ver,0);
        }
        printf("%d\n",spfa());
    }
    return 0;
}