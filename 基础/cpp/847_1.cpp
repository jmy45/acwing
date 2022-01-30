#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int n,m,a,b;
    cin>>n>>m;
    vector<vector<int>> g(n);
    vector<int> visited(n);
    for (int i=0;i<m;i++){
        cin>>a>>b;
        g[a-1].push_back(b-1);
    }
    //1号到n号的最短距离
    queue<int> q;
    q.push(0);
    visited[0]=1;
    int dis=0;
    if (n==1) {
        cout<<dis<<endl;
        return 0;
    }
    while (!q.empty()){
        int l=q.size();
        dis++;
        for (int i=0;i<l;i++){
            int x=q.front();
            q.pop();
            for (int nei:g[x]){
                if (nei==n-1){
                    cout<<dis<<endl;
                    return 0;
                }
                if (!visited[nei]){
                    q.push(nei);
                    visited[nei]=1;
                }
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}