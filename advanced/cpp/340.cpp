#include<cstring>
#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
const int N=1010,M=20010;
int n,m,k;
int h[N],e[M],w[M],ne[M],idx;
deque<int> q;
int dist[N];
int st[N];
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
bool check(int bound){
    memset(dist,0x3f,sizeof dist);
    memset(st,0,sizeof st);
    dist[1]=0;
    q.push_back(1);
    while (q.size()){
        int t=q.front();
        q.pop_front();
        if (st[t]) continue;
        st[t]=true;
        for (int i=h[t];~i;i=ne[i]){
            int j=e[i],v=w[i]>bound;
            if (dist[j]>dist[t]+v){
                dist[j]=dist[t]+v;
                if (!v) q.push_front(j);
                else q.push_back(j);
            }
        }
    }
    return dist[n]<=k;
}
int main(){
    cin>>n>>m>>k;
    memset(h,-1,sizeof h);
    while (m--){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);
    }
    int l=0,r=1e6+1;
    while (l<r){
        int md=l+r>>1;
        if (check(md)) r=md;
        else l=md+1;
    }
    if (r==1e6+1) r=-1;
    cout<<r<<endl;
    return 0;
}