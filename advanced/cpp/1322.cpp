#include <cstdio>

using namespace std;

const int N = 1010;

int n;
int a[N];
int l[N][N], r[N][N];

int main()
{
    int T;
    scanf("%d", &T);
    while (T -- )
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);

        for (int len = 1; len <= n; len ++ )
            for (int i = 1; i + len - 1 <= n; i ++ )
            {
                int j = i + len - 1;
                if (len == 1) l[i][j] = r[i][j] = a[i];
                else
                {
                    int L = l[i][j - 1], R = r[i][j - 1], X = a[j];
                    if (R == X) l[i][j] = 0;
                    else if (X < L && X < R || X > L && X > R) l[i][j] = X;
                    else if (L > R) l[i][j] = X - 1;
                    else l[i][j] = X + 1;

                    L = l[i + 1][j], R = r[i + 1][j], X = a[i];
                    if (L == X) r[i][j] = 0;
                    else if (X < L && X < R || X > L && X > R) r[i][j] = X;
                    else if (R > L) r[i][j] = X - 1;
                    else r[i][j] = X + 1;
                }
            }

        if (n == 1) puts("1");
        else printf("%d\n", l[2][n] != a[1]);
    }

    return 0;
}