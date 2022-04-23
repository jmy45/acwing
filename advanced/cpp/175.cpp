#include<iostream>
#include<cstring>
#include<algorithm>
#include<deque>
#define x first
#define y second
using namespace std;
typedef pair<int,int> PII;
const int N=510,M=N*N;
int n,m;
char g[N][N];
PII q[M];
int dist[N][N];
bool st[N][N];
int bfs(){
    deque<PII> q;
    memset(st,0,sizeof(st));
    memset(dist,0x3f,sizeof(dist));
    char cs[5]="\\/\\/";
    int dx[4]={-1,-1,1,1},dy[4]={-1,1,1,-1};
    int ix[4]={-1,-1,0,0},iy[4]={-1,0,0,-1};
    q.push_back({0,0});
    dist[0][0]=0;
    while (q.size()){
        auto t=q.front();
        q.pop_front();
        int x=t.x,y=t.y;
        if (x==n&&y==m) return dist[x][y];
        if (st[x][y]) continue;
        st[x][y]=1;
        for (int i=0;i<4;i++){
            int a=x+dx[i],b=y+dy[i];
            if (a<0||a>n||b<0||b>m) continue;
            int ga=x+ix[i],gb=y+iy[i];
            int w=g[ga][gb]!=cs[i];
            int d=dist[x][y]+w;
            if (d<=dist[a][b]){
                dist[a][b]=d;
                if (!w) q.push_front({a,b});
                else q.push_back({a,b});
            }
        }
    }
    return -1;
}
int main(){
    int T;
    scanf("%d",&T);
    while (T--){
        scanf("%d%d",&n,&m);
        for (int i=0;i<n;i++) scanf("%s",g[i]);
        if (n+m&1) puts("NO SOLUTION");
        else printf("%d\n",bfs());
    }
    return 0;
}