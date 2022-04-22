#include<iostream>
#include<vector>
using namespace std;
const int M=150*150;
typedef pair<int,int> PII;
vector<vector<char>> g;
int c,r,x,y;
PII q[M];
int bfs(int sx,int sy){
    int hh=0,tt=0;
    q[0]={sx,sy};
    g[sx][sy]='V';
    int dx[]={-2,-2,-1,-1,1,1,2,2};
    int dy[]={-1,1,-2,2,-2,2,-1,1};
    int ans=0;
    while (hh<=tt){
        int l=tt-hh+1;
        ans++;
        for (int i=0;i<l;i++){
            auto [x,y]=q[hh++];
            for (int i=0;i<8;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if (nx<0||nx>=r||ny<0||ny>=c||g[nx][ny]=='*') continue;
                if (g[nx][ny]=='V') continue;
                if (g[nx][ny]=='H') return ans;
                q[++tt]={nx,ny};
                g[nx][ny]='V';
            }
        }
    }
    return ans;
}
int main(){
    cin>>c>>r;
    g.assign(r,vector<char>(c));
    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++){
            cin>>g[i][j];
            if (g[i][j]=='K'){
                x=i;
                y=j;
            }
        }
    cout<<bfs(x,y)<<endl;
    return 0;
}