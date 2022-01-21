//已知m为质数，求b的乘法逆元
#include<iostream>
using namespace std;
typedef long long LL;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int qmul(int x,int y,int m){
    int ret=1;
    while (y){
        if (y&1)
            ret=(LL)ret*x%m;
        x=(LL)x*x%m;
        y>>=1;
    }
    return ret;
}
int main(){
    int n,b,m;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d%d",&b,&m);
        if (gcd(b,m)>1)
            puts("impossible");
        else
            printf("%d\n",qmul(b,m-2,m));
    }
    return 0;
}