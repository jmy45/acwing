#include<iostream>
#include<cstring>
using namespace std;
int f,n,m,w,a,b,c;
const int N=510,M=5210;
int cnt;
int dist[N],backup[N];
struct Edge{
    int a,b,w;
}edges[M];
string bellman_ford(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    for (int i=0;i<n;i++){
        memcpy(backup,dist,sizeof dist);
        for (int j=0;j<cnt;j++){
            int a=edges[j].a,b=edges[j].b,w=edges[j].w;
            if (dist[b]>backup[a]+w){
                dist[b]=backup[a]+w;
                if (i==n-1) return "YES";
            }
        }
    }
    return "NO";
}
int main(){
    scanf("%d",&f);
    while (f--){
        scanf("%d%d%d",&n,&m,&w);
        cnt=0;
        while (m--){
            scanf("%d%d%d",&a,&b,&c);
            edges[cnt++]={a,b,c};
            edges[cnt++]={b,a,c};
        }
        while (w--){
            scanf("%d%d%d",&a,&b,&c);
            edges[cnt++]={a,b,-c};
        }
        cout<<bellman_ford()<<endl;
    }
    return 0;
}