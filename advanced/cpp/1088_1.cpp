#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=2000010;
LL a[N],b[N],q[N],p[N],f[N],n,oil[N],dis[N];
void circle(bool reversed){
    int hh=0,tt=-1;
    for (int i=1;i<=2*n;i++){
        if (hh<=tt&&i-q[hh]>n) hh++;
        if (i>n){
            LL x=p[i]-p[q[hh]];
            if (x>=0)
                if (reversed) 
                    f[n+1-(i-n)]=1;
                else
                    f[i-n]=1;
        }
        while (hh<=tt&&p[q[tt]]<=p[i]) tt--;
        q[++tt]=i;
    } 
}
int main(){
    scanf("%lld",&n);
    for (int i=1;i<=n;i++){
        scanf("%lld%lld",&oil[i],&dis[i]);
        a[i+n]=a[i]=oil[i]-dis[i];
    }
    b[n+1]=b[1]=oil[1]-dis[n];
    for (int i=2;i<=n;i++)
        b[i+n]=b[i]=oil[i]-dis[i-1];
    reverse(a+1,a+2*n+1);
    for (int i=1;i<=2*n;i++)
        p[i]=p[i-1]+a[i];
    circle(true);
    for (int i=1;i<=2*n;i++)
        p[i]=p[i-1]+b[i];
    circle(false);
    for (int i=1;i<=n;i++)
        if (!f[i]) 
            printf("%s\n","NIE");
        else 
            printf("%s\n","TAK");
    return 0;
}