#include <bits/stdc++.h>
using namespace std;

#define LOCAL
#define MAXN 100000

typedef struct node
{
    char key;
    int nxt;
    bool fg;
} node;

int h1, h2, n;
node w[MAXN];

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    char tk;
    int ti, tn, cur;
    scanf("%d %d %d\n", &h1, &h2, &n);
    while (n--)
    {
        scanf("%d %c %d\n", &ti, &tk, &tn);
        w[ti].key = tk;
        w[ti].nxt = tn;
        w[ti].fg = false;
    }

    cur = h1;
    while (cur != -1)
    {
        w[cur].fg = true;
        cur = w[cur].nxt;
    }

    cur = h2;
    while (cur != -1)
    {
        if (w[cur].fg)
        {
            printf("%05d\n", cur);
            return 0;
        }
        cur = w[cur].nxt;
    }
    printf("-1\n");

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}
