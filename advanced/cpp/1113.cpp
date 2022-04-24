#include<iostream>
using namespace std;
const int N=30;
char g[N][N];
int x,y,h,w;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int dfs(int x,int y){
    if (x<0||x>=h||y<0||y>=w||g[x][y]=='#') return 0;
    g[x][y]='#';
    int count=1;
    for (int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        count+=dfs(nx,ny);
    }
    return count;
}
int main(){
    while (cin>>w>>h,w||h){
        for (int i=0;i<h;i++)
            for (int j=0;j<w;j++){
                cin>>g[i][j];
                if (g[i][j]=='@')
                {
                    x=i;
                    y=j;
                }
            }
        cout<<dfs(x,y)<<endl;        
    }
    return 0;
}