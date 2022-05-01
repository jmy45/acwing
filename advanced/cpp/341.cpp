#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100010,M=2000010;
int n,m;
int w[N];
int hs[N],ht[N],e[M],ne[M],idx;
int dmin[N],dmax[N];
bool st[N];
int q[N];
void add(int h[],int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void spfa(int h[],int dist[],int type){
    int hh=0,tt=1;
    if (type==0){
        memset(dist,0x3f,sizeof dmin);
        dist[1]=w[1];
        q[0]=1;
    }
    else{
        memset(dist,-0x3f,sizeof dmax);
        dist[n]=w[n];
        q[0]=n;
    }
    while (hh!=tt){
        int t=q[hh++];
        if (hh==N) hh=0;
        st[t]=false;
        for (int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if (type==0&&dist[j]>min(dist[t],w[j])||type==1&&dist[j]<max(dist[t],w[j]))
            {
                if (type==0) dist[j]=min(dist[t],w[j]);
                else dist[j]=max(dist[t],w[j]);
                if (!st[j]){
                    q[tt++]=j;
                    if (tt==N) tt=0;
                    st[j]=true;
                }
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&w[i]);
    memset(hs,-1,sizeof hs);
    memset(ht,-1,sizeof ht);
    while (m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(hs,a,b),add(ht,b,a);
        if (c==2) add(hs,b,a),add(ht,a,b);
    }
    spfa(hs,dmin,0);
    spfa(ht,dmax,1);
    int res=0;
    for (int i=1;i<=n;i++) res=max(res,dmax[i]-dmin[i]);
    printf("%d\n",res);
    return 0;
}