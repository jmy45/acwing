#include<iostream>
#include<cstring>
using namespace std;
const int N=20;
int ans;
char words[N][N];
int g[N],n;
void dfs(int c,int len){
    if (len>ans) ans=len;
    g[c]++;
    int l=strlen(words[c]);
    for (int i=1;i<l;i++)
        for (int j=0;j<n;j++)
            if (g[j]<2){
                int k=0;
                for (;k<i;k++)
                    if (words[j][k]!=words[c][l-i+k]) break;
                if (k==i) dfs(j,len+strlen(words[j])-i);
            }
    g[c]--;
}
int main(){
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>words[i];
    char ch;
    cin>>ch;
    for (int i=0;i<n;i++)
        if (words[i][0]==ch)
            dfs(i,strlen(words[i]));
    cout<<ans<<endl;
}