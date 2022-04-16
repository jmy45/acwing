#include<iostream>
using namespace std;
const int N=300010;
int q[N],pre[N];
int main(){
    int n,m,x;
    cin>>n>>m;
    int hh=0,tt=-1;
    q[++tt]=0;
    int ans=-0x3f3f3f3f;
    for (int i=1;i<=n;i++){
        cin>>x;
        pre[i]=pre[i-1]+x;
        if (hh<=tt&&i-q[hh]>m) hh++;
        while (hh<=tt&&pre[q[tt]]>=pre[i]) 
            tt--;
        ans=max(ans,pre[i]-pre[q[hh]]);
        q[++tt]=i;
    }
    cout<<ans<<endl;
    return 0;
}