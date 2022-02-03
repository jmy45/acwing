#include<iostream>
#include<cstring>
#include<sstream>
using namespace std;
const int N=1010;
int a[N],dp[N];
int n;
typedef bool (func) (int ,int);
int LDS(func cmp){
    int ans=0;
    for (int i=0;i<n;i++)
    {
        dp[i]=1;
        for (int j=0;j<i;j++)
            if (cmp(a[j],a[i])){
                dp[i]=max(dp[i],dp[j]+1);
            }
        ans=max(ans,dp[i]);
    }
    return ans;
}
int main(){
    int idx=0;
    string s;
    getline(cin,s);
    stringstream ss(s);
    while (ss>>s){
        a[idx++]=stoi(s);
    }
    n=idx;
    cout<<LDS([](int x,int y){return x>=y;})<<endl;
    cout<<LDS([](int x,int y){return x<y;})<<endl;
    return 0;
}