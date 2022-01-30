//bfs
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100010,M=200010;
int n,m;
int h[N],e[M],ne[M],idx;
int color[N],q[N];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
bool bfs(int u){
    int hh=0,tt=-1;
    q[++tt]=u;
    color[u]=1;
    while (hh<=tt){
        int l=tt-hh+1;
        for (int i=0;i<l;i++){
            int cur=q[hh++];
            for (int j=h[cur];j!=-1;j=ne[j]){
                int k=e[j];
                if (color[k]==color[cur]){
                    return false;
                }
                else if (!color[k]){
                   color[k]=3-color[cur];
                   q[++tt]=k; 
                }                
            }
        }
    }
    return true;
}

int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);
    while (m--){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b),add(b,a);
    }
    bool flag=true;
    for (int i=1;i<=n;i++)
        if (!color[i]){
            if (!bfs(i)){
                flag=false;
                break;
            }
        }
    if (flag) puts("Yes");
    else puts("No");
    return 0;
}