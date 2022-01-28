#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
int main(){
    int n,a,b;
    cin>>n;
    vector<PII> arr;
    for (int i=0;i<n;i++){
        cin>>a>>b;
        arr.emplace_back(a,b);
    }
    sort(arr.begin(),arr.end());
    int tl=-2e9,tr=-2e9,ans=0;
    for (auto [l,r]:arr){
        if (l>tr){
            if (tl!=-2e9)
                ans++;
            tl=l;
            tr=r;
        }
        else{
            if (r<=tr){
                tl=l;
                tr=r;
            }
            else{
                tl=l;
            }
        }
    }
    cout<<ans+1<<endl;
    return 0;
}