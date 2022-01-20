#include<iostream>
using namespace std;
const int N=100010;
int a[N],b[N];
int main(){
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int i=0;i<m;i++)
        cin>>b[i];
    int i=n-1,j=m-1;
    while (j>=0&&i>=0){
        if (b[j]==a[i])
            i--;
        j--;
    }
    if (i<0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}