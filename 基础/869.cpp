#include<iostream>
#include<set>
using namespace std;
void get_divisors(int x){
    set<int> us;
    for (int i=1;i<=x/i;i++)
        if (i*i==x)
            us.insert(i);
        else if (x%i==0)
            us.insert({i,x/i});
    for (int e:us)
        cout<<e<<" ";
    cout<<endl;    
}
int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        get_divisors(a);
    }
    return 0;
}