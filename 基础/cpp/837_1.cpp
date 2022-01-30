#include<iostream>
using namespace std;
const int N=100010;
int parent[N],sz[N];
class UF{
public:
    int find(int i){
        return parent[i]=parent[i]==i?i:find(parent[i]);
    }
    void un(int i,int j){
        int x=find(i),y=find(j);
        if  (x!=y){
            parent[x]=y;
            sz[y]+=sz[x];
        }
    }
};
int main(){
    int n,m,a,b;
    cin>>n>>m;
    UF *uf;
    for (int i=1;i<=n;i++){
        parent[i]=i;
        sz[i]=1;
    }
    string s;
    for (int i=0;i<m;i++){
        cin>>s;
        if (s=="C"){
            cin>>a>>b;
            uf->un(a,b);
        }
        else if (s=="Q1"){
            cin>>a>>b;
            if (uf->find(a)==uf->find(b))
                cout<<"Yes"<<endl;
            else 
                cout<<"No"<<endl;
        }
        else{
            cin>>a;
            cout<<sz[uf->find(a)]<<endl;
        }
    }
    return 0;
}