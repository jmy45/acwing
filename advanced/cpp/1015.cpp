#include<iostream>
using namespace std;
const int N=110;
int a[N][N];
int main(){
    int t,r,c;
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        scanf("%d%d",&r,&c);
        for (int j=1;j<=r;j++)
            for (int k=1;k<=c;k++){
                scanf("%d",&a[j][k]);
                a[j][k]+=max(a[j][k-1],a[j-1][k]);
            }
        printf("%d\n",a[r][c]);
    }
    return 0;
}