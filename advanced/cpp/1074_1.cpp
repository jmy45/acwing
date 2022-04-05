#include<iostream>
#include<cstring>
using namespace std;
const int M=220,INF=1e9;
int ne[M],w[M],ha[M],e[M],idx;
int vis[M][30010];
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=ha[a],ha[a]=idx++;
}
int dfs(int root,int fa,int remain){
    int &ans=vis[root][remain];
    if (ans) return ans;
    int child[2]={-1,-1};
    int wei[2];
    int p=0;
    for (int i=ha[root];i!=-1;i=ne[i]){
        int j=e[i];
        if (j==fa) continue;
        child[p]=j;
        wei[p]=w[i];
        p++;
    }
    if (child[0]==-1){
        if (remain)
            return -INF;
        else
            return 0;
    }
    for (int i=0;i<=remain;i++){
        int t=0;
        if (i)
            t+=dfs(child[0],root,i-1)+wei[0];
        if (remain-i)
            t+=dfs(child[1],root,remain-1-i)+wei[1];
        ans=max(ans,t);
        t=0;
        if (remain-i)
            t+=dfs(child[0],root,remain-1-i)+wei[0];
        if (i)
            t+=dfs(child[1],root,i-1)+wei[1];
        ans=max(ans,t);
    }
    return ans;
}
int main(){
    int n,t,a,b,c;
    memset(ha,-1,sizeof(ha));
    cin>>n>>t;
    for (int i=0;i<n-1;i++){
        cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);
    }
    cout<<dfs(1,-1,t)<<endl;
    return 0;
}