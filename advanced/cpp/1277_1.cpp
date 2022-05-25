//2222ms
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=100010;
int w[N];
struct Node{
    int l,r;
    int sum;
}tr[N*3];
int add[N*3],mul[N*3];
int n,p;
void pushup(Node&u,Node&l,Node&r){
    u.sum=((LL)l.sum+r.sum)%p;
}
void pushup(int u){
    pushup(tr[u],tr[u<<1],tr[u<<1|1]);
}
void pushdown(int u){
    int l=u<<1,r=u<<1|1;
    add[l]=((LL)add[l]*mul[u]+add[u])%p;
    add[r]=((LL)add[r]*mul[u]+add[u])%p;
    mul[l]=((LL)mul[l]*mul[u])%p;
    mul[r]=((LL)mul[r]*mul[u])%p;
    tr[l].sum=((LL)tr[l].sum*mul[u]+(LL)add[u]*(tr[l].r-tr[l].l+1))%p;
    tr[r].sum=((LL)tr[r].sum*mul[u]+(LL)add[u]*(tr[r].r-tr[r].l+1))%p;
    add[u]=0,mul[u]=1;
}
void build(int u,int l,int r){
    if (l==r){
        tr[u]={l,r,w[l]};
        return;
    }
    int md=l+r>>1;
    tr[u]={l,r};
    build(u<<1,l,md),build(u<<1|1,md+1,r);
    pushup(u);
}
void update(int u,int l,int r,int x,int type){
    if (l<=tr[u].l&&tr[u].r<=r){
        if (type==1){
            tr[u].sum=((LL)tr[u].sum*x)%p;
            mul[u]=((LL)mul[u]*x)%p;
            add[u]=((LL)add[u]*x)%p;
        }
        else{
            tr[u].sum=(tr[u].sum+(LL)x*(tr[u].r-tr[u].l+1))%p;
            add[u]=(add[u]+x)%p;
        }
        return;
    }
    if (add[u]||mul[u]!=1) pushdown(u);
    int md=tr[u].l+tr[u].r>>1;
    if (l<=md) update(u<<1,l,r,x,type);
    if (r>md) update(u<<1|1,l,r,x,type);
    pushup(u);
}
int query(int u,int l,int r){
    if (l<=tr[u].l&&tr[u].r<=r) return tr[u].sum;
    if (add[u]||mul[u]!=1) pushdown(u);
    int md=tr[u].l+tr[u].r>>1;
    int ans=0;
    if (l<=md) ans=query(u<<1,l,r);
    if (r>md) ans=((LL)ans+query(u<<1|1,l,r))%p;
    return ans;
}
int main(){
    for (int i=1;i<=N*3;i++) mul[i]=1;
    scanf("%d%d",&n,&p);
    for (int i=1;i<=n;i++) scanf("%d",&w[i]);
    build(1,1,n);
    int m;
    scanf("%d",&m);
    int x,t,g,c;
    while (m--){
        scanf("%d%d%d",&x,&t,&g);
        if (x==1){
            scanf("%d",&c);
            update(1,t,g,c,1);
        }
        else if (x==2){
            scanf("%d",&c);
            update(1,t,g,c,2);
        }
        else{
            printf("%d\n",query(1,t,g));
        }
    }
    return 0;
}