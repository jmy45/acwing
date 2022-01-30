//340ms
#include<iostream>
#include<vector>
using namespace std;
const int N=100010;
int a[N];
vector<int> merge_sort(int a[],int l,int r){
    if (l==r) return {a[l]};
    int md=(l+r)>>1;
    auto arr1=merge_sort(a,l,md);
    auto arr2=merge_sort(a,md+1,r);
    int l1=arr1.size(),l2=arr2.size();
    vector<int> v;
    int i=0,j=0;
    while (i<l1||j<l2){
        int x=i<l1?arr1[i]:0x3f3f3f3f;
        int y=j<l2?arr2[j]:0x3f3f3f3f;
        if (x<y){
            v.push_back(x);
            i++;
        }
        else{
            v.push_back(y);
            j++;
        }
    }
    return v;
}
int main(){
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    auto v=merge_sort(a,0,n-1);
    for (int e:v)
        printf("%d ",e);
    return 0;
}