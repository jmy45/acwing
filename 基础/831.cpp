/*
3
aba
5
ababa
----
0 2
*/
#include<bits/stdc++.h>
using namespace std;
const int N=100100,M=1000100;
int n,m,j;
char s[M],p[N];
int ne[N];
int main(){
    cin>>n>>p+1>>m>>s+1;
    j=0;
    for (int i=2;i<=n;i++){
        while (j&&p[j+1]!=p[i])
            j=ne[j];
        if (p[j+1]==p[i])
            j++;
        ne[i]=j;
    }
    j=0;
    for (int i=1;i<=m;i++){
        while (j&&p[j+1]!=s[i])
            j=ne[j];
        if (p[j+1]==s[i])
            j++;
        if (j==n){
            cout<<i-n<<" ";
            //j=ne[j];
        }
    }
    cout<<endl;
    return 0;
}