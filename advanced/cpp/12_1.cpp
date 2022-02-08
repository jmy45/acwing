#include<iostream>
#include<vector>
using namespace std;
int dp[1010],ans[1010];
bool cmp(vector<int>&a,vector<int>&b){
    int t=min(a.size(),b.size());
    for (int i=0;i<t;i++)
        if (a[i]<b[i])
            return true;
        else if (a[i]>b[i])
            return false;
    return a.size()>b.size();
}
int main(){
    int N,V;
    cin>>N>>V;
    vector<vector<int>> p(1010),q(1010);
    for (int i=1;i<=N;i++){
        int v,w;
        cin>>v>>w;
        q=p;
        for (int j=V;j>=v;j--)
            if (dp[j-v]+w>dp[j]||(dp[j-v]+w==dp[j]&&cmp(q[j-v],p[j]))){
                dp[j]=dp[j-v]+w;
                p[j]=q[j-v];
                p[j].push_back(i);
            }
    }
    for (auto &e:p[V])
        cout<<e<<" ";
    return 0;
}