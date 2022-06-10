#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int mod = 100003;

int qmi(int a, LL k)
{
    int res = 1;
    while (k)
    {
        if (k & 1) res = (LL)res * a % mod;
        a = (LL)a * a % mod;
        k >>= 1;
    }
    return res;
}

int main()
{
    int m;
    LL n;
    cin >> m >> n;

    cout << (qmi(m, n) - (LL)m * qmi(m - 1, n - 1) % mod + mod) % mod << endl;

    return 0;
}