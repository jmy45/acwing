#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N=31;
int K,B;
int f[N][N];
void init(){
    for (int i=0;i<N;i++)
        for (int j=0;j<=i;j++)
            if (!j) f[i][j]=1;
            else f[i][j]=f[i-1][j-1]+f[i-1][j];
}
int dp(int n){
    if (!n) return 0;
    vector<int> nums;
    while (n) nums.push_back(n%B),n/=B;
    int res=0,last=0;
    for (int i=nums.size()-1;i>=0;i--){
        int x=nums[i];
        if (x){
            res+=f[i][K-last];
            if (x>1){
                if (K-last-1>=0) res+=f[i][K-last-1];
                break;
            }
            else {
                last++;
                if (last>K) break;
            }
        }
        if (!i&&last==K) res++;
    }
    return res;
}
int main(){
    init();
    int l,r;
    cin>>l>>r>>K>>B;
    cout<<dp(r)-dp(l-1)<<endl;
    return 0;
}