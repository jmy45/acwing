#include<iostream>
using namespace std;
const int N=17;
int p[N],ans;
int main(){
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=m;i++)
        cin>>p[i];
    for (int i=1;i<1<<m;i++){
        int t=n,c=0;
        for (int j=0;j<m;j++)
            if (i>>j&1){
                c++;
                t/=p[j+1];
                if (t==0)
                    break;
            }
        ans+=c%2?t:-t;
    }
    cout<<ans<<endl;
    return 0;
}