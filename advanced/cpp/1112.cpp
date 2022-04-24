#include<iostream>
using namespace std;
const int N=110;
char g[N][N];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int n,x1,x2,y1,y2;
bool dfs(int x,int y){
    if (x<0||x>=n||y<0||y>=n||g[x][y]=='#') return false;
    if (x==x2&&y==y2) return true;
    g[x][y]='#';
    bool r=false;
    for (int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        r|=dfs(nx,ny);
    }
    return r;
}
int main(){
    int k;
    scanf("%d",&k);
    while (k--){
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            scanf("%s",g[i]);
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if (dfs(x1,y1))
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}