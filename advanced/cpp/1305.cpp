#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 25;

int n, m, mod;
char str[N];
int ne[N];
int a[N][N];

void mul(int c[][N], int a[][N], int b[][N])  // c = a * b
{
    static int t[N][N];
    memset(t, 0, sizeof t);

    for (int i = 0; i < m; i ++ )
        for (int j = 0; j < m; j ++ )
            for (int k = 0; k < m; k ++ )
                t[i][j] = (t[i][j] + a[i][k] * b[k][j]) % mod;

    memcpy(c, t, sizeof t);
}

int qmi(int k)
{
    int f0[N][N] = {1};
    while (k)
    {
        if (k & 1) mul(f0, f0, a);  // f0 = f0 * a
        mul(a, a, a);  // a = a * a
        k >>= 1;
    }

    int res = 0;
    for (int i = 0; i < m; i ++ ) res = (res + f0[0][i]) % mod;
    return res;
}

int main()
{
    cin >> n >> m >> mod;
    cin >> str + 1;

    // kmp
    for (int i = 2, j = 0; i <= m; i ++ )
    {
        while (j && str[j + 1] != str[i]) j = ne[j];
        if (str[j + 1] == str[i]) j ++ ;
        ne[i] = j;
    }

    // 初始化A[i][j]
    for (int j = 0; j < m; j ++ )
        for (int c = '0'; c <= '9'; c ++ )
        {
            int k = j;
            while (k && str[k + 1] != c) k = ne[k];
            if (str[k + 1] == c) k ++ ;
            if (k < m) a[j][k] ++ ;
        }


    // F[n] = F[0] * A^n
    cout << qmi(n) << endl;

    return 0;
}