//二维费用背包
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1010,M=510;
int n,V1,V2;
int f[N][M];
int main(){
    cin>>n>>V1>>V2;
    for (int i=0;i<n;i++){
        int v1,v2,w;
        cin>>v1>>v2>>w;
        for (int j=V1;j>=v1;j--)
            for (int k=V2;k>=v2;k--)
                f[j][k]=max(f[j][k],f[j-v1][k-v2]+w);
    }
    int k=V2;
    while (k&&f[V1][k-1]==f[V1][V2])
        k--;
    cout<<f[V1][V2]<<endl;
    return 0;
}