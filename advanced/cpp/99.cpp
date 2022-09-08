#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5010;

int s[N][N];

int main()
{
    int n, R;
    scanf("%d%d", &n, &R);
    R = min(R, 5001);

    for (int i = 0; i < n; i ++ )
    {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        x ++, y ++ ;
        s[x][y] += w;
    }

    for (int i = 1; i <= 5001; i ++ )
        for (int j = 1; j <= 5001; j ++ )
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];

    int res = 0;
    for (int i = R; i <= 5001; i ++ )
        for (int j = R; j <= 5001; j ++ )
            res = max(res, s[i][j] - s[i - R][j] - s[i][j - R] + s[i - R][j - R]);

    printf("%d\n", res);

    return 0;
}