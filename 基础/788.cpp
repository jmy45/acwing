#include<iostream>
using namespace std;
const int N=100010;
int a[N],t[N];
long long ans;
void merge_sort(int l,int r){
    if (l==r) return ;
    int md=(l+r)>>1;
    merge_sort(l,md);
    merge_sort(md+1,r);
    int i=l,j=md+1,idx=0;
    while (i<=md&&j<=r){
        if (a[i]<=a[j]){
            t[idx++]=a[i++];
        }
        else{
            t[idx++]=a[j++];
            ans+=md+1-i;
        }
    }
    while (i<=md)
        t[idx++]=a[i++];
    while (j<=r)
        t[idx++]=a[j++];
    for (int k=0;k<idx;k++)
        a[l+k]=t[k];
}
int main(){
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    merge_sort(0,n-1);
    printf("%lld",ans);
    return 0;
}