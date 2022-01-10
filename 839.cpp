#include<cstdio>
#include<algorithm>
#include<string.h>
const int N=100010;
int n,m;
int h[N],sz,ph[N],hp[N];
using namespace std;
void heap_swap(int a,int b){
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a],hp[b]);
    swap(h[a],h[b]);
}
void down(int u){
    int t=u;
    if (u*2<=sz&&h[u*2]<h[t])
        t=2*u;
    if (u*2+1<=sz&&h[u*2+1]<h[t])
        t=2*u+1;
    if (u!=t){
        heap_swap(u,t);
        down(t);
    }
};
void up(int u){
    while (u/2&&h[u/2]>h[u]){
        heap_swap(u/2,u);
        u/=2;
    }
}
int main(){
    scanf("%d",&n);
    while (n--){
        char op[10];
        int k,x;
        scanf("%s",op);
        if (!strcmp(op,"I")){
            scanf("%d",&x);
            m++;
            sz++;
            ph[m]=sz;
            hp[sz]=m;
            h[sz]=x;
            up(sz);
        }
        else if (!strcmp(op,"PM"))
            printf("%d\n",h[1]);
        else if (!strcmp(op,"DM")){
            heap_swap(1,sz);
            sz--;
            down(1);
        }
        else if (!strcmp(op,"D")){
            scanf("%d",&k);
            k=ph[k];
            heap_swap(k,sz);
            sz--;
            down(k),up(k);
        }
        else{
            scanf("%d%d",&k,&x);
            k=ph[k];
            h[k]=x;
            down(k),up(k);
        }
    }
    return 0;
}