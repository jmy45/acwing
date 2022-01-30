#include<iostream>
#include<algorithm>
using namespace std;
const int N=100010;
struct Range{
    int l,r;
    bool operator<(const Range&W)const{
        return l<W.l;
    }
}range[N];
int main(){
    int n,a,b;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a>>b;
        range[i]={a,b};
    }
    sort(range,range+n);
    int ans=0;
    for (int i=0;i<n;i++){
        int j=i,cr=range[i].r;
        while (j<n&&range[j].l<=cr){
            cr=min(cr,range[j].r);
            j++;
        }
        ans++;
        i=j-1;
    }
    cout<<ans<<endl;
    return 0;
}