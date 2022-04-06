//O(n*n^1/2)
#include<iostream>
#include<cstring>
using namespace std;
const int N=50010,M=N*2;
int e[M],ne[M],ha[N],idx;
int ans;
int solve(int x){
    int r=1;
    for (int i=2;i*i<=x;i++)
        if (x%i==0){
            r+=i;
            if (i*i!=x)
                r+=x/i;
        }
    return r;
}
void add(int a,int b){
    e[idx]=b,ne[idx]=ha[a],ha[a]=idx++;
}
int dfs(int u,int fa){
    int dist=0;
    int d1=0,d2=0;
    for (int i=ha[u];i!=-1;i=ne[i]){
        int j=e[i];
        if (j==fa) continue;
        int d=dfs(j,u)+1;
        dist=max(dist,d);
        if (d>=d1){
            d2=d1,d1=d;
        }
        else if (d>d2)
            d2=d;
    }
    ans=max(ans,d1+d2);
    return dist;
}
int main(){
    int n,a;
    memset(ha,-1,sizeof ha);
    cin>>n;
    for (int i=2;i<=n;i++){
        a=solve(i);
        if (a<i){
            add(a,i);
            add(i,a);
        }
    }
    dfs(1,-1);
    cout<<ans<<endl;
    return 0;
}