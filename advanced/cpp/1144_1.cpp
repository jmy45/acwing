#include<iostream>
#include<algorithm>
using namespace std;
const int N=1010,M=N*N;
int n,m,x1,y1,x2,y2,x,y,cnt,w,res;
int p[M],sz[M];
struct edge{
    int x,y,w;
    bool operator <(const edge& e)const{
        return w<e.w;
    }
}edges[M*2];
int find(int x){
    return p[x]=p[x]==x?x:find(p[x]);
}
void un(int a,int b){
    int x=find(a),y=find(b);
    if (x!=y){
        if (sz[x]>sz[y]) swap(x,y);
        p[x]=y;
        sz[y]+=sz[x];
    }
}
int main(){
    scanf("%d%d",&m,&n);
    for (int i=1;i<=n*m;i++) p[i]=i,sz[i]=1;
    while (scanf("%d%d%d%d",&x1,&y1,&x2,&y2)!=EOF){
        x=(x1-1)*n+y1,y=(x2-1)*n+y2;
        un(x,y);
    }
    for (int i=1;i<=m-1;i++)
        for (int j=1;j<=n;j++){
            x=(i-1)*n+j,y=i*n+j;
            //if (find(x)!=find(y))
                edges[cnt++]={x,y,1};
        }
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n-1;j++)
        {
            x=(i-1)*n+j,y=x+1;
            //if (find(x)!=find(y))
                edges[cnt++]={x,y,2};
        }
    for (int i=0;i<cnt;i++){
        x=edges[i].x,y=edges[i].y,w=edges[i].w;
        if (find(x)!=find(y)){
            un(x,y);
            res+=w;
        }
        if (sz[x]==n*m) break;
    }
    printf("%d\n",res);
    return 0;
}