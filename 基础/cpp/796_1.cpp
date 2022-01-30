#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>> a(n,vector<int>(m));
    vector<vector<int>> pre(n+1,vector<int>(m+1));
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin>>a[i][j];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+a[i-1][j-1];
    int x1,y1,x2,y2;
    for (int i=0;i<q;i++){
        cin>>x1>>y1>>x2>>y2;
        int ret=pre[x2][y2]-pre[x1-1][y2]-pre[x2][y1-1]+pre[x1-1][y1-1];
        cout<<ret<<endl;
    }
    return 0;
}