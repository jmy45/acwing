#include<iostream>
#include<vector>
using namespace std;
typedef pair<int,vector<int>> PII;
int a[30];
PII dp[30][30];
PII dfs(int l,int r){
    if (l>r) return PII(1,vector<int>());
    else if (l==r) return PII(a[l],vector<int>({l}));
    if (dp[l][r].first)
        return dp[l][r];
    int score=0;
    vector<int> res;
    for (int k=l;k<=r;k++){
        auto [s1,v1]=dfs(l,k-1);
        auto [s2,v2]=dfs(k+1,r);
        if (s1*s2+a[k]>score){
            score=s1*s2+a[k];
            res={k};
            for (int e:v1)
                res.push_back(e);
            for (int e:v2)
                res.push_back(e);
        }
    }
    dp[l][r]=PII(score,res);
    return dp[l][r];
}
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    auto [score,res]=dfs(1,n);
    cout<<score<<endl;
    for (int e:res)
        cout<<e<<" ";
    return 0;
}