#include<iostream>
#include<cstring>
using namespace std;
const int N=100010;
int q[N],hh,tt=-1;
int main(){
    int m;
    scanf("%d",&m);
    while (m--){
        int x;
        char op[10];
        scanf("%s",op);
        if (!strcmp(op,"push")){
            scanf("%d",&x);
            q[++tt]=x;
        }
        else if (!strcmp(op,"pop"))
            hh++;
        else if (!strcmp(op,"empty"))
            cout<<(hh<=tt?"NO":"YES")<<endl;
        else 
            cout<<q[hh]<<endl;
    }
    return 0;
}