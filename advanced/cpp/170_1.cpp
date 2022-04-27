#include<iostream>
#include<cstring>
using namespace std;
int n;
int m;
int a[100],b[100];
bool check(int idx,int x){
    int l=0,r=idx-1;
    while (l<r){
        if (a[l]+a[r]<x) l++;
        else if (a[l]+a[r]>x) r--;
        else return true;
    }
    return a[l]+a[r]==x;      
}
void dfs(int idx){
    if (idx>=m) return;
    if (a[idx-1]==n){
        m=idx;
        memcpy(b,a,m*sizeof(int));
        return;
    }
    for (int i=min(2*a[idx-1],n);i>a[idx-1];i--)
        if (check(idx,i))
        {
            a[idx]=i;
            dfs(idx+1);
        }
}
int main(){
    while (cin>>n,n){
        m=100;
        a[0]=1;
        dfs(1);
        for (int i=0;i<m-1;i++)
            printf("%d ",b[i]);
        printf("%d\n",b[m-1]);
    }
    return 0;
}