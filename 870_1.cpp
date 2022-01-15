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
    long long sum=1,mod=1e9+7;
    for (auto &[k,v]:m)
        sum=(sum*(v+1))%mod;
    cout<<sum<<endl;
    return 0;
}