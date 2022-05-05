//可能是2个不连通的环
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
const int N=110,M=410;
int n,k,a,b,c,sum;
int p[N];
struct edge{
    int a,b,w;
    bool operator <(const edge&r) const{
        return w<r.w;
    }
}edges[M];
int dist[N];
int find(int x){
    if (p[x]==x) return x;
    return p[x]=find(p[x]);
}
void un(int a,int b){
    int x=find(a),y=find(b);
    if (x!=y) p[x]=y;
}
int main(){
    cin>>n>>k;
    for (int i=0;i<k;i++){
        cin>>a>>b>>c;
        edges[i]={a,b,c};
        sum+=c;
    }
    for (int i=1;i<=n;i++) p[i]=i;
    sort(edges,edges+k);
    for (int i=0;i<k;i++){
        a=edges[i].a,b=edges[i].b,c=edges[i].w;
        if (find(b)!=find(a)){
            un(a,b);
            sum-=c;
        }
    }
    cout<<sum<<endl;
    return 0;
}