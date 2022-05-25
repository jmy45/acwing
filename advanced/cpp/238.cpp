#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 30010;

int m;
int p[N], sz[N], d[N];

int find(int x)
{
    if (p[x] != x)
    {
        int root = find(p[x]);
        d[x] += d[p[x]];
        p[x] = root;
    }
    return p[x];
}

int main()
{
    scanf("%d", &m);

    for (int i = 1; i < N; i ++ )
    {
        p[i] = i;
        sz[i] = 1;
    }

    while (m -- )
    {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        if (op[0] == 'M')
        {
            int pa = find(a), pb = find(b);
            d[pa] = sz[pb];
            sz[pb] += sz[pa];
            p[pa] = pb;
        }
        else
        {
            int pa = find(a), pb = find(b);
            if (pa != pb) puts("-1");
            else printf("%d\n", max(0, abs(d[a] - d[b]) - 1));
        }
    }

    return 0;
}