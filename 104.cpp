#include<iostream>
#include<algorithm>
using namespace std;
const int N=100010;
int a[N];
int main(){
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    long long ans=0;
    sort(a,a+n);
    int t=n/2;
    for (int i=0;i<n;i++)
        ans+=abs(a[t]-a[i]);
    printf("%lld",ans);
    return 0;
}