#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int,int> PII;
int main(){
    int l,r,a,b;
    cin>>l>>r;
    int n;
    cin>>n;
    vector<PII> arr;
    for (int i=0;i<n;i++){
        cin>>a>>b;
        arr.emplace_back(a,b);
    }
    sort(arr.begin(),arr.end());
    int p1=upper_bound(arr.begin(),arr.end(),l,[](int val,PII &it){return val<it.first;})-arr.begin();
    if (p1==0){
        cout<<-1<<endl;
        return 0;
    }
    int cr=-2e9;
    int p2=p1;
    --p1;
    while (p1>=0){
        cr=max(cr,arr[p1].second);
        --p1;
    }
    if (cr==-2e9){
        cout<<-1<<endl;
        return 0;  
    }
    p1=p2;
    int ans=1,tr=cr;
    while (cr<r&&p1<n){
        if (arr[p1].first<=cr){
            tr=max(tr,arr[p1].second);
            ++p1;
        }
        else{
            if (cr==tr){
                cout<<-1<<endl;
                return 0;
            }
            cr=tr;
            ans++;
        }  
    }
    if (tr>=r)
        cout<<ans+(tr!=cr)<<endl;
    else
        cout<<-1<<endl;
    return 0;
}