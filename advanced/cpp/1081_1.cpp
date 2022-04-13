#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
int X,Y,K,B;
LL C(int a,int b){
    if (a<b) return 0;
    LL ans=1;
    for (int i=1;i<=b;i++){
        ans*=(a-i+1);
        ans/=i;
    }
    return ans;
}
LL calc(int x){
    LL ans=0;
    vector<int> digits;
    while (x){
        digits.push_back(x%B);
        x/=B;
    }
    reverse(digits.begin(),digits.end());
    int bits=digits.size(),ones=0,i=0;
    for (;i<bits;i++){
        int m=digits[i]%B;
        if (m){
            ones++;
            ans+=C(bits-i-1,K-ones+1);
            if (K-ones+1==0) break;
        }
        if (m>1){
            ans+=C(bits-i-1,K-ones);
            break;
        }
    }
    if (i==bits&&ones==K) ans++;
    return ans;
}
int main(){
    cin>>X>>Y>>K>>B;
    cout<<calc(Y)-calc(X-1)<<endl;
    return 0;
}