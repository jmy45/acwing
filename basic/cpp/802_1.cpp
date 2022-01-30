#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
int main(){
    int n,m,x,c,l,r;
    cin>>n>>m;
    vector<PII> a;
    for (int i=0;i<n;i++){
        cin>>x>>c;
        a.emplace_back(x,c);
    }
    sort(a.begin(),a.end());
    vector<int> pre(n+1);
    for (int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i-1].second;
    }
    for (int i=0;i<m;i++){
        cin>>l>>r;
        int p2=upper_bound(a.begin(),a.end(),r,[](int val,PII& it){return it.first>val;})-a.begin();
        if (p2==0){
            cout<<0<<endl;
        }
        else{
            int p1=lower_bound(a.begin(),a.end(),l,[](PII& it,int val){return it.first<val;})-a.begin();
            cout<<pre[p2]-pre[p1]<<endl;
        }
    }
    return 0;
}