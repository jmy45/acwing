#include<iostream>
#include<set>
using namespace std;
typedef long long LL;
LL ans;
int main(){
    int n;
    scanf("%d",&n);
    int x;
    set<int> s;
    for (int i=0;i<n;i++){
        scanf("%d",&x);
        if (!i) ans+=x;
        else{
            int t=0x3f3f3f3f;
            auto it=s.lower_bound(x);
            if (it!=s.end())
                t=min(t,*it-x);
            it=s.upper_bound(x);
            if (it!=s.begin())
                t=min(t,x-*--it);
            ans+=t;
        }
        s.insert(x);
    }
    printf("%lld",ans);
    return 0;
}