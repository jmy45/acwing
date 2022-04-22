#include<iostream>
using namespace std;
int q[200010];
bool st[200010];
int main(){
    int n,k;
    cin>>n>>k;
    if (n==k){
        cout<<0<<endl;
        return 0;
    }
    int hh=0,tt=0;
    q[0]=n;
    st[n]=true;
    int ans=0;
    while (hh<=tt){
        int l=tt-hh+1;
        ans++;
        for (int i=0;i<l;i++){
            int c=q[hh++];
            if (c-1==k||c+1==k||c*2==k) {
                cout<<ans<<endl;
                return 0;
            };
            if (c-1>0&&!st[c-1]) {
                q[++tt]=c-1;
                st[c-1]=true;
            }
            if (c+1<=2*k&&!st[c+1]) {
                q[++tt]=c+1;
                st[c+1]=true;
            }
            if (c*2<=2*k&&!st[c*2]) {
                q[++tt]=c*2;
                st[c*2]=true;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}