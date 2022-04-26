#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=64;
int a[N];
int sum,n;
int groups,len;
bool st[N];
bool dfs(int start,int val,int gc){
    if (gc==groups) return true;
    if (val==len)
        return dfs(0,0,gc+1);
    for (int i=start;i<n;i++){
        if (!st[i]&&val+a[i]<=len){
            st[i]=true;
            if (dfs(i+1,val+a[i],gc))
                return true;
            st[i]=false;
            if (val+a[i]==len)
                return false;
            if (val==0)
                return false;
            while (i+1<n&&a[i]==a[i+1])
                i++;
        }
    }
    return false;
}
int main(){
    while (cin>>n,n){
        sum=0;
        int t=1;
        memset(st,false,sizeof(st));
        for (int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
            t=max(t,a[i]);
        }
        sort(a,a+n);
        reverse(a,a+n);
        int b[N],idx=0;
        for (int i=1;i*i<=sum;i++)
            if (sum%i==0){
                b[idx++]=i;
                if (i*i!=sum)
                    b[idx++]=sum/i;
            }
        sort(b,b+idx);
        for (int i=0;i<idx;i++)
            if (b[i]>=t){
                groups=sum/b[i];
                len=b[i];
                if (dfs(0,0,0)){
                    cout<<b[i]<<endl;
                    break;
                }
            }
    }
    return 0;
}