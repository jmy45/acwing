#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;
typedef pair<vector<int>,string> PII;
vector<int> t,s;
queue<PII> q;
vector<int> operateA(vector<int>& c){
    vector<int> d={c[7],c[6],c[5],c[4],c[3],c[2],c[1],c[0]};
    return d;
}
vector<int> operateB(vector<int>& c){
    vector<int> d={c[3],c[0],c[1],c[2],c[5],c[6],c[7],c[4]};
    return d;
}
vector<int> operateC(vector<int>&c){
    vector<int> d={c[0],c[6],c[1],c[3],c[4],c[2],c[5],c[7]};
    return d;
}
int main(){
    int x;
    for (int i=0;i<8;i++){
        cin>>x;
        t.push_back(x);
        s.push_back(i+1);
    }
    if (t==s){cout<<0<<endl;return 0;}
    q.emplace(s,"");
    auto hfunc=[](vector<int> v)->size_t{
        static hash<int> h;
        int x=0;
        for (auto &e:v)
            x=x*10+e;
        return h(x);
    };
    unordered_set<vector<int>,decltype(hfunc)> us(0,hfunc);
    us.insert(s);
    int ans=0;
    while (q.size()){
        int l=q.size();
        ans++;
        for (int i=0;i<l;i++){
            auto [c,str]=q.front();
            q.pop();
            if (c==t){
                cout<<ans-1<<endl;
                cout<<str<<endl;
                return 0;
            }
            auto d=operateA(c);
            if (us.find(d)==us.end()){
                us.insert(d);
                q.emplace(d,str+"A");
            }
            d=operateB(c);
            if (us.find(d)==us.end()){
                us.insert(d);
                q.emplace(d,str+"B");
            }
            d=operateC(c);
            if (us.find(d)==us.end()){
                us.insert(d);
                q.emplace(d,str+"C");
            }
        }
    }
    return 0;
}