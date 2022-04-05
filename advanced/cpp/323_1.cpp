#include<iostream>
#include<cstring>
using namespace std;
const int N=1510,M=N,INF=0x3f3f3f3f;
int e[M],ne[M],ha[M],idx;
int arr[N];
int vis[N][2];
void add(int a,int b){
    e[idx]=b,ne[idx]=ha[a],ha[a]=idx++;
}
int dfs(int root,int p){
    int &ans=vis[root][p];
    if (ans!=INF) return ans;
    int t=1;
    for (int i=ha[root];~i;i=ne[i]){
        int j=e[i];
        t+=dfs(j,0);
    }
    ans=min(ans,t);
    if (!p){
        t=0;
        for (int i=ha[root];~i;i=ne[i]){
            int j=e[i];
            t+=dfs(j,1);
        }
        ans=min(ans,t);
    }
    return ans;
}
int main(){
    int n,a,m,b;
    char ch;
    while (cin>>n){
        idx=0;
        memset(vis,INF,sizeof vis);
        memset(ha,-1,sizeof ha);
        memset(arr,0,sizeof arr);
        for (int i=0;i<n;i++){
            cin>>a;
            cin>>ch>>ch;
            cin>>m;
            cin>>ch;
            for (int j=0;j<m;j++){
                cin>>b;
                add(a,b);
                arr[b]=1;
            }
        }
        for (int i=0;i<n;i++)
            if (!arr[i]){
                cout<<dfs(i,0)<<endl;
                break;
            }
    }
    return 0;
}