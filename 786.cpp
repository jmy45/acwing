//快速选择
#include<iostream>
using namespace std;
const int N=100010;
int a[N];
int findK(int l,int r,int k){
    if (l==r)
        return a[l];
    int pivot=a[l];
    int i=l-1,j=r+1;
    while (i<j){
        do{i++;} while (a[i]<pivot);
        do{j--;} while (a[j]>pivot);
        if (i<j) swap(a[i],a[j]);
    }
    if (j-l+1>=k)
        findK(l,j,k);
    else
        findK(j+1,r,k-j+l-1);
}
int main(){
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++)
        cin>>a[i];
    cout<<findK(0,n-1,k)<<endl;
    return 0;
}