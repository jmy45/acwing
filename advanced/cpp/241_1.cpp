#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=200010;
int w[N],a[N],b[N];
int n;
int p[N];
LL ans1,ans2;
int lowbit(int x){
    return x&(-x);
}
void add(int x,int v){
    for (int i=x;i<=N;i+=lowbit(i))
        p[i]+=v;
}
LL query(int x){
    LL ans=0;
    for (int i=x;i>=1;i-=lowbit(i))
        ans+=p[i];
    return ans;
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&w[i]);
    for (int i=1;i<=n;i++) {
        a[i]=query(w[i]-1);
        add(w[i],1);
    }
    memset(p,0,sizeof p);
    for (int i=n;i>=1;i--) {
        b[i]=query(w[i]-1);
        add(w[i],1);
    }
    for (int i=2;i<=n-1;i++){
        ans1+=LL(i-1-a[i])*(n-i-b[i]);
        ans2+=(LL)b[i]*a[i];
    }
    printf("%lld %lld\n",ans1,ans2);
    return 0;
}