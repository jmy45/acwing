#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1010,M=N*N,K=2*M;
int n,m,k,res;
int ids[N][N];
struct Edge{
    int a,b,w;
}e[K];
int p[M];
int find(int x){
    if (p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
void get_edges(){
    int dx[]={-1,0,1,0},dy[]={0,1,0,-1},dw[]={1,2,1,2};
    for (int z=0;z<2;z++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                for (int u=0;u<4;u++)
                    if (u%2==z){
                        int x=i+dx[u],y=j+dy[u],w=dw[u];
                        if (x&&x<=n&&y&&y<=m){
                            int a=ids[i][j],b=ids[x][y];
                            if (a<b) e[k++]={a,b,w};
                        }
                    }
}
int main(){
    cin>>n>>m;
    for (int i=1,t=1;i<=n;i++)
        for (int j=1;j<=m;j++,t++)
            ids[i][j]=t;
    for (int i=1;i<=n*m;i++) p[i]=i;
    int x1,y1,x2,y2;
    while (cin>>x1>>y1>>x2>>y2){
        int a=ids[x1][y1],b=ids[x2][y2];
        p[find(a)]=find(b);
    }
    get_edges();
    for (int i=0;i<k;i++){
        int a=find(e[i].a),b=find(e[i].b);
        if (a!=b){
            p[a]=b;
            res+=e[i].w;
        }
    }
    cout<<res<<endl;
    return 0;
}