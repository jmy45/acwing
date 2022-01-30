#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
const int N=100010;
int n;
struct Range{
    int l,r;
    bool operator< (const Range &w)const{
        return r<w.r;
    }
}range[N];
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        range[i]={l,r};
    }
    sort(range,range+n);
    multiset<int> s;
    for (int i=0;i<n;i++){
        auto it=s.lower_bound(range[i].l);
        if (it!=s.begin())
            s.erase(--it);
        s.insert(range[i].r);
    }
    printf("%d",s.size());
    return 0;
}