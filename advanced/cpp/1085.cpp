#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int n,m;
const int N=10;
int f[N][N];
void init(){
    memset(f,0,sizeof(f));
    for (int i=0;i<=9;i++) 
        if (i!=4) f[1][i]++;
    for (int i=2;i<N;i++)
        for (int j=0;j<=9;j++)
            for (int k=0;k<=9;k++)
                if (k!=4&&!(k==2&&j==6))
                    f[i][j]+=f[i-1][k];
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
            if (j!=4&&!(j==2&&last==6)) 
                res+=f[i+1][j];
        if (x==4||(x==2&&last==6)) break;
        else last=x;
        if (!i) res++;        
    }
    return res;
}
int main(){
    while (cin>>n>>m,n|m){
        init();
        cout<<dp(m)-dp(n-1)<<endl;
    }
    return 0;
}