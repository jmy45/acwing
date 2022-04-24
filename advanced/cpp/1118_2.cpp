#include<iostream>
#include<algorithm>
using namespace std;
const int N=10;
int a[N],n;
int ans;
bool g[1<<N];
int v[1<<N];
bool check(int i,int j){
    return __gcd(a[i],a[j])==1;
}
int dfs(int st){
    if (v[st]) return v[st];
    if (st==(1<<n)-1) return 0;
    v[st]=n;
    int t=0;
    for (;t<n;t++)
        if (!(st>>t&1)) 
            break;
    for (int i=st|(1<<t);i<1<<n;i++)
        if (g[i^st])
            v[st]=min(v[st],dfs(i)+1);
    return v[st];
}
int main(){
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int st=1;st<1<<n;st++){
        bool f=true;
        for (int i=0;i<n&&f;i++)
            if (st>>i&1)
                for (int j=i+1;j<n;j++)
                    if (st>>j&1){
                        f&=check(i,j);
                        if (!f) break;
                    }
        g[st]=f;
    }
    cout<<dfs(0)<<endl;
    return 0;
}