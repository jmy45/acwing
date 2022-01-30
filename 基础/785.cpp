//全文背诵。。180ms
#include<iostream>
using namespace std;
const int N=1e5+10;
int n;
int q[N];
void qsort(int q[],int l,int r){
    if (l>=r) return;
    int rnd_idx = rand() % (r - l + 1) + l;
    swap(q[l], q[rnd_idx]);
    int x=q[l],i=l-1,j=r+1;
    while (i<j){
        do i++; while (q[i]<x);
        do j--; while (q[j]>x);
        if (i<j) swap(q[i],q[j]);
    }
    qsort(q,l,j);
    qsort(q,j+1,r);
}
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&q[i]);
    qsort(q,0,n-1);
    for (int i=0;i<n;i++)
        printf("%d ",q[i]);
    return 0;
}