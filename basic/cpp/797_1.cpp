//170ms
#include<iostream>
using namespace std;
const int N=100010;
int a[N],d[N];
int main(){
    int n,m,l,r,c;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        d[i]=a[i]-a[i-1];
    }
    while (m--){
        scanf("%d%d%d",&l,&r,&c);
        d[l]+=c;
        d[r+1]-=c;
    }
    int t=0;
    for (int i=1;i<=n;i++){
        t+=d[i];
        printf("%d ",t);
    }
    return 0;
}