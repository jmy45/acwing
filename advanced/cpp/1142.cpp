#include<iostream>
#include<algorithm>
using namespace std;
const int N=310,M=8010;
int n,m,a,b,c,cnt,res;
int p[N];
struct edge{
    int a,b,w;
    bool operator <(const edge& e)const{
        return w<e.w;
    }
}edges[M];
int find(int x){
    return p[x]==x?x:find(p[x]);
}
int main(){
    cin>>n>>m;
    for (int i=0;i<m;i++){
        cin>>a>>b>>c;
        edges[i]={a,b,c};
    }
    sort(edges,edges+m);
    for (int i=1;i<=n;i++) p[i]=i;
    for (int i=0;i<m;i++){
        int a=edges[i].a,b=edges[i].b,c=edges[i].w;
        int x=find(a),y=find(b);
        if (x!=y){
            p[x]=y;
            cnt++;
            res=c;
            if (cnt==n-1) break;
        }
    }
    cout<<n-1<<" "<<res<<endl;
    return 0;
}