//dijkstra求最短路，存在重边，自环，边权为正
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    int n,m,a,b,c;
    cin>>n>>m;
    vector<unordered_map<int,int>> g(n);
    for (int i=0;i<m;i++){
        cin>>a>>b>>c;
        //存在重边
        if (g[a-1].count(b-1))
            g[a-1][b-1]=min(g[a-1][b-1],c);
        else
            g[a-1][b-1]=c;
    }
    vector<int> d(n,0x3f3f3f3f);
    vector<int> visited(n);
    d[0]=0;
    int i=0;
    for (;i<=n-1;i++){
        int t=-1,v=0x3f3f3f3f;
        for (int j=0;j<n;j++)
            if (!visited[j]&&d[j]<v){
                t=j;
                v=d[j];
            }
        if (t==-1) break;
        for (auto &[nei,val]:g[t])
            if (d[t]+val<d[nei])
                d[nei]=d[t]+val;
        visited[t]=1;
    }
    if (i==n)
        cout<<d[n-1]<<endl;
    else 
        cout<<-1<<endl;
    return 0;
}
