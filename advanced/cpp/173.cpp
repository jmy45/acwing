#include<iostream>
using namespace std;
typedef pair<int,int> PII;
int a[1010][1010],b[1010][1010];
PII q[1000001];
int main(){
    int n,m;
    char ch;
    int hh=0,tt=-1;
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++){
            cin>>ch;
            a[i][j]=ch-'0';
            if (a[i][j])
                q[++tt]={i,j};
        }
    int dx[]={-1,0,0,1};
    int dy[]={0,-1,1,0};
    while (hh<=tt){
        auto [x,y]=q[hh++];
        for (int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if (nx<0||nx>=n||ny<0||ny>=m) continue;
            if (!a[nx][ny]){
                a[nx][ny]=1;
                q[++tt]={nx,ny};
                b[nx][ny]=b[x][y]+1;
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m-1;j++)
            printf("%d ",b[i][j]);
        printf("%d\n",b[i][m-1]);
    }
    return 0;
}