#include<iostream>
using namespace std;
const int N=9;
int n,m;
bool st[N][N];
int ans;
int dx[]={-2,-2,-1,-1,1,1,2,2};
int dy[]={-1,1,-2,2,-2,2,-1,1};
void dfs(int x,int y,int cnt){
    if (cnt==n*m){
        ans++;
        return;
    }
    st[x][y]=true;
    for (int i=0;i<8;i++){
        int a=x+dx[i],b=y+dy[i];
        if (a<0||a>=n||b<0||b>=m||st[a][b]) continue;
        dfs(a,b,cnt+1);
    }
    st[x][y]=false;
}
int main(){
    int T;
    cin>>T;
    while (T--){
        int x,y;
        cin>>n>>m>>x>>y;
        ans=0;
        dfs(x,y,1);
        printf("%d\n",ans);
    }
    return 0;
}