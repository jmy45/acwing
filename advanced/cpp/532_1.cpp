#include<iostream>
#include<unordered_set>
#include<algorithm>
#include<cstring>
using namespace std;
const int M=25005,N=105;
int a[N],dp[M];
int main(){
    int T,n,idx;
    scanf("%d",&T);
    for (int i=0;i<T;i++){
        scanf("%d",&n);
        memset(dp,0,sizeof(dp));
        for (int j=1;j<=n;j++){
            scanf("%d",&a[j]);
        }
        idx=1;
        sort(a+1,a+n+1);
        dp[0]=1;
        int ans=0,lc=0;
        for (int j=1;j<=n;j++){
            for (int k=a[j];k<M;k++)
                dp[k]+=dp[k-a[j]];
            int c=0;
            for (int k=1;k<=n;k++)
                if (dp[a[k]])
                    c++;
            if (c!=lc){
                ans++;
                lc=c;
            }
            if (c==n)
                break;
        }
        printf("%d\n",ans);
    }
    return 0;
}