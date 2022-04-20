#include<iostream>
using namespace std;
const int N=1010;
int w[N][N],v1[N][N],v2[N][N];
int q[100000],p[100000];
int hh,tt,h,t;
int main(){
    int a,b,n;
    scanf("%d%d%d",&a,&b,&n);
    for (int i=0;i<a;i++)
        for (int j=0;j<b;j++)
            scanf("%d",&w[i][j]);
    for (int j=0;j<b;j++){
        int hh=0,tt=-1,h=0,t=-1;
        for (int i=0;i<a;i++){
            if (hh<=tt&&i-q[hh]/b>=n) hh++;
            while (hh<=tt&&w[i][j]<=w[q[tt]/b][q[tt]%b]) tt--;
            q[++tt]=i*b+j;
            v1[i][j]=q[hh];
            if (h<=t&&i-p[h]/b>=n) h++;
            while (h<=t&&w[i][j]>=w[p[t]/b][p[t]%b]) t--;
            p[++t]=i*b+j;
            v2[i][j]=p[h];
        }
    }
    int ans=0x3f3f3f3f;
    int x,y,xx,yy;
    for (int i=0;i<=a-n;i++){
        hh=0,tt=-1,h=0,t=-1;
        for (int j=0;j<b;j++){
            while (hh<=tt&&j-q[hh]%b>=n) hh++;
            while (h<=t&&j-p[h]%b>=n) h++;
            while (hh<=tt&&w[v1[i+n-1][j]/b][v1[i+n-1][j]%b]<=w[q[tt]/b][q[tt]%b]) tt--;
            q[++tt]=v1[i+n-1][j];
            while (h<=t&&w[v2[i+n-1][j]/b][v2[i+n-1][j]%b]>=w[p[t]/b][p[t]%b]) t--;
            p[++t]=v2[i+n-1][j];
            if (j>=n-1){
                x=q[hh]/b,y=q[hh]%b;
                xx=p[h]/b,yy=p[h]%b;
                ans=min(ans,w[xx][yy]-w[x][y]);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}