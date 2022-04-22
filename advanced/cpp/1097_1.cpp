#include<iostream>
#include<vector>
using namespace std;
int n,m;
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,1,-1,0,1,-1};
int ans;
void dfs(int x,int y,vector<vector<char>>&a){
    if (x<0||x>=n||y<0||y>=m||a[x][y]=='.') return;
    a[x][y]='.';
    for (int i=0;i<8;i++){
        int nx=x+dx[i],ny=y+dy[i];
        dfs(nx,ny,a);
    }
}
int main(){
    cin>>n>>m;
    vector<vector<char>> a(n,vector<char>(m));
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin>>a[i][j];
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (a[i][j]=='W'){
                ans++;
                dfs(i,j,a);
            }
    cout<<ans<<endl;
    return 0;
}