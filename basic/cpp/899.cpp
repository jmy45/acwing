#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1010,M=11;
int n,m,ans,limit;
char a[N][N],b[N];
int f[M][M];
int cal_dist(char a[],char b[]){
    int n=strlen(a+1),m=strlen(b+1);
    for (int i=0;i<=m;i++)  f[0][i]=i;
    for (int i=0;i<=n;i++)  f[i][0]=i;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            f[i][j]=min(f[i-1][j]+1,f[i][j-1]+1);
            if (a[i]==b[j])
                f[i][j]=min(f[i][j],f[i-1][j-1]);
            else
                f[i][j]=min(f[i][j],f[i-1][j-1]+1);
        }
    return f[n][m];
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++)
        scanf("%s",a[i]+1);
    for (int i=0;i<m;i++){
        scanf("%s%d",b+1,&limit);
        ans=0;
        for (int j=0;j<n;j++){
            int r=cal_dist(a[j],b);
            if (r<=limit)
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}