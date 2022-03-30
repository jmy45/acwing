#include<iostream>
#include<vector>
#include<hash_map>
using namespace __gnu_cxx;
using namespace std;
typedef pair<int,int> PII;
int g[105];
int main(){
    int n,m;
    cin>>n>>m;
    char c;
    for (int i=2;i<n+2;i++) 
        for (int j=0;j<m;j++){
            cin>>c;
            g[i]|=!(c=='P')<<j;
        }
    vector<int> valid;
    for (int i=0;i<1<<m;i++)
        if ((i>>1&i)==0&&(i>>2&i)==0)
            valid.push_back(i);
    hash_map<int,int> count;
    for (auto i:valid)
        count[i]=__builtin_popcount(i);
    int l=valid.size();
    int p,q,r;
    /*
    function<size_t(const PII&)> hfunc=[](const PII& p)->size_t{
    static hash<int> hashll;
    return hashll(p.first+(p.second<<10));
    };
    unordered_map<PII,int,decltype(hfunc)> dp(0,hfunc);
    unordered_map<PII,vector<int>,decltype(hfunc)> um(0,hfunc);*/
    hash_map<int,int> dp;
    hash_map<int,vector<int>> um;
    for (int i=0;i<l;i++)
        for (int j=0;j<l;j++){
            p=valid[i],q=valid[j];
            if (p&q) continue;
            for (int k=0;k<l;k++){
                r=valid[k];
                if ((p&r)|(q&r)) continue;
                //um[make_pair(p,q)].push_back(r);
                um[p<<10|q].push_back(r);
            }
        }
    //dp[make_pair(0,0)]=0;
    dp[0]=0;
    for (int i=2;i<=n+3;i++){
        //unordered_map<PII,int,decltype(hfunc)> dp2(0,hfunc);
        hash_map<int,int> dp2;
        for (auto &[p2,v]:dp){
            //auto &[p,q]=p2;
            int p=p2>>10,q=p2&1023;
            for (int &r:um[p2]){
                if (r&g[i]) continue;
                //int &t=dp2[make_pair(q,r)];
                int &t=dp2[q<<10|r];
                t=max(t,v+count[r]);
            }
        }
        dp=dp2;
    }
    //cout<<dp[make_pair(0,0)]<<endl;
    cout<<dp[0]<<endl;
    return 0;
}