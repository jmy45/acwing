#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n;
int d[N][20];
int main(){
    scanf("%d",&n);
    int x;
    for (int i=0;i<n;i++){
        scanf("%d",&x);
        d[i][0]=x;
    }
    int t=1;
    while (1){
        int l=1<<t;
        for (int i=0;i<n;i++){
            int y=d[i][t-1];
            int ml=1<<t-1;
            if (i+ml<n)
                y=max(y,d[i+ml][t-1]);
            d[i][t]=y;
        }
        t++;
        if (l>=n) break;
    }
    int m,a,b;
    scanf("%d",&m);
    for (int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        a--,b--;
        int len=b-a+1;
        int k=32-__builtin_clz(len);
        k--;
        printf("%d\n",max(d[a][k],d[b-(1<<k)+1][k]));
    }
    return 0;
}