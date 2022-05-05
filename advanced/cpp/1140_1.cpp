#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<int,int> PII;
const int N=110;
int g[N][N];
int n;
int dist[N];
bool st[N];
int prim(int start){
    memset(dist,0x3f,sizeof dist);
    dist[start]=0;
    int tot=0;
    priority_queue<PII,vector<PII>,greater<>> heap;
    heap.push({0,start});
    while (heap.size()){
        auto [d,u]=heap.top();
        heap.pop();
        if (st[u]) continue;
        tot+=d;
        st[u]=true;
        for (int i=1;i<=n;i++)
            if (!st[i]&&g[u][i]&&g[u][i]<dist[i]){
                dist[i]=g[u][i];
                heap.push({dist[i],i});
            }
    }
    return tot;
}
int main(){
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cin>>g[i][j];
    cout<<prim(1)<<endl;
    return 0;
}