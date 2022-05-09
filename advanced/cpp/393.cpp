#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=30,M=100;
int n;
int h[N],e[M],w[M],ne[M],idx;
int r[N],num[N];
int dist[N];
int q[N],cnt[N];
bool st[N];
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
void build(int s24){
    memset(h,-1,sizeof h);
    idx=0;
    for (int i=1;i<=24;i++){
        add(i-1,i,0);
        add(i,i-1,-num[i]);
    }
    for (int i=8;i<=24;i++) add(i-8,i,r[i]);
    for (int i=1;i<=7;i++) add(i+16,i,-s24+r[i]);
    add(0,24,s24),add(24,0,-s24);
}
bool spfa(int s24){
    build(s24);
    memset(dist,-0x3f,sizeof dist);
    memset(cnt,0,sizeof cnt);
    memset(st,0,sizeof st);
    dist[0]=0;
    int hh=0,tt=1;
    q[0]=0;
    st[0]=true;
    while (hh!=tt){
        int t=q[hh++];
        if (hh==N) hh=0;
        st[t]=false;
        for (int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if (dist[j]<dist[t]+w[i]){
                dist[j]=dist[t]+w[i];
                cnt[j]=cnt[t]+1;
                if (cnt[j]>=25) return false;
                if (!st[j]){
                    q[tt++]=j;
                    if (tt==N) tt=0;
                    st[j]=true;
                }
            }
        }
    }
    return true;
}
int main(){
    int T;
    cin>>T;
    while (T--){
        for (int i=1;i<=24;i++) cin>>r[i];
        cin>>n;
        memset(num,0,sizeof num);
        for (int i=0;i<n;i++){
            int t;
            cin>>t;
            num[t+1]++;
        }
        bool suc=false;
        for (int i=0;i<=1000;i++)
            if (spfa(i)){
                cout<<i<<endl;
                suc=true;
                break;
            }
        if (!suc) puts("No Solution");
    }
    return 0;
}