//自己写的，y总风格
#include <cstdio>
using namespace std;
const int N=100010;
int p[N],size[N];
int find(int x){
    if (p[x]!=x)
        p[x]=find(p[x]);
    return p[x];
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
        p[i]=i;
        size[i]=1;
    }
    while (m--){
        char op;
        int a,b;
        scanf("%s%d%d",&op,&a,&b);
        if (op=='M'){
            if (find(a)==find(b))   continue;
            p[find(a)]=find(b);
            size[find(b)]+=size[find(a)];
        }
        else{
            if (find(a)==find(b))
                puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}