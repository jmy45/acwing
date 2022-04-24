#include<iostream>
#include<cstring>
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
void dfs(int st,int groups){
    if (groups>=ans) return;
    if (st==(1<<n)-1){
        ans=min(ans,groups);
        return ;
    }
    if (groups>=v[st]) return;
    v[st]=groups;
    int t=0;
    for (;t<n;t++)
        if (!(st>>t&1)) 
            break;
    for (int i=st|(1<<t);i<1<<n;i++)
        if (g[i^st])
            dfs(i,groups+1);
}
int main(){
    memset(v,0x3f,sizeof v);
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
    ans=n;
    dfs(0,0);
    cout<<ans<<endl;
    return 0;
}