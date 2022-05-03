#include<iostream>
#include<cstring>
using namespace std;
const int N=110,M=10010,INF=0x3f3f3f3f;
int n,m,a,b,c,cnt;
int g[N][N],d[N][N],p[N][N];
int path[N];
void get_path(int i,int j){
    if (p[i][j]==0) return;
    int k=p[i][j];
    get_path(i,k);
    path[cnt++]=k;
    get_path(k,j);
}
int main(){
    cin>>n>>m;
    memset(g,0x3f,sizeof g);
    for (int i=1;i<=n;i++) g[i][i]=0;
    while (m--){
        cin>>a>>b>>c;
        g[a][b]=g[b][a]=min(g[a][b],c);
    }
    int res=INF;
    memcpy(d,g,sizeof d);
    for (int k=1;k<=n;k++){
        for (int i=1;i<k;i++)
            for (int j=i+1;j<k;j++)
                if ((long long)d[i][j]+g[j][k]+g[k][i]<res){
                    res=d[i][j]+g[j][k]+g[k][i];
                    cnt=0;
                    path[cnt++]=k;
                    path[cnt++]=i;
                    get_path(i,j);
                    path[cnt++]=j;
                }
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (d[i][j]>d[i][k]+d[k][j]){
                    d[i][j]=d[i][k]+d[k][j];
                    p[i][j]=k;
                }
    }
    if (res==INF) puts("No solution.");
    else{
        for (int i=0;i<cnt;i++)
            cout<<path[i]<<" ";
        cout<<endl; 
    }
    return 0;                
}