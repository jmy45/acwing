#include<iostream>
using namespace std;
const int N=100010;
int a[N],b[N];
int main(){
    int n,m,x;
    scanf("%d%d%d",&n,&m,&x);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for (int i=0;i<m;i++)
        scanf("%d",&b[i]);
    int i=0,j=m-1;
    //数据保证唯一解
    while (1){
        if (a[i]+b[j]>x)
            j--;
        else if (a[i]+b[j]<x)
            i++;
        else  break;    
    }
    printf("%d %d",i,j);
    return 0;
}