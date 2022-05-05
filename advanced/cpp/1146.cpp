#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=310;
int n;
int w[N][N];
int dist[N];
bool st[N];
int prim(){
    memset(dist,0x3f,sizeof dist);
    dist[0]=0;
    int res=0;
    for (int i=0;i<n+1;i++){
        int t=-1;
        for (int j=0;j<=n;j++)
            if (!st[j]&&(t==-1||dist[t]>dist[j]))
                t=j;
        st[t]=true;
        res+=dist[t];
        for (int j=0;j<=n;j++)
            dist[j]=min(dist[j],w[t][j]);
    }
    return res;
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&w[0][i]);
        w[i][0]=w[0][i];
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            scanf("%d",&w[i][j]);
    printf("%d\n",prim());
    return 0;
}