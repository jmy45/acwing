//dfs MLE
#include<iostream>
#include<vector>
using namespace std;
typedef pair<int,int> PII;
int val,peaks,valleys,n,no;
bool p;
PII q[1000005];
vector<vector<int>>arr,visited;
int bfs(int sx,int sy){
    int hh=0,tt=0;
    q[0]={sx,sy};
    visited[sx][sy]=no;
    int r=-1;
    while (hh<=tt){
        auto [x,y]=q[hh++];
        for (int i=x-1;i<=x+1;i++)
            for (int j=y-1;j<=y+1;j++)
                if (i!=x||j!=y)
                {
                    if (i<0||i>=n||j<0||j>=n) continue;
                    if (visited[i][j]==no) continue;
                    if (arr[i][j]<val) {
                        if (r==0) return 2;
                        r=1;
                        continue;
                    }
                    if (arr[i][j]>val) {
                        if (r==1) return 2;
                        r=0;
                        continue;
                    }
                    q[++tt]={i,j};
                    visited[i][j]=no;
                }
    }
    return r;
}
int main(){
    cin>>n;
    arr.assign(n,vector<int>(n));
    visited.assign(n,vector<int>(n));
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cin>>arr[i][j];
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            if (!visited[i][j]){
                val=arr[i][j];
                no++;
                int r=bfs(i,j);
                if (r==-1){
                    peaks=valleys=1;
                    break;
                }
                if (r==1) peaks++;
                if (r==0) valleys++;
            }
    cout<<peaks<<" "<<valleys<<endl;
    return 0;
}