#include<iostream>
#include<algorithm>
using namespace std;
const int N=6010;
int n;
struct edge{
    int a,b,w;
    bool operator< (const edge &t) const{
        return w<t.w;
    }
}e[N];
int p[N],sz[N];
int find(int x){
    if (p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
int main(){
    int T;
    cin>>T;
    while (T--){
        cin>>n;
        for (int i=0;i<n-1;i++){
            int a,b,w;
            cin>>a>>b>>w;
            e[i]={a,b,w};
        }
        sort(e,e+n-1);
        for (int i=1;i<=n;i++) p[i]=i,sz[i]=1;
        int res=0;
        for (int i=0;i<n-1;i++){
            int a=find(e[i].a),b=find(e[i].b),w=e[i].w;
            if (a!=b){
                res+=(sz[a]*sz[b]-1)*(w+1);
                p[a]=b;
                sz[b]+=sz[a];
            }
        }
        cout<<res<<endl;
    }
    return 0;
}