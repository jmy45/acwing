#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e7 + 10;

int primes[N], cnt;
bool st[N];
int phi[N];
LL s[N];

void init(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i])
        {
            primes[cnt ++ ] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] * i <= n; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
            {
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            }
            phi[i * primes[j]] = phi[i] * (primes[j] - 1);
        }
    }

    for (int i = 1; i <= n; i ++ ) s[i] = s[i - 1] + phi[i];
}

int main()
{
    int n;
    cin >> n;
    init(n);

    LL res = 0;
    for (int i = 0; i < cnt; i ++ )
    {
        int p = primes[i];
        res += s[n / p] * 2 + 1;
    }

    cout << res << endl;

    return 0;
}