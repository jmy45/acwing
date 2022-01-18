#include<iostream>
#include<unordered_set>
using namespace std;
const int N=100010;
int a[N];
int main(){
    int n;
    scanf("%d",&n);
    int ans=0,l=1;
    unordered_set<int> us;
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        while (us.count(a[i]))
            us.erase(a[l++]);
        us.insert(a[i]);
        ans=max(ans,i-l+1);
    }
    printf("%d",ans);
    return 0;
}