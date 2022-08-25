#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, mod = 5000011;

int n, k;
int f[N], s[N];

int main()
{
    cin >> n >> k;

    f[0] = s[0] = 1;
    for (int i = 1; i <= n; i ++ )
    {
        f[i] = s[max(i - k - 1, 0)];
        s[i] = (s[i - 1] + f[i]) % mod;
    }

    cout << s[n] << endl;

    return 0;
}