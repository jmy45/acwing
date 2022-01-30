#include<iostream>
#include<cstring>
#include<algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int,int> PII;
const int N=50010;
int n;
PII a[N];
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        int w,s;
        scanf("%d%d",&w,&s);
        a[i]={w+s,w};
    }
    sort(a,a+n);
    int res=-1e9;
    for (int i=0,sum=0;i<n;i++){
        int w=a[i].y,s=a[i].x-w;
        res=max(res,sum-s);
        sum+=w;
    }
    printf("%d",res);
    return 0;
}