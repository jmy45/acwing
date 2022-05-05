#include<iostream>
#include<algorithm>
using namespace std;
const int N=2010,M=10010;
int n,m,p,u,v,w,cost;
int pa[N];
struct edge{
    int u,v,w;
    bool operator <(const edge& e)const{
        return w<e.w;
    }
}edges[M];
int find(int x){
    return pa[x]==x?x:find(pa[x]);
}
void un(int a,int b){
    int x=find(a),y=find(b);
    if (x!=y) pa[x]=y;
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++) pa[i]=i;
    for (int i=0;i<m;i++){
        int p,u,v,w;
        cin>>p>>u>>v>>w;
        if (p==1){
            cost+=w;
            un(u,v);
        }
        else edges[i]={u,v,w};
    }
    sort(edges,edges+m);
    for (int i=0;i<m;i++){
        u=edges[i].u,v=edges[i].v,w=edges[i].w;
        if (find(u)!=find(v)){
            cost+=w;
            un(u,v);
        }
    }
    cout<<cost<<endl;
    return 0;
}