#include<iostream>
using namespace std;
const int N=100010;
const int base=29;
int n,m,a,b,c,d;
unsigned long long h[N],p[N];
int main(){
    cin>>n>>m;
    string s;
    cin>>s;
    p[0]=1;
    for (int i=1;i<=n;i++){
        h[i]=h[i-1]*base+s[i-1];
        p[i]=p[i-1]*base;
    }
    for (int i=0;i<m;i++){
        cin>>a>>b>>c>>d;
        if ((h[b]-h[a-1]*p[b-a+1])==(h[d]-h[c-1]*p[d-c+1]))
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}