//计算二进制中1的个数
#include<iostream>
using namespace std;
int count(int x){
    int ans=0;
    while (x){
        ans++;
        x&=x-1;
    }
    return ans;
}
int main(){
    int n,x;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>x;
        cout<<count(x)<<" ";
    }
    cout<<endl;
    return 0;
}