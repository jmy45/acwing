#include<iostream>
#include<math.h>
using namespace std;
int a[9][9],p[9][9];
double v[15][9][9][9][9];
double average;
double calc(int x0,int y0,int x1,int y1){
    double r=p[x1][y1]-p[x1][y0-1]-p[x0-1][y1]+p[x0-1][y0-1]-average;
    return r*r;
}
double dfs(int k,int x0,int y0,int x1,int y1){
    if (!k)
        return calc(x0,y0,x1,y1);
    if (v[k][x0][y0][x1][y1])
        return v[k][x0][y0][x1][y1];
    double ans=1e9;
    for (int i=x0;i<x1;i++){
        //x0,y0,i,y1
        ans=min(ans,calc(x0,y0,i,y1)+dfs(k-1,i+1,y0,x1,y1));
        ans=min(ans,calc(i+1,y0,x1,y1)+dfs(k-1,x0,y0,i,y1));
    }
    for (int j=y0;j<y1;j++){
        //x0,y0,x1,j
        ans=min(ans,calc(x0,y0,x1,j)+dfs(k-1,x0,j+1,x1,y1));
        ans=min(ans,calc(x0,j+1,x1,y1)+dfs(k-1,x0,y0,x1,j));
    }
    return v[k][x0][y0][x1][y1]=ans;
}
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=8;i++)
        for (int j=1;j<=8;j++){
            cin>>a[i][j];
            average+=a[i][j];
            p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+a[i][j];
        }
    average/=n;
    printf("%.3lf\n",sqrt(dfs(n-1,1,1,8,8)/n));
    return 0;
}