#include<iostream>
#include<algorithm>
using namespace std;
const int N=100010;
int n;
int a[N],q[N];
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int len=0;
    q[0]=-2e9;
    for (int i=0;i<n;i++){
        int l=0,r=len;
        while (l<r){
            int md=l+r+1>>1;
            if (q[md]<a[i])
                l=md;
            else
                r=md-1;
        }
        len=max(len,r+1);
        q[r+1]=a[i];
    }
    printf("%d\n",len);
    return 0;
}