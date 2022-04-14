#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int a,b,N;
const int M=31;
int f[M][M][100];
void init(){
    for (int i=0;i<=9;i++)
        for (int j=0;j<N;j++)
            f[1][i][j]=(i-j)%N==0;
    for (int i=2;i<M;i++)
        for (int l=0;l<N;l++)
            for (int j=0;j<=9;j++)
                for (int k=0;k<=9;k++)
                    f[i][j][l]+=f[i-1][k][(N+l-j%N)%N];
}
int dp(int n){
    if (!n) return 1;
    vector<int> nums;
    while (n) nums.push_back(n%10),n/=10;
    int res=0;
    int last=0;
    for (int i=nums.size()-1;i>=0;i--){
        int x=nums[i];
        for (int j=0;j<x;j++)
            res+=f[i+1][j][last];
        last=(N+last-x)%N;
        if (!i&&!last) res++;        
    }
    return res;
}
int main(){
    while (cin>>a>>b>>N){
        memset(f,0,sizeof(f));
        init();
        cout<<dp(b)-dp(a-1)<<endl;
    }
    return 0;
}