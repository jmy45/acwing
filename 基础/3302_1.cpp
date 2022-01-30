#include<iostream>
using namespace std;
const int N=10000;
int stk[N],tt,tt2;
char op[N];
bool cmp(char a,char b){
    if (a==')') {
        if (b=='(') return false;
        return true;
    }
    if (a=='+'||a=='-'){
        if (b=='(') return false;
        return true;
    }
    if (a=='*'||a=='/'){
        if (b=='*'||b=='/') return true;
    }
    return false;
}
int main(){
    string s;
    cin>>s;
    s+=')';
    bool lch=false;
    for (char&ch:s){
        if (isdigit(ch)){
            if (lch)
                stk[tt]=stk[tt]*10+ch-'0';
            else
                stk[++tt]=ch-'0';
            lch=true;
        }
        else{
            lch=false;
            while (tt2&&cmp(ch,op[tt2])){
                switch(op[tt2]){
                    case '+':{
                        int t=stk[tt-1]+stk[tt];
                        stk[--tt]=t;
                        break;
                    }
                    case '-':{
                        int t=stk[tt-1]-stk[tt];
                        stk[--tt]=t;
                        break;
                    }
                    case '*':{
                        int t=stk[tt-1]*stk[tt];
                        stk[--tt]=t;
                        break;
                    }
                    default:{
                        int t=stk[tt-1]/stk[tt];
                        stk[--tt]=t;
                    }
                }
                tt2--;
            }
            if (ch==')')
                tt2--;
            else
                op[++tt2]=ch;
            
        }  
    }
    cout<<stk[tt]<<endl;
    return 0;
}