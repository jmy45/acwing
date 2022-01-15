#include<iostream>
#include<math.h>
using namespace std;
bool isPrime(int x){
    if (x==1) return false;
    for (int i=2;i<=x/i;i++)
        if (x%i==0)
            return false;
    return true;
}
int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        if (isPrime(a))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}