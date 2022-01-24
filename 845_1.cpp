#include<iostream>
#include<queue>
#include<unordered_set>
using namespace std;
int dx[]={-1,0,0,1},dy[]={0,-1,1,0};
bool check(string &s){
    for (int i=0;i<8;i++)
        if (s[i]-'0'!=i+1)
            return false;
    return s[8]=='x';
}
int main(){
    string s;
    char ch;
    for (int i=0;i<9;i++){
        cin>>ch;
        s+=ch;
    }
    int step=0;
    if (check(s))
        return step;
    queue<string>q;
    q.push(s);
    unordered_set<string> us;
    us.insert(s);
    while (!q.empty()){
        int l=q.size();
        step++;
        for (int i=0;i<l;i++){
            string cur=q.front();
            q.pop();
            int j=0;
            for (;j<9;j++)
                if (cur[j]=='x')
                    break;
            int x=j/3,y=j%3;
            for (int k=0;k<4;k++){
                int nx=x+dx[k],ny=y+dy[k];
                if (nx>=0&&nx<3&&ny>=0&&ny<3){
                    swap(cur[j],cur[nx*3+ny]);
                    if (!us.count(cur)){
                        us.insert(cur);
                        if (check(cur)){
                            cout<<step<<endl;
                            return 0;
                        }
                        q.push(cur);
                    }
                    swap(cur[j],cur[nx*3+ny]);
                }
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}