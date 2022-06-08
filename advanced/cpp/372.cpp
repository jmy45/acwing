//转换为二分图的最大匹配
#include <cstring>
#include <iostream>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 110;

int n, m;
PII match[N][N];
bool g[N][N], st[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

bool find(int x, int y)
{
    for (int i = 0; i < 4; i ++ )
    {
        int a = x + dx[i], b = y + dy[i];
        if (a && a <= n && b && b <= n && !g[a][b] && !st[a][b])
        {
            st[a][b] = true;
            PII t = match[a][b];
            if (t.x == -1 || find(t.x, t.y))
            {
                match[a][b] = {x, y};
                return true;
            }
        }
    }

    return false;
}

int main()
{
    cin >> n >> m;

    while (m -- )
    {
        int x, y;
        cin >> x >> y;
        g[x][y] = true;
    }

    memset(match, -1, sizeof match);

    int res = 0;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            if ((i + j) % 2 && !g[i][j])
            {
                memset(st, 0, sizeof st);
                if (find(i, j)) res ++ ;
            }

    cout << res << endl;

    return 0;
}