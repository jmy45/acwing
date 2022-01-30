#include<iostream>
using namespace std;
int qexp(long long x,int y,int m){
    long long ans=1;
    while (y){
        if (y&1)
            ans=(ans*x)%m;
        x=(x*x)%m;
        y>>=1;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,a,b,m;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a>>b>>m;
        cout<<qexp(a,b,m)<<endl;
    }
    return 0;
}