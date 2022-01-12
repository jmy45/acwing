#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int n,m,a,b;
    cin>>n>>m;
    vector<int> deg(n);
    vector<vector<int>> g(n);
    for (int i=0;i<m;i++){
        cin>>a>>b;
        deg[b-1]++;
        g[a-1].push_back(b-1);
    }
    queue<int> q;
    for (int i=0;i<n;i++)
        if (deg[i]==0)
            q.push(i);
    vector<int> ans;
    while (!q.empty()){
        int x=q.front();
        q.pop();
        ans.push_back(x+1);
        for (int nei:g[x]){
            deg[nei]--;
            if (deg[nei]==0)
                q.push(nei);
        }
    }
    if (ans.size()!=n){
        cout<<-1<<endl;
        return 0;
    }
    for (int e:ans)
        cout<<e<<' ';
    cout<<endl;
    return 0;
}