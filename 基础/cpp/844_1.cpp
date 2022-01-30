#include<iostream>
using namespace std;
const int N=110;
int a[N][N],b[12100];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    int hh=0,tt=-1,step=0;
    if (n==1&&m==1){
        printf("%d",step);
        return 0;
    }
    b[++tt]=m+2;
    a[1][1]=1;
    while (hh<=tt){
        int l=tt-hh+1;
        step++;
        for (int j=0;j<l;j++){
            int cur=b[hh++];
            int x=cur/(m+1),y=cur%(m+1);
            for (int i=0;i<4;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if (nx==n&&ny==m){
                    printf("%d",step);
                    return 0;
                }
                if (nx>=1&&nx<=n&&ny>=1&&ny<=m&&!a[nx][ny]){
                    b[++tt]=nx*(m+1)+ny;
                    a[nx][ny]=1;
                }
            }
        }
    }
    return 0;
}