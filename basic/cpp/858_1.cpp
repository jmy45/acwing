//prim
//mlogm
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
typedef pair<int,int> PII;
const int N=510,INF=0x3f3f3f3f;
int n,m;
vector<unordered_map<int,int>> g(N);
int d[N];
bool st[N];
int prim(){
    memset(d,0x3f,sizeof d);
    int res=0,tot=1;
    priority_queue<PII,vector<PII>,greater<PII>> h;
    h.emplace(0,0);
    st[0]=true;
    for (auto &[nei,cost]:g[0])
        if (!st[nei]&&d[nei]>cost){
            d[nei]=cost;
            h.emplace(d[nei],nei);
        }
    while (!h.empty()){
        auto [val,cur]=h.top();
        h.pop();
        if (st[cur])
            continue;
        st[cur]=true;
        res+=val;
        tot++;
        for (auto &[nei,cost]:g[cur])
            if (!st[nei]&&d[nei]>cost){
                d[nei]=cost;
                h.emplace(d[nei],nei);
            }                
    }   
    return tot==n?res:INF;
}
int main(){
    scanf("%d%d",&n,&m);
    while (m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        a--,b--;
        if (g[a].count(b))
            g[a][b]=g[b][a]=min(g[a][b],c);
        else
            g[a][b]=g[b][a]=c;
    }
    int t=prim();
    if (t==INF) puts("impossible");
    else printf("%d\n",t);
    return 0;
}