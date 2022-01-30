#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,j,k;
    cin>>n;
    vector<int> a;
    for (int i=1;i<=n;i++)
        a.push_back(i);
    int sz=a.size();
    while (1){
        for (int i=0;i<sz;i++)
            cout<<a[i]<<" ";
        cout<<endl;
        j=sz-2;
        while (j>=0&&a[j]>a[j+1])
            j--;
        if (j==-1) break;
        k=sz-1;
        while (a[k]<a[j])
            k--;
        swap(a[j],a[k]);
        reverse(a.begin()+j+1,a.end());
    }
    return 0;
}