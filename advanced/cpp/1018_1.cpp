#include<iostream>
using namespace std;
const int N=110,M=0x3f3f3f3f;
int a[N][N];
int main(){
    int n,t;
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++){
            cin>>a[i][j];
            int t=M;
            if (i>1)
                t=min(t,a[i-1][j]);
            if (j>1)
                t=min(t,a[i][j-1]);
            a[i][j]+=t==M?0:t;
        }
    cout<<a[n][n]<<endl;
    return 0;
}