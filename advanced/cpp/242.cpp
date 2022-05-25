#include<iostream>
using namespace std;
const int N=100010;
int w[N],p[N];
int n,m;
int lowbit(int x){
    return x&(-x);
}
void update(int x,int v){
    for (int i=x;i<=N;i+=lowbit(i))
        p[i]+=v;
}
int query(int x){
    int ans=0;
    for (int i=x;i;i-=lowbit(i))
        ans+=p[i];
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) {
        scanf("%d",&w[i]);
        update(i,w[i]-w[i-1]);
    }
    char op[2];
    int l,r,d,x;
    while (m--){
        scanf("%s",op);
        if (*op=='C'){
            scanf("%d%d%d",&l,&r,&d);
            update(l,d);
            if (r+1<=n) update(r+1,-d);
        }
        else{
            scanf("%d",&x);
            printf("%d\n",query(x));
        }
    }
    return 0;
}