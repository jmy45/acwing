#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=110,M=N*2;
int n,m;
int h[N],e[M],w[M],ne[M],idx;
int f[N][N];
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
void dfs(int u,int fa){
    for (int i=h[u];~i;i=ne[i]){//物品组
        if (e[i]==fa) continue;
        dfs(e[i],u);
        for (int j=m;j>=0;j--)//体积
            for (int k=0;k<j;k++)//决策
                f[u][j]=max(f[u][j],f[u][j-k-1]+f[e[i]][k]+w[i]);
    }
}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for (int i=0;i<n-1;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);
    }
    dfs(1,-1);
    cout<<f[1][m]<<endl;
    return 0;
}