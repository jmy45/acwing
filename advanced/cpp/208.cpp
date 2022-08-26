#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 35;

int n;
int a[N][N];

int gauss()
{
    int r, c;
    for (r = 1, c = 1; c <= n; c ++ )
    {
        // 找主元
        int t = r;
        for (int i = r + 1; i <= n; i ++ )
            if (a[i][c])
                t = i;

        if (!a[t][c]) continue;
        // 交换
        for (int i = c; i <= n + 1; i ++ ) swap(a[t][i], a[r][i]);
        // 消
        for (int i = r + 1; i <= n; i ++ )
            for (int j = n + 1; j >= c; j -- )
                a[i][j] ^= a[i][c] & a[r][j];
        r ++ ;
    }

    int res = 1;
    if (r < n + 1)
    {
        for (int i = r; i <= n; i ++ )
        {
            if (a[i][n + 1]) return -1;  // 出现了 0 == !0，无解
            res *= 2;
        }
    }

    return res;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T -- )
    {
        memset(a, 0, sizeof a);
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i][n + 1]);
        for (int i = 1; i <= n; i ++ )
        {
            int t;
            scanf("%d", &t);
            a[i][n + 1] ^= t;
            a[i][i] = 1;
        }

        int x, y;
        while (scanf("%d%d", &x, &y), x || y) a[y][x] = 1;

        int t = gauss();
        if (t == -1) puts("Oh,it's impossible~!!");
        else printf("%d\n", t);
    }

    return 0;
}