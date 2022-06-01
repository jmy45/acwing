#include<iostream>
#include<cstring>
using namespace std;
const int N=10010,M=N*N;
int e[M],ne[M],h[N],idx,ans;
int q[N];
int salary[N];
int din[N];
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int main(){
    int n,m;
    memset(h,-1,sizeof h);
    scanf("%d%d",&n,&m);
    while (m--){
        int a,b;
        scanf("%d%d",&a,&b);
        add(b,a);
        din[a]++;
    }
    int hh=0,tt=-1;
    for (int i=1;i<=n;i++)
        if (!din[i]) {
            q[++tt]=i;
            salary[i]=99;
        }
    while (hh<=tt){
        int u=q[hh++];
        salary[u]++;
        for (int i=h[u];~i;i=ne[i]){
            int j=e[i];
            salary[j]=max(salary[j],salary[u]);
            if (--din[j]==0) q[++tt]=j;
        }
    }
    if (tt<n-1) puts("Poor Xed");
    else{
        for (int i=1;i<=n;i++) ans+=salary[i];
        printf("%d",ans);
    }
    return 0;
}