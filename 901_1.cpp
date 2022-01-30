#include<iostream>
using namespace std;
const int N=310;
int a[N][N],b[N][N];
int dx[]={-1,0,0,1},dy[]={0,-1,1,0};
int r,c;
void dfs(int x,int y){
    if (b[x][y])
        return;
    int value=0;
    for (int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if (nx>=0&&nx<r&&ny>=0&&ny<c&&a[nx][ny]<a[x][y]){
            dfs(nx,ny);
            value=max(value,b[nx][ny]);
        }
    }
    b[x][y]=value+1;
}
int main(){
    cin>>r>>c;
    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++)
            cin>>a[i][j];
    int ans=0;
    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++){
            dfs(i,j);
            ans=max(ans,b[i][j]);
    }
    cout<<ans<<endl;
    return 0;
}