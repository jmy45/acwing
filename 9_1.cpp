#include<iostream>
#include<vector>
using namespace std;

int main(){
    //n组
    int n,v,rows,x,y,idx=0;
    vector<vector<int>>g(110);
    vector<int> volume(10010),price(10010);
    cin>>n>>v;
    for (int i=1;i<=n;i++){
        cin>>rows;
        for (int j=0;j<rows;j++){
            cin>>x>>y;
            volume[idx]=x;
            price[idx]=y;
            g[i].push_back(idx);
            idx++;
        }
    }
    vector<vector<int>> dp(n+1,vector<int>(v+1));
    for (int i=1;i<=n;i++)
        for (int j=0;j<=v;j++){
            dp[i][j]=dp[i-1][j];
            for (auto k:g[i])
                if (j>=volume[k])
                    dp[i][j]=max(dp[i][j],dp[i-1][j-volume[k]]+price[k]);
        }
    cout<<dp[n][v]<<endl;
    return 0;
}