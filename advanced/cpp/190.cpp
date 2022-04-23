#include<cstring>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;
const int N=6;
int n;
string a[N],b[N];
int extend(queue<string>&q,unordered_map<string,int>&da,unordered_map<string,int>&db,string a[],string b[]){
    string t=q.front();
    q.pop();
    for (int i=0;i<t.size();i++)
        for (int j=0;j<n;j++)
            if (t.substr(i,a[j].size())==a[j]){
                string st=t.substr(0,i)+b[j]+t.substr(i+a[j].size());
                if (db.count(st)) return da[t]+1+db[st];
                if (da.count(st)) continue;
                da[st]=da[t]+1;
                q.push(st);
            }
    return 11;
}
int bfs(string A,string B){
    queue<string> qa,qb;
    unordered_map<string,int> da,db;
    qa.push(A),da[A]=0;
    qb.push(B),db[B]=0;
    if (db.count(A)) return 0;
    while (qa.size()&&qb.size()){
        int t;
        if (qa.size()<qb.size()) t=extend(qa,da,db,a,b);
        else t=extend(qb,db,da,b,a);
        if (t<=10) return t;
    }
    return 11;
}
int main(){
    string A,B;
    cin>>A>>B;
    while (cin>>a[n]>>b[n]) n++;
    int step=bfs(A,B);
    if (step>10) puts("NO ANSWER!");
    else cout<<step<<endl;
    return 0;
}