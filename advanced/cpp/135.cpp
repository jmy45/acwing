#include<iostream>
#include<limits.h>
using namespace std;
typedef long long LL;
const int N=300010;
int n,m;
int q[N];
LL s[N];
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>s[i];
        s[i]+=s[i-1];
    }
    int hh=0,tt=0;
    LL res=INT_MIN;
    for (int i=1;i<=n;i++){
        if (i-q[hh]>m) hh++;
        res=max(res,s[i]-s[q[hh]]);
        while (hh<=tt&&s[q[tt]]>=s[i]) tt--;
        q[++tt]=i;
    }
    cout<<res<<endl;
    return 0;
}