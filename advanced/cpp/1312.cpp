#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int p = 1000003;

int qmi(int a, int k)
{
    int res = 1;
    while (k)
    {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}

int C(int a, int b)
{
    if (a < b) return 0;

    int down = 1, up = 1;
    for (int i = a, j = 1; j <= b; i --, j ++ )
    {
        up = (LL)up * i % p;
        down = (LL)down * j % p;
    }

    return (LL)up * qmi(down, p - 2) % p;
}

int Lucas(int a, int b)
{
    if (a < p && b < p) return C(a, b);
    return (LL)Lucas(a / p, b / p) * C(a % p, b % p) % p;
}

int main()
{
    int T;
    cin >> T;
    while (T -- )
    {
        int n, l, r;
        cin >> n >> l >> r;
        cout << (Lucas(r - l + n + 1, r - l + 1) + p - 1) % p << endl;
    }

    return 0;
}