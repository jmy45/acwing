#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const int N=310;
struct edge{
    int a,b,w;
    bool operator < (const edge &e) const{
        return w<e.w;
    }
}edges[N*N];
int n,cnt;
LL cost;
int price[N];
int g[N][N];
int p[N],sz[N],minv[N];
int find(int x){
    return p[x]=p[x]==x?x:find(p[x]);
}
void un(int a,int b){
    int x=find(a),y=find(b);
    if (x!=y){
        if (sz[x]>sz[y]) swap(x,y);
        p[x]=y;
        sz[y]+=sz[x];
        minv[y]=min(minv[y],minv[x]);
    }
}
LL check(){
    LL sum=0;
    for (int i=1;i<=n;i++)
        if (p[i]==i)
            sum+=minv[i];
    return sum;
}
int main(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>price[i];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++){
            cin>>g[i][j];
            if (i<j){
                edges[cnt++]={i,j,g[i][j]};
            }
        }
    sort(edges,edges+cnt);
    for (int i=1;i<=n;i++) p[i]=i,sz[i]=1,minv[i]=price[i];
    LL res=check();
    for (int i=0;i<cnt;i++){
        int a=edges[i].a,b=edges[i].b,w=edges[i].w;
        if (find(a)!=find(b)&&w<max(minv[find(a)],minv[find(b)])){
            un(a,b);
            cost+=w;
            LL tt=check();
            res=min(res,cost+tt);
        }
    }
    cout<<res<<endl;
    return 0;
}