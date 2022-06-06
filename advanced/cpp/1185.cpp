#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 30;

int n;
int din[N], dout[N], p[N];
bool st[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    char str[1010];

    int T;
    scanf("%d", &T);
    while (T -- )
    {
        scanf("%d", &n);
        memset(din, 0, sizeof din);
        memset(dout, 0, sizeof dout);
        memset(st, 0, sizeof st);
        for (int i = 0; i < 26; i ++ ) p[i] = i;

        for (int i = 0; i < n; i ++ )
        {
            scanf("%s", str);
            int len = strlen(str);
            int a = str[0] - 'a', b = str[len - 1] - 'a';
            st[a] = st[b] = true;
            dout[a] ++, din[b] ++ ;
            p[find(a)] = find(b);
        }

        int start = 0, end = 0;
        bool success = true;
        for (int i = 0; i < 26; i ++ )
            if (din[i] != dout[i])
            {
                if (din[i] == dout[i] + 1) end ++ ;
                else if (din[i] + 1 == dout[i]) start ++ ;
                else
                {
                    success = false;
                    break;
                }
            }

        if (success && !(!start && !end || start == 1 && end == 1)) success = false;

        int rep = -1;
        for (int i = 0; i < 26; i ++ )
            if (st[i])
            {
                if (rep == -1) rep = find(i);
                else if (rep != find(i))
                {
                    success = false;
                    break;
                }
            }

        if (success) puts("Ordering is possible.");
        else puts("The door cannot be opened.");
    }

    return 0;
}