#include<iostream>
#include<cstring>
using namespace std;
const int N=110,M=N*N;
int e[M],ne[M],h[N],idx;
int din[N];
int q[N];
int add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int main(){
    memset(h,-1,sizeof h);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        int x;
        while (cin>>x,x){
            add(i,x);
            din[x]++;
        }
    }
    int hh=0,tt=-1;
    for (int i=1;i<=n;i++)
        if (!din[i]) q[++tt]=i;
    while (hh<=tt){
        int u=q[hh++];
        printf("%d ",u);
        for (int i=h[u];~i;i=ne[i]){
            int j=e[i];
            if (--din[j]==0) q[++tt]=j;
        }
    }
    return 0;
}