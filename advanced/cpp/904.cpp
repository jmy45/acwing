#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=510,M=5210;
int n,m1,m2;
int h[N],e[M],w[M],ne[M],idx;
int dist[N];
int q[N],cnt[N];
bool st[N];
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
bool spfa(){
    int hh=0,tt=0;
    memset(dist,0,sizeof dist);
    memset(st,0,sizeof st);
    memset(cnt,0,sizeof cnt);
    for (int i=1;i<=n;i++){
        q[tt++]=i;
        st[i]=true;
    }
    while (hh!=tt){
        int t=q[hh++];
        if (hh==N) hh=0;
        st[t]=false;
        for (int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if (dist[j]>dist[t]+w[i]){
                dist[j]=dist[t]+w[i];
                cnt[j]=cnt[t]+1;
                if (cnt[j]>=n) return true;
                if (!st[j]){
                    q[tt++]=j;
                    if (tt==N) tt=0;
                    st[j]=true;
                }
            }
        }
    }
    return false;
}
int main(){
    int T;
    cin>>T;
    while (T--){
        cin>>n>>m1>>m2;
        memset(h,-1,sizeof h);
        idx=0;
        while (m1--){
            int a,b,c;
            cin>>a>>b>>c;
            add(a,b,c),add(b,a,c);
        }
        while (m2--){
            int a,b,c;
            cin>>a>>b>>c;
            add(a,b,-c);
        }
        if (spfa()) puts("YES");
        else puts("NO");
    }
    return 0;
}