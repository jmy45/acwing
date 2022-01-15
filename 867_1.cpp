//分解质因数
#include<iostream>
#include<math.h>
using namespace std;
void prime(int x){
    int j=sqrt(x);
    for (int i=2;x!=1&&i<=j;i++){
        int y=0;
        while (x%i==0) {
            x/=i;
            y++;
        }
        if (y)
            cout<<i<<" "<<y<<endl;
    }
    if (x!=1)
        cout<<x<<" "<<1<<endl;
}
int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        prime(a);
        cout<<endl;
    }
    return 0;
}