#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=26;
int n,m;
bool d[N][N];
bool st[N];
int check(){
    for (int i=0;i<n;i++)
        if (d[i][i])
            return 2;
    for (int i=0;i<n;i++)
        for (int j=0;j<i;j++)
            if (!d[i][j]&&!d[j][i])
                return 0;
    return 1;
}
char get_min(){
    for (int i=0;i<n;i++)
        if (!st[i]){
            bool flag=true;
            for (int j=0;j<n;j++)
                if (!st[j]&&d[j][i]){
                    flag=false;
                    break;
                }
            if (flag){
                st[i]=true;
                return 'A'+i;
            }
        }
}
int main(){
    while (cin>>n>>m,n||m){
        memset(d,0,sizeof d);
        int type=0,t;
        for (int i=1;i<=m;i++){
            char str[5];
            cin>>str;
            int a=str[0]-'A',b=str[2]-'A';
            if (!type){
                d[a][b]=1;
                for (int x=0;x<n;x++){
                    if (d[x][a]) d[x][b]=1;
                    if (d[b][x]) d[a][x]=1;
                    for (int y=0;y<n;y++)
                        if (d[x][a]&&d[b][y])
                            d[x][y]=1;
                }
                type=check();
                if (type) t=i;
            }
        }
        if (!type) puts("Sorted sequence cannot be determined.");
        else if (type==2) printf("Inconsistency found after %d relations.\n",t);
        else {
            memset(st,0,sizeof st);
            printf("Sorted sequence determined after %d relations: ",t);
            for (int i=0;i<n;i++) printf("%c",get_min());
            printf(".\n");
        }
    }
    return 0;
}