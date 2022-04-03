#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=101;
int n;
int w[N];
__int128_t f[N][N];
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>w[i];
    }
    for (int len=3;len<=n;len++)
        for (int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            f[l][r]=1e28;
            for (int k=l+1;k<r;k++)
                f[l][r]=min(f[l][r],f[l][k]+f[k][r]+(__int128_t)w[l]*w[k]*w[r]);
        }
    __int128_t res=f[1][n];
    string s;
    while (res){
        s+='0'+res%10;
        res/=10;
    }
    reverse(s.begin(),s.end());
    cout<<s<<endl;
}