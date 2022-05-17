#include<iostream>
#include<cstring>
using namespace std;
const int N=110,M=N*N;
int e[M],ne[M],h[N],idx,ans,cnt;
int dfn[N],low[N],timestamp;
int stk[N],top;
bool in_stk[N];
int id[N],sz[N],dout[N],din[N],scc_cnt;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void tarjan(int u){
    dfn[u]=low[u]=++timestamp;
    stk[++top]=u,in_stk[u]=true;
    for (int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if (!dfn[j]){
            tarjan(j);
            low[u]=min(low[u],low[j]);
        }
        else if (in_stk[j]) low[u]=min(low[u],dfn[j]);
    }
    if (dfn[u]==low[u]){
        ++scc_cnt;
        int y;
        do{
            y=stk[top--];
            in_stk[y]=false;
            id[y]=scc_cnt;
            sz[scc_cnt]++;
        }while (y!=u);
    }
}
int main(){
    memset(h,-1,sizeof h);
    int n,b;
    cin>>n;
    for (int i=1;i<=n;i++){
        while (cin>>b,b){
            add(i,b);
        }
    }
    for (int i=1;i<=n;i++)
        if (!dfn[i])
            tarjan(i);
    for (int i=1;i<=n;i++)
        for (int j=h[i];~j;j=ne[j]){
            int k=e[j];
            int a=id[i],b=id[k];
            if (a!=b) {
                dout[a]++;
                din[b]++;
            }
        }
    for (int i=1;i<=scc_cnt;i++)
        if (!din[i])
            cnt++;
    for (int i=1;i<=scc_cnt;i++)
        if (!dout[i])
            ans++;  
    cout<<cnt<<endl;
    if (scc_cnt==1)
        cout<<0<<endl;
    else
        cout<<max(ans,cnt)<<endl;
    return 0;
}