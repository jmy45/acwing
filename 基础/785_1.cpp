//qsort  210ms
#include<iostream>
using namespace std;
const int N=100010;
int q[N];
void qsort(int q[],int l,int r){
    if (l>=r) return ;
    int rnd_idx = rand() % (r - l + 1) + l;
    swap(q[l], q[rnd_idx]);
    int pivot =q[l];
    int i=l,j=r;
    while (i<j){
        while (i<j&&q[j]>pivot)
            j--;
        swap(q[i],q[j]);
        if (i<j) i++;
        while (i<j&&q[i]<pivot)
            i++;
        swap(q[i],q[j]);
        if (i<j) j--;
    }
    q[i]=pivot;
    qsort(q,l,i-1);
    qsort(q,i+1,r);
}
int main(){
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&q[i]);
    qsort(q,0,n-1);
    for (int i=0;i<n;i++)
        printf("%d ",q[i]);
    return 0;
}