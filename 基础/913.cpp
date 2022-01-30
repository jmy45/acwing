#include<iostream>
#include<algorithm>
using namespace std;
const int N=100010;
int a[N];
int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    long long ans=0;
    for (int i=0;i<n;i++)
        ans+=(n-i-1)*a[i];
    cout<<ans<<endl;
    return 0;
}