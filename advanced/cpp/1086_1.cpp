#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
LL l,r,T;
const int M=19,N=7,mod=1e9+7;
LL f[M][M][N][N],g[M][M][N][N],h[M][M][N][N];
void init(){
    for (int i=0;i<=9;i++)
        if (i!=7)
            for (int a=0;a<N;a++)
                for (int b=0;b<N;b++)
                    if ((N+a-i%N)%N&&(b*10+i)%N){
                        h[1][i][a][b]++;
                        g[1][i][a][b]=i;
                        f[1][i][a][b]=i*i;
                    }
    for (int i=2;i<M;i++)
        for (int j=0;j<=9;j++)
            if (j!=7)
                for (int k=0;k<=9;k++)
                    if (k!=7)
                        for (int a=0;a<N;a++)
                            for (int b=0;b<N;b++){
                                LL &sum=g[i-1][k][(N+a-j%N)%N][(b*10+j)%N];
                                LL &sum2=f[i-1][k][(N+a-j%N)%N][(b*10+j)%N];
                                LL &tot=h[i-1][k][(N+a-j%N)%N][(b*10+j)%N];
                                h[i][j][a][b]+=tot;
                                h[i][j][a][b]%=mod;
                                LL t=j*(LL)pow(10,i-1)%mod;
                                g[i][j][a][b]+=tot*t+sum;
                                g[i][j][a][b]%=mod;
                                f[i][j][a][b]+=sum2+2*t*sum+t*t%mod*tot;
                                f[i][j][a][b]%=mod;
                            }
}
LL dp(LL n){
    if (!n) return 0;
    vector<int> nums;
    while (n) nums.push_back(n%10),n/=10;
    LL res=0;
    LL last=0,last2=0,last3=0;
    for (int i=nums.size()-1;i>=0;i--){
        int x=nums[i];
        LL t=last3*(LL)pow(10,i+1)%mod;
        for (int j=0;j<x;j++)
            if (j!=7){
                LL &sum2=f[i+1][j][last][last2];
                LL &sum=g[i+1][j][last][last2];
                LL &tot=h[i+1][j][last][last2];
                res+=sum2+2*t*sum+t*t%mod*tot;
                res%=mod;
            }
        if (x==7) break;
        last=(N+last-x%N)%N;
        last2=(last2*10+x)%N;
        last3=last3*10+x;
        if (!i&&last&&last2) res+=last3%mod*(last3%mod);        
    }
    return res%mod;
}
int main(){
    cin>>T;
    init();
    while (T--){
        cin>>l>>r;
        cout<<(dp(r)+mod-dp(l-1))%mod<<endl;
    }
    return 0;
}