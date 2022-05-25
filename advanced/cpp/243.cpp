#include<iostream>
typedef long long LL;
const int N=100010;
int arr[N];
struct Node{
    int l,r;
    LL sum;
} tr[N*4];
int lazy[N*4];
void pushup(int u){
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}
void pushdown(int u){
    lazy[u<<1]+=lazy[u];
    lazy[u<<1|1]+=lazy[u];
    tr[u<<1].sum+=(LL)lazy[u]*(tr[u<<1].r-tr[u<<1].l+1);
    tr[u<<1|1].sum+=(LL)lazy[u]*(tr[u<<1|1].r-tr[u<<1|1].l+1);
    lazy[u]=0;
}
void build(int u,int l,int r){
    if (l==r) tr[u]={l,r,arr[l]};
    else{
        tr[u]={l,r};
        int md=l+r>>1;
        build(u<<1,l,md),build(u<<1|1,md+1,r);
        pushup(u);
    }
}
void update(int u,int l,int r,int x){
    if (l<=tr[u].l&&tr[u].r<=r){
        lazy[u]+=x;
        tr[u].sum+=(LL)(tr[u].r-tr[u].l+1)*x;
        return;
    }
    if (lazy[u]) pushdown(u);
    int md=tr[u].l+tr[u].r>>1;
    if (l<=md) update(u<<1,l,r,x);
    if (md<r) update(u<<1|1,l,r,x);
    pushup(u);
}
LL query(int u,int l,int r){
    if (l<=tr[u].l&&tr[u].r<=r){
        return tr[u].sum;
    }
    if (lazy[u]) pushdown(u);
    int md=tr[u].l+tr[u].r>>1;
    LL ans=0;
    if (l<=md) ans+=query(u<<1,l,r); 
    if (md<r) ans+=query(u<<1|1,l,r);
    return ans;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    build(1,1,n);
    char op[2];
    int a,b,c;
    while (m--){
        scanf("%s",op);
        if (*op=='Q'){
            scanf("%d%d",&a,&b);
            printf("%lld\n",query(1,a,b));
        }
        else{
            scanf("%d%d%d",&a,&b,&c);
            update(1,a,b,c);
        }
    }
    return 0;
}