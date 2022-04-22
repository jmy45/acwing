#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
const int N=1010,M=N*N;
int arr[N][N],p[N][N],n;
PII q[M];
void bfs(int x,int y){
    int hh=0,tt=0;
    q[0]={x,y};
    int dx[]={-1,0,0,1};
    int dy[]={0,-1,1,0};
    while (hh<=tt){
        auto [cx,cy]=q[hh++];
        for (int i=0;i<4;i++){
            int nx=cx+dx[i],ny=cy+dy[i];
            if (nx<0||nx>=n||ny<0||ny>=n||arr[nx][ny]) continue;
            if (!p[nx][ny]){
                p[nx][ny]=i+1;
                q[++tt]={nx,ny};
            }
        }       
    }
}
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            scanf("%d",&arr[i][j]);
    bfs(0,0);
    int x=n-1,y=n-1;
    vector<PII> ans;
    while (x||y){
        ans.emplace_back(x,y);
        if (p[x][y]==2) y++;
        else if (p[x][y]==3) y--;
        else if (p[x][y]==4) x--;
        else x++;
    }
    ans.emplace_back(0,0);
    reverse(ans.begin(),ans.end());
    for (auto [x,y]:ans)
        printf("%d %d\n",x,y);
    return 0;
}