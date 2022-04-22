#include<cstring>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;
int g[2][4];
unordered_map<string,int> dist;
unordered_map<string,pair<char,string>> pre;
queue<string> q;
void set(string st){
    for (int i=0;i<4;i++) g[0][i]=st[i];
    for (int i=3,j=4;i>=0;i--,j++) g[1][i]=st[j];
}
string get(){
    string res;
    for (int i=0;i<4;i++) res+=g[0][i];
    for (int i=3;i>=0;i--) res+=g[1][i];
    return res;
}
string move0(string st){
    set(st);
    for (int i=0;i<4;i++) swap(g[0][i],g[1][i]);
    return get();
}
string move1(string st){
    set(st);
    char v0=g[0][3],v1=g[1][3];
    for (int i=3;i>=0;i--)
        for (int j=0;j<2;j++)
            g[j][i]=g[j][i-1];
    g[0][0]=v0,g[1][0]=v1;
    return get();
}
string move2(string st){
    set(st);
    char v=g[0][1];
    g[0][1]=g[1][1];
    g[1][1]=g[1][2];
    g[1][2]=g[0][2];
    g[0][2]=v;
    return get();
}
void bfs(string st,string ed){
    if (st==ed) return;
    q.push(st);
    dist[st]=0;
    while (q.size()){
        auto t=q.front();
        q.pop();
        string m[3];
        m[0]=move0(t);
        m[1]=move1(t);
        m[2]=move2(t);
        for (int i=0;i<3;i++){
            string str=m[i];
            if (dist.count(str)==0)
            {
                dist[str]=dist[t]+1;
                pre[str]={char(i+'A'),t};
                if (str==ed) break;
                q.push(str);
            }
        }
    }
}
int main(){
    int x;
    string st,ed;
    for (int i=0;i<8;i++){
        cin>>x;
        ed+=char(x+'0');
    }
    for (int i=0;i<8;i++) st+=char(i+'1');
    bfs(st,ed);
    cout<<dist[ed]<<endl;
    string res;
    while (ed!=st){
        res+=pre[ed].first;
        ed=pre[ed].second;
    }
    reverse(res.begin(),res.end());
    if (res.size()) cout<<res<<endl;
    return 0;
}