#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 100
#define BLACK 0
#define RED 1

typedef struct node
{
    int key, color;
    node *lc, *rc;
    node(int k, int c, node *l = NULL, node *r = NULL): key(k), color(c), lc(l), rc(r) {}
} node;

int k, n, m, black;
int pres[MAXN];

node* build(int *ps, int lw, int hi)
{
    if (hi - lw < 1)
        return NULL;
    if (hi - lw == 1)
        return new node(abs(ps[lw]), ps[lw] > 0? BLACK : RED);
    int m = lw + 1;
    while (m < hi && abs(ps[m]) <= abs(ps[lw]))
        m++;
    node *r = new node(abs(ps[lw]), ps[lw] > 0? BLACK : RED);
    r->lc = build(ps, lw + 1, m);
    r->rc = build(ps, m, hi);
    return r;
}

int dfs(node *r)
{
    if (r == NULL)
        return 0;
    if (r->color == RED)
    {
        if (r->lc && r->lc->color == RED)
            return -1;
        if (r->rc && r->rc->color == RED)
            return -1;
    }
    int ln = dfs(r->lc);
    int rn = dfs(r->rc);
    if (ln != -1 && rn!= -1 && ln == rn)
        return r->color == BLACK? ln + 1 : ln;
    else
        return -1;
}

bool judge(node *tree)
{
    return dfs(tree) != -1;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d", &k);
    REP(i, 0, k)
    {
        scanf("%d", &n);
        REP(j, 0, n)
            scanf("%d", &pres[j]);
        if (pres[0] < 0)
        {
            printf("No\n");
            continue;
        }
        node *tree = build(pres, 0, n);
        if (judge(tree))
            printf("Yes\n");
        else
            printf("No\n");
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}
