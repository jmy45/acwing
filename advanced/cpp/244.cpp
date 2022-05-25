#include<iostream>
#include<algorithm>
using namespace std;
const int N=100010;
int n;
int w[N],p[N];
int ans[N];
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
    scanf("%d",&n);
    for (int i=2;i<=n;i++)
        scanf("%d",&w[i]);
    for (int i=1;i<=n;i++){
        ans[i]=i;
        update(i,1);
    }
    for (int i=n;i>=1;i--){
        int l=1,r=n;
        while (l<r){
            int md=l+r>>1;
            if (query(md)<w[i]+1) l=md+1;
            else r=md; 
        }
        ans[i]=r;
        update(ans[i],-1);
    }
    for (int i=1;i<=n;i++)
        printf("%d\n",ans[i]);
    return 0;
}