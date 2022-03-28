#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int a[13][13];
const int mod=1e8;
int main(){
    int m,n;
    cin>>m>>n;
    for (int i=1;i<=m;i++)
        for (int j=0;j<n;j++)
            cin>>a[i][j];
    for (int j=0;j<n;j++)
        a[m+1][j]=1;
    vector<int> valid;
    for (int i=0;i<1<<n;i++)
        if ((i>>1&i)==0)
            valid.push_back(i);
    int l=valid.size();
    unordered_map<int,vector<int>> um;
    int p,q;
    for (int i=0;i<l;i++)
        for (int j=0;j<l;j++){
            p=valid[i],q=valid[j];
            if ((p&q)==0)
                um[p].push_back(q);
        }
    unordered_map<int,int> dp;
    dp[0]=1;
    for (int i=1;i<=m+1;i++){
        unordered_map<int,int> d2;
        for (auto &[p,v]:dp)
            for (int q:um[p]){
                bool f=true;
                for (int k=0;k<n;k++)
                    if ((q>>k&1)&&a[i][k]==0)
                        f=false;
                if (f)
                    d2[q]=(d2[q]+v)%mod;
        }
        dp=d2;
    }
    cout<<dp[0]<<endl;
    return 0;
}