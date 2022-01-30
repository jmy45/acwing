#include<iostream>
#include<cstring>
using namespace std;
const int N=100010;
int stk[N],tt;
int main(){
    int m;
    scanf("%d",&m);
    while (m--){
        int x;
        char op[10];
        scanf("%s",op);
        if (!strcmp(op,"push")){
            scanf("%d",&x);
            stk[++tt]=x;
        }
        else if (!strcmp(op,"pop"))
            tt--;
        else if (!strcmp(op,"empty"))
            cout<<(tt>0?"NO":"YES")<<endl;
        else 
            cout<<stk[tt]<<endl;
    }
    return 0;
}