#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510;

int n = 500, m;
int g[N][N];
int ans[1100], cnt;
int d[N];

void dfs(int u)
{
    for (int i = 1; i <= n; i ++ )
        if (g[u][i])
        {
            g[u][i] --, g[i][u] -- ;
            dfs(i);
        }
    ans[ ++ cnt] = u;
}

int main()
{
    cin >> m;
    while (m -- )
    {
        int a, b;
        cin >> a >> b;
        g[a][b] ++, g[b][a] ++ ;
        d[a] ++, d[b] ++ ;
    }

    int start = 1;
    while (!d[start]) start ++ ;
    for (int i = 1; i <= n; i ++ )
        if (d[i] % 2)
        {
            start = i;
            break;
        }

    dfs(start);

    for (int i = cnt; i; i -- ) printf("%d\n", ans[i]);

    return 0;
}