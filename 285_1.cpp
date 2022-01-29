#include<iostream>
#include<unordered_map>
#include<vector>
#include<cstring>
using namespace std;
const int N=6010,M=-1e7;
int p[N],h[N],visited[N];
unordered_map<int,vector<int>> m;
int dfs(int cur){
    int x=0,y=h[cur];
    if (visited[cur]!=M) return visited[cur];
    for (auto child:m[cur]){
        x+=dfs(child);
        for (auto ch:m[child])
            y+=dfs(ch);
    }
    return visited[cur]=max(x,y);
}
int main(){
    int n,a,b;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>h[i];
        visited[i]=M;
    }
    for (int i=1;i<=n-1;i++){
        cin>>a>>b;
        p[a]=b;
        m[b].push_back(a);
    }
    for (int i=1;i<=n;i++)
        if (!p[i]){
            cout<<dfs(i)<<endl;
            break;
        }
    return 0;
}