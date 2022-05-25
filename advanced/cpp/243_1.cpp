#include<iostream>
using namespace std;
typedef long long LL;
const int N=100010;
int a[N];
LL p[N],q[N];
int n,m;
int lowbit(int x){
    return x&(-x);
}
void update(LL p[],int x,LL v){
    for (int i=x;i<=N;i+=lowbit(i))
        p[i]+=v;
}
LL query(LL p[],int x){
    LL ans=0;
    for (int i=x;i;i-=lowbit(i))
        ans+=p[i];
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        update(p,i,a[i]-a[i-1]);
        update(q,i,(LL)(n+1-i)*(a[i]-a[i-1]));
    }
    char op[2];
    int l,r,d;
    while (m--){
        scanf("%s",op);
        if (*op=='C'){
            scanf("%d%d%d",&l,&r,&d);
            update(p,l,d),update(p,r+1,-d);
            update(q,l,(LL)(n+1-l)*d),update(q,r+1,(LL)(n-r)*(-d));
        }
        else{
            scanf("%d%d",&l,&r);
            LL ans=query(q,r)-query(q,l-1)-(n-r)*query(p,r)+(n-l+1)*query(p,l-1);
            printf("%lld\n",ans);
        }
    }
}