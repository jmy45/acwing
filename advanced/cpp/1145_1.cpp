#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
typedef pair<int,int> PII;
const int N=510,M=N*N;
int n,k,x,y,cnt;
int p[N];
PII v[N];
struct edge{
    int a,b;
    double w;
    bool operator < (const edge &e) const{
        return w<e.w;
    }
}edges[M];
edge calc(int i,int j){
    auto [x0,y0]=v[i];
    auto [x1,y1]=v[j];
    double dis=sqrt((x1-x0)*(x1-x0)+(y1-y0)*(y1-y0));
    return {i,j,dis};
}
int find(int x){
    return p[x]=p[x]==x?x:find(p[x]);
}
int main(){
    cin>>n>>k;
    for (int i=1;i<=n;i++) p[i]=i;
    for (int i=1;i<=n;i++){
        cin>>x>>y;
        v[i]={x,y};
    }
    for (int i=1;i<n;i++)
        for (int j=i+1;j<=n;j++)
            edges[cnt++]=calc(i,j);
    sort(edges,edges+cnt);
    vector<int> res;
    for (int i=0;i<cnt;i++){
        int a=edges[i].a,b=edges[i].b;
        if (find(a)!=find(b)){
            res.push_back(i);
            p[find(a)]=find(b);
            if (res.size()==n-1) break;
        }
    }
    int l=res.size();
    if (k-1>=l)
        printf("%.2f\n",0);
    else
        if (!k)
            printf("%.2f\n",edges[res[l-1]].w);
        else
            printf("%.2f\n",edges[res[l-k]].w);
    return 0;
}