//floyd
#include<iostream>
#include<cstring>
using namespace std;
const int N=201,null=0x3f3f3f3f;
int g[N][N];
int main(){
    int n,m,k,a,b,c;
    cin>>n>>m>>k;
    memset(g,0x3f,sizeof g);
    for (int i=1;i<=m;i++){
        cin>>a>>b>>c;
        g[a][b]=min(g[a][b],c);
    }
    for (int i=1;i<=n;i++)
        g[i][i]=0;
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (g[i][k]!=null&&g[k][j]!=null&&g[i][k]+g[k][j]<g[i][j])
                    g[i][j]=g[i][k]+g[k][j];
    for (int i=1;i<=k;i++){
        cin>>a>>b;
        if (g[a][b]==null)
            cout<<"impossible"<<endl;
        else
            cout<<g[a][b]<<endl;
    }
    return 0;
}