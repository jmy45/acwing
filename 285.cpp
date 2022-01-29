#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=6010;
int n;
int w[N];
int h[N],e[N],ne[N],idx;
bool st[N];
int f[N][2];
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void dfs(int u){
    f[u][1]=w[u];
    for (int i=h[u];~i;i=ne[i]){
        int j=e[i];
        dfs(j);
        f[u][0]+=max(f[j][0],f[j][1]);
        f[u][1]+=f[j][0];
    }
}
int main(){
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>w[i];
    memset(h,-1,sizeof h);
    for (int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        add(b,a);
        st[a]=true;
    }
    int root=1;
    while (st[root]) root++;
    dfs(root);
    cout<<max(f[root][0],f[root][1])<<endl;
    return 0;
}