#include<cstdio>
#include<algorithm>
const int N=100010;
int n,m;
int h[N],sz;
using namespace std;
void down(int u){
    int t=u;
    if (u*2<=sz&&h[u*2]<h[t])
        t=2*u;
    if (u*2+1<=sz&&h[u*2+1]<h[t])
        t=2*u+1;
    if (u!=t){
        swap(h[u],h[t]);
        down(t);
    }
};
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%d",&h[i]);
    sz=n;
    for (int i=n/2;i;i--)
        down(i);
    while (m--){
        printf("%d",h[1]);
        h[1]=h[sz];
        sz--;
        down(1);
    }
    return 0;
}