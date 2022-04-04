#include<iostream>
#include<unordered_map>
using namespace std;
typedef pair<int,int> PII;
unordered_map<int,unordered_map<int,int>> nei;
int ans;
PII dfs(int r,int p){
    int a=-1e9,b=-1e9;
    for (auto& [k,v]:nei[r]){
        if (k!=p){
            auto [c,d]=dfs(k,r);
            c+=v;
            if (c>a) {
                b=a;
                a=c;
            }
            else if (c>b) b=c;
        }
    }
    int t=a+b>a?a+b:a;
    ans=max(ans,t);
    if (a==-1e9) return {0,0};
    return {a,b};
}
int main(){
    int n,a,b,c;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a>>b>>c;
        nei[a][b]=c;
        nei[b][a]=c;
    }
    dfs(1,0);
    cout<<ans<<endl;
    return 0;
}