#include<iostream>
#include<vector>
using namespace std;
int ans,s;
int m,n;
int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};
int dfs(int x,int y,vector<vector<int>>&a,vector<vector<int>>&visited){
    if (x<0||x>=m||y<0||y>=n||visited[x][y]) return 0;
    visited[x][y]=1;
    int cnt=1;
    for (int i=0;i<4;i++)
        if (!(a[x][y]>>i&1)){
            int nx=x+dx[i],ny=y+dy[i];
            cnt+=dfs(nx,ny,a,visited);
        }
    return cnt;
}
int main(){
    cin>>m>>n;
    vector<vector<int>> a(m,vector<int>(n));
    vector<vector<int>> visited(m,vector<int>(n));
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
            cin>>a[i][j];
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
            if (!visited[i][j]){
                ans++;
                s=max(s,dfs(i,j,a,visited));
            }
    cout<<ans<<endl<<s<<endl;
    return 0;
}