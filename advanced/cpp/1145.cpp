#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#define x first
#define y second
using namespace std;
typedef pair<int,int> PII;
const int N=510,M=N*N/2;
int n,k,m;
struct Edge{
    int a,b;
    double w;
    bool operator <(const Edge&t) const{
        return w<t.w;
    }
}e[M];
PII q[M];
int p[N];
double get_dist(PII a,PII b){
    int dx=a.x-b.x,dy=a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}
int find(int x){
    if (p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
int main(){
    cin>>n>>k;
    for (int i=0;i<n;i++) cin>>q[i].x>>q[i].y;
    for (int i=0;i<n;i++)
        for (int j=0;j<i;j++)
            e[m++]={i,j,get_dist(q[i],q[j])};
    sort(e,e+m);
    for (int i=0;i<n;i++) p[i]=i;
    int cnt=n;
    double res=0;
    for (int i=0;i<m;i++){
        if (cnt<=k) break;
        int a=find(e[i].a),b=find(e[i].b);
        double w=e[i].w;
        if (a!=b){
            p[a]=b;
            cnt--;
            res=w;
        }
    }
    printf("%.2lf\n",res);
    return 0;
}