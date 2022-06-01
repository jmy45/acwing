#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int N=2010,M=N*N;
int e[M],ne[M],h[N],idx;
int q[N],din[N],f[N];
int n,m,last;
int add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int top_sort(){
    int hh=0,tt=-1;
    for (int i=1;i<=n;i++)
        if (!din[i]) q[++tt]=i,f[i]=1;
    int ans=1;
    while (hh<=tt){
        int u=q[hh++];
        for (int i=h[u];~i;i=ne[i]){
            int j=e[i];
            f[j]=max(f[j],f[u]+(j<=n));
            ans=max(ans,f[j]);
            if (--din[j]==0) q[++tt]=j;
        }
    }
    return ans;
}
int main(){
    memset(h,-1,sizeof h);
    scanf("%d%d",&n,&m);
    last=n+1;
    while (m--){
        int x;
        scanf("%d",&x);
        vector<int> arr;
        while (x--){
            int a;
            scanf("%d",&a);
            arr.push_back(a);
        }
        vector<int> arr2;
        int j=0;
        for (int i=arr.front();i<=arr.back();i++)
            if (i==arr[j]) j++;
            else arr2.push_back(i);
        if (arr2.empty()) continue;
        for (int a:arr2) add(a,last),din[last]++;
        for (int b:arr) add(last,b),din[b]++;
        last++;
    }
    printf("%d\n",top_sort());
}