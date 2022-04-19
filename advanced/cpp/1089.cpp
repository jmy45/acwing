#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=200010;
int n,m,w[N],f[N],q[N];
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    int hh=0,tt=0;
    for (int i=1;i<=n;i++){
        if (q[hh]<i-m) hh++;
        f[i]=f[q[hh]]+w[i];
        while (hh<=tt&&f[i]<=f[q[tt]]) tt--;
        q[++tt]=i;
    }
    int res=1e9;
    for (int i=n-m+1;i<=n;i++) res=min(res,f[i]);
    printf("%d\n",res);
    return 0;
}