#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

LL C(int n)
{
    return (LL)n * (n - 1) * (n - 2) / 6;
}

int main()
{
    int n, m;
    cin >> n >> m;

    n ++, m ++ ;

    LL res = C(n * m) - (LL)n * C(m) - (LL)m * C(n);
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            res -= 2ll * (gcd(i, j) - 1) * (n - i) * (m - j);

    cout << res << endl;

    return 0;
}