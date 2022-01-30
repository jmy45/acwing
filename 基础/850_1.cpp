//2s!!!
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
using PII=pair<int,int>;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,a,b,c;
    cin>>n>>m;
    vector<unordered_map<int,int>> g(n);
    for (int i=0;i<m;i++){
        cin>>a>>b>>c;
        if (g[a-1].count(b-1))
            g[a-1][b-1]=min(g[a-1][b-1],c);
        else
            g[a-1][b-1]=c;
    }
    priority_queue<PII,vector<PII>,greater<PII>> h;
    vector<int> d(n,0x3f3f3f3f);
    d[0]=0;
    h.emplace(d[0],0);
    while (!h.empty()){
        auto [dist,cur]=h.top();
        h.pop();
        if (dist>d[cur])
            continue;
        for (auto &[nei,cost]:g[cur])
            if (d[nei]>dist+cost){
                d[nei]=dist+cost;
                h.emplace(d[nei],nei);
            }
    }
    if (d[n-1]==0x3f3f3f3f)
        cout<<-1<<endl;
    else
        cout<<d[n-1]<<endl;
    return 0;
}
