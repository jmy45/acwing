//扩展域写法
#include<iostream>
using namespace std;
const int N=150030;
int n,m;
int p[N];
int find(int x){
    if (p[x]!=x)
        p[x]=find(p[x]);
    return p[x];
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=N;i++) p[i]=i;
    int res=0;
    while (m--){
        int t,x,y;
        scanf("%d%d%d",&t,&x,&y);
        if (x>n||y>n) res++;
        else{
            if (t==1){
                if (find(x)==find(y+n)||find(x)==find(y+2*n))
                    res++;
                else{
                    p[find(x)]=find(y);
                    p[find(x+n)]=find(y+n);
                    p[find(x+2*n)]=find(y+2*n);
                }
            }
            else{
                if (find(x)==find(y+2*n)||find(x)==find(y))
                    res++;
                else{
                    p[find(x)]=find(y+n);
                    p[find(x+n)]=find(y+2*n);
                    p[find(x+2*n)]=find(y);
                }
            }
        }
    }
    printf("%d\n",res);
    return 0;
}