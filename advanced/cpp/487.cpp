#include<iostream>
#include<vector>
#define v first
#define w second
using namespace std;
typedef pair<int,int> PII;
const int N=70,M=32010;
int n,m;
PII master[N];
vector<PII> sv[N];
int f[M];
int main(){
    cin>>m>>n;
    for (int i=1;i<=n;i++){
        int v,w,q;
        cin>>v>>w>>q;
        if (!q)
            master[i]={v,v*w};
        else
            sv[q].push_back({v,v*w});
    }
    for (int i=1;i<=n;i++)
        if (master[i].v){
            for (int j=m;j>=0;j--){
                for (int k=0;k<1<<sv[i].size();k++){
                    int v=master[i].v,w=master[i].w;
                    for (int u=0;u<sv[i].size();u++){
                        if (k&(1<<u)){
                            v+=sv[i][u].v;
                            w+=sv[i][u].w;
                        }
                    }
                    if (j>=v)
                        f[j]=max(f[j],f[j-v]+w);
                }
            }
        }
    cout<<f[m]<<endl;
    return 0;
}