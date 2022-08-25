#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int primes[N], cnt;
bool st[N];
int a[N], b[N];

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

int get(int n, int p)
{
    int s = 0;
    while (n) s += n / p, n /= p;
    return s;
}

void mul(int r[], int &len, int x)
{
    int t = 0;
    for (int i = 0; i < len; i ++ )
    {
        t += r[i] * x;
        r[i] = t % 10;
        t /= 10;
    }
    while (t)
    {
        r[len ++ ] = t % 10;
        t /= 10;
    }
}

void sub(int a[], int al, int b[], int bl)
{
    for (int i = 0, t = 0; i < al; i ++ )
    {
        a[i] -= t + b[i];
        if (a[i] < 0) a[i] += 10, t = 1;
        else t = 0;
    }
}

int C(int x, int y, int r[N])
{
    int len = 1;
    r[0] = 1;

    for (int i = 0; i < cnt; i ++ )
    {
        int p = primes[i];
        int s = get(x, p) - get(y, p) - get(x - y, p);
        while (s -- ) mul(r, len, p);
    }

    return len;
}

int main()
{
    init(N - 1);

    int n, m;
    cin >> n >> m;
    int al = C(n + m, m, a);
    int bl = C(n + m, n + 1, b);

    sub(a, al, b, bl);

    int k = al - 1;
    while (!a[k] && k > 0) k -- ;
    while (k >= 0) printf("%d", a[k -- ]);

    return 0;
}