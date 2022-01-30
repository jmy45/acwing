#include<iostream>
#include<set>
#include<unordered_map>
using namespace std;
const int N=100010;
int a[N],p[N],n,idx=1;
long long ans;
int lowbit(int x){
    return x&-x;
}
int update(int x){
    for (int i=x;i<n;i+=lowbit(i))
        p[i]++;
}
int query(int x){
    int ret=0;
    for (int i=x;i;i-=lowbit(i))
        ret+=p[i];
    return ret;
}
int main(){
    scanf("%d",&n);
    set<int> us;
    unordered_map<int,int> m;
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
        us.insert(a[i]);
    }
    for (int e:us)
        m[e]=idx++;
    for (int i=n-1;i>=0;i--){
        int x=m[a[i]];
        ans+=query(x-1);
        update(x);
    }
    printf("%lld",ans);
    return 0;
}