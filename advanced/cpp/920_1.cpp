#include<iostream>
#include<cstring>
#include<sstream>
#include<queue>
#include<tuple>
using namespace std;
typedef tuple<int,int,int> PIII;
int m,n;
const int N=510,M=100*500,INF=0x3f3f3f3f;
int e[M],w[M],ne[M],h[N],idx;
int dist[N];
bool st[501][101];
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
void spfa(){
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    queue<PIII> q;
    q.emplace(0,1,100);
    st[1][100]=true;
    while (q.size()){
        auto [d,u,line]=q.front();
        q.pop();
        if (d>dist[u]) continue;
        st[u][line]=false;
        for (int i=h[u];~i;i=ne[i]){
            int j=e[i];
            if (dist[j]>=dist[u]+(line==100?0:(w[i]!=line))){
                dist[j]=dist[u]+(line==100?0:(w[i]!=line));
                if (!st[j][w[i]]){
                    q.emplace(dist[j],j,w[i]);
                    st[j][w[i]]=true;
                }
            }
        }
    }
}
int main(){
    memset(h,-1,sizeof(h));
    cin>>m>>n;
    cin.get();
    for (int i=0;i<m;i++){
        string s;
        getline(cin,s);
        stringstream ss(s);
        int x,y;
        ss>>x;
        while (ss>>y){
            add(x,y,i);
            x=y;
        }
    }
    spfa();
    if (dist[n]==INF) puts("NO");
    else printf("%d\n",dist[n]);
    return 0;
}