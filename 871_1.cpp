#include<iostream>
#include<unordered_map>
#include<math.h>
using namespace std;
unordered_map<int,int> m;
void prime(int x){
    int j=sqrt(x);
    for (int i=2;x!=1&&i<=j;i++){
        int y=0;
        while (x%i==0) {
            x/=i;
            m[i]++;
        }
    }
    if (x!=1)
        m[x]++;
}
int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        prime(a);
    }
    long long ans=1,mod=1e9+7;
    for (auto &[k,v]:m){
        long long sum=0,mul=1;
        for (int i=0;i<=v;i++){
            sum=(sum+mul)%mod;
            mul=(mul*k)%mod;
        }
        ans=(ans*sum)%mod;
    }
    cout<<ans<<endl;
    return 0;
}