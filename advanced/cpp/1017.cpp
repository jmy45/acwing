#include<iostream>
#include<algorithm>
using namespace std;
const int N=110;
int n;
int a[N],f[N];
int main(){
    int T;
    scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        int res=0;
        for (int i=1;i<=n;i++){
            f[i]=1;
            for (int j=1;j<i;j++)
                if (a[i]>a[j])
                    f[i]=max(f[i],f[j]+1);
            res=max(res,f[i]);
        }
        for (int i=n;i;i--){
            f[i]=1;
            for (int j=n;j>i;j--)
                if (a[i]>a[j])
                    f[i]=max(f[i],f[j]+1);
            res=max(res,f[i]);
        }
        printf("%d\n",res);
    }
    return 0;
}