#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=2e6+10;
int n;
int o[N],d[N];
LL s[N];
int q[N];
bool ans[N];
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d%d",&o[i],&d[i]);
    for (int i=1;i<=n;i++) s[i]=s[i+n]=o[i]-d[i];
    for (int i=1;i<=n*2;i++) s[i]+=s[i-1];
    int hh=0,tt=-1;
    for (int i=n*2;i;i--){
        if (hh<=tt&&q[hh]>=i+n) hh++;
        while (hh<=tt&&s[q[tt]]>=s[i]) tt--;
        q[++tt]=i;
        if (i<=n){
            if (s[q[hh]]>=s[i-1]) ans[i]=true;
        }
    }
    d[0]=d[n];
    for (int i=1;i<=n;i++) s[i]=s[i+n]=o[i]-d[i-1];
    for (int i=1;i<=n*2;i++) s[i]+=s[i-1];
    hh=0,tt=-1;
    for (int i=1;i<=n*2;i++){
        if (hh<=tt&&q[hh]<i-n) hh++;
        if (i>n){
            if (s[q[hh]]<=s[i]) ans[i-n]=true;
        }
        while (hh<=tt&&s[q[tt]]<=s[i]) tt--;
        q[++tt]=i;
    }
    for (int i=1;i<=n;i++)
        if (ans[i]) puts("TAK");
        else puts("NIE");
    return 0;
}