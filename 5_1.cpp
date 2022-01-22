//多重背包II
#include<iostream>
using namespace std;
const int N=11010;
int volume[N],price[N],idx=1;
int dp[N];
int main(){
    int n,v,x,y,z;
    scanf("%d%d",&n,&v);
    for (int i=1;i<=n;i++){
        scanf("%d%d%d",&x,&y,&z);
        int z2=z;
        int nz=1;
        while (z>1){
            volume[idx]=nz*x;
            price[idx]=nz*y;
            idx++;
            z>>=1;
            nz<<=1;
        }
        if (z==1){
            nz=z2-nz+1;
            volume[idx]=nz*x;
            price[idx]=nz*y;
            idx++;
        }
    }
    for (int i=1;i<idx;i++)
        for (int j=v;j>=volume[i];j--)
                dp[j]=max(dp[j],dp[j-volume[i]]+price[i]);
    printf("%d",dp[v]);
    return 0;
}