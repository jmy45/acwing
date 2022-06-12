#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 50010;

int primes[N], cnt;
bool st[N];
struct Factor
{
    int p, s;
}factor[10];
int fcnt;

int dividor[1601], dcnt;

void init(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] * i <= n; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

void dfs(int u, int p)
{
    if (u == fcnt)
    {
        dividor[dcnt ++ ] = p;
        return;
    }

    for (int i = 0; i <= factor[u].s; i ++ )
    {
        dfs(u + 1, p);
        p *= factor[u].p;
    }
}

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    init(N - 1);

    int n;
    cin >> n;
    while (n -- )
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        fcnt = 0;
        int t = d;
        for (int i = 0; primes[i] <= t / primes[i]; i ++ )
        {
            int p = primes[i];
            if (t % p == 0)
            {
                int s = 0;
                while (t % p == 0) t /= p, s ++ ;
                factor[fcnt ++ ] = {p, s};
            }
        }

        if (t > 1) factor[fcnt ++ ] = {t, 1};

        dcnt = 0;
        dfs(0, 1);

        int res = 0;
        for (int i = 0; i < dcnt; i ++ )
        {
            int x = dividor[i];
            if (gcd(a, x) == b && (LL)c * x / gcd(c, x) == d) res ++ ;
        }

        cout << res << endl;
    }

    return 0;
}