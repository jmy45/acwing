#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> valid;
    unordered_map<int,unordered_map<int,long long>> a;
    int cnt;
    for (int cur=0;cur<1<<n;cur++){
        if ((cur<<1&cur)==0&&(cur>>1&cur)==0){
            cnt=__builtin_popcount(cur);
            if (cnt<=k)
                valid.push_back(cur);
                a[cur][cnt]=1;
        }
    }
    int l=valid.size();
    int p,q;
    unordered_map<int,vector<int>> m;
    for (int i=0;i<l;i++)
        for (int j=0;j<l;j++)
        {
            p=valid[i],q=valid[j];
            if ((p&q)==0&&(p>>1&q)==0&&(p<<1&q)==0){
                m[p].push_back(q);
            }
        }
    for (int i=2;i<=n;i++){
        unordered_map<int,unordered_map<int,long long>> b;
        for (int j=0;j<=k;j++)
            for (int t=0;t<l;t++){
                p=valid[t];
                if (a[p].count(j)){
                    int c;
                    for (int ne:m[p]){
                        c=__builtin_popcount(ne);
                        if (j+c<=k)
                            b[ne][j+c]+=a[p][j];
                    }
                }
            }
        a=b;
    }
    long long ans=0;
    for (auto &[_,um]:a)
        ans+=um[k];
    cout<<ans<<endl;
    return 0;
}