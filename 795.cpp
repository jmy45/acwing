//y总也是这么写的
#include<iostream>
using namespace std;
const int N=100010;
int a[N],presum[N];
int main(){
    int n,m,l,r;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        presum[i]=presum[i-1]+a[i];    
    for (int i=1;i<=m;i++){
        cin>>l>>r;
        cout<<presum[r]-presum[l-1]<<endl;
    }
    return 0;
}