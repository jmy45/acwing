#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int> arr;
void print(){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++)
            if (j!=arr[i]) cout<<".";
            else cout<<"Q";
        cout<<endl;
    }
    cout<<endl;
}
void dfs(int idx){
    if (idx==n){
        print();
        return;
    }
    for (int j=0;j<n;j++){
        bool f=true;
        arr[idx]=j;
        for (int i=0;i<idx;i++)
            if ((arr[i]==j)||(abs(arr[i]-j)==idx-i)){
                f=false;
                break;
            }
        if (f){
            dfs(idx+1);
        }
    }
}
int main(){
    cin>>n;
    arr.assign(n,-1);
    dfs(0);
}