#include<iostream>
using namespace std;
int m,n,x,y;
bool g[9][9];
int dx[]={-2,-2,-1,-1,1,1,2,2};
int dy[]={-1,1,-2,2,-2,2,-1,1};
int dfs(int x,int y,int step){
    g[x][y]=1;
    int count=0;
    for (int i=0;i<8;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if (nx<0||nx>=m||ny<0||ny>=n||g[nx][ny]) continue;
        if (step+1==m*n) count++;
        else
            count+=dfs(nx,ny,step+1);
    }
    g[x][y]=0;
    return count;
}
int main(){
    int t;
    cin>>t;
    while (t--){
        cin>>m>>n>>x>>y;
        cout<<dfs(x,y,1)<<endl;
    }
}